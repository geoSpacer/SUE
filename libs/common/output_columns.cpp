#include "pragmas.h"

#include "output_columns.h"
#include "trim_whitespace.h"

//-----------------------------------------------------------------------------

void write_titles(std::ofstream &		       file,
		  const std::vector<Column_or_Group> & columns,
		  bool				       initial_GT_sign)
{
    Multi_Line_Text titles = combine_titles(columns);

    for (int i = 0; i < titles.line_count(); i++)
	if (initial_GT_sign)
	    file << ">" << titles[i].substr(1) << "\n";
	else
	    file << titles[i] << "\n";
}

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    const Output_Column * first_column(const Column_Group * group)
	//  Determine the first column in a group.
    {
	if (! group || group->members().size() == 0)
	    return 0;

	const Output_Column * column = group->members()[0].column();
	if (column)
	    return column;
	else
	    return first_column(group->members()[0].group());
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text titles(const std::vector<Column_or_Group> & cols);
	//  Forward reference.

    //-------------------------------------------------------------------------

    Multi_Line_Text title(const Column_or_Group & col_or_grp)
	//  Construct the title for an output column or a group of columns.
	//  All the lines in the title are the same length (short lines are
	//  padded at the end with spaces).
    {
	std::vector<std::string> lines;

	const Output_Column * column = col_or_grp.column();
	if (column) {
	    lines = column->title();
	    for (unsigned int i = 0; i < lines.size(); i++)
		lines[i] = column->spacing_str() + lines[i]
			   + std::string(column->width() - lines[i].size(),
					 ' ');
	}
	else {
	    const Column_Group * group = col_or_grp.group();
	    lines = titles(group->members());

	    //	Determine the spacing of the group's first column.
	    std::string spacing;
	    const Output_Column * first_col = first_column(group);
	    if (first_col)
		spacing = first_col->spacing_str();

	    //	Determine the line length in the members' titles.
	    int length = 0;
	    if (lines.size() > 0)
		length = lines[0].size();

	    //	Insert the group's title.
	    std::vector<std::string> group_title;
	    for (int i = 0; i < group->title().line_count(); i++) {
		std::string line = spacing + group->title()[i];
		if (line.size() > (unsigned int) length)
		    line = line.substr(0, length);
		line += std::string(length - line.size(),
				    (i == group->title().line_count() - 1)
									? '_'
									: ' ');
		group_title.push_back(line);
	    }
	    lines.insert(lines.begin(), group_title.begin(),
					group_title.end());
	}

	return lines;
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text titles(const std::vector<Column_or_Group> & cols)
	//  Construct all the titles for the list of columns and groups.  The
	//  lines will all be the same length, with padding at the right with
	//  spaces.
    {
	std::vector<std::string> all_titles;

	for (unsigned int i = 0; i < cols.size(); i++) {
	    std::vector<std::string> titles_to_add = title(cols[i]);

	    //  Make sure the number of existing lines and lines to add are the
	    //  same.  Insert blank lines on top of shorter list.
	    unsigned int j;
	    if (all_titles.size() > titles_to_add.size()) {
		std::string blank_line;
		if (titles_to_add.size() > 0)
		    blank_line = std::string(titles_to_add[0].size(), ' ');
		for (j = all_titles.size() - titles_to_add.size(); j > 0; j--)
		    titles_to_add.insert(titles_to_add.begin(), blank_line);
	    }
	    else if (all_titles.size() < titles_to_add.size()) {
		for (j = titles_to_add.size() - all_titles.size(); j > 0; j--)
		    all_titles.insert(all_titles.begin(), "");
	    }

	    //  Make sure all the existing title lines are equal length (pad
	    //  out the shorter ones with spaces).
	    int max_length = 0;
	    for (j = 0; j < all_titles.size(); j++)
		if (all_titles[j].size() > (unsigned int) max_length)
		    max_length = all_titles[j].size();
	    for (j = 0; j < all_titles.size(); j++)
		all_titles[j] += std::string(max_length - all_titles[j].size(),
					     ' ');
	    //  Append new title lines.
	    for (j = 0; j < titles_to_add.size(); j++)
		all_titles[j] += titles_to_add[j];
	}

	return all_titles;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

Multi_Line_Text combine_titles(const std::vector<Column_or_Group> & columns)
{
    std::vector<std::string> all_titles = titles(columns);

    //	Trim all trailing whitespace.
    for (unsigned int i = 0; i < all_titles.size(); i++)
	all_titles[i] = trim_whitespace(all_titles[i], Trailing);

    return all_titles;
}
