#  Usage:
#
#      perl {script} {message_file} {state_file} < {YACC_verbose_output}
#
#  This script scans the YACC verbose output file from the Parser Generator
#  application to produce more-detailed syntax error messages.  This verbose
#  file is read from standard input.  The scripts determines the list of
#  unique error messages and print the C/C++ string literals for them to one
#  output file.  In a second output file, the script outputs the C/C++
#  initializing code for pairs of potential error states and the number of
#  their corresponding error message.
#------------------------------------------------------------------------------

#  Process command arguments
if (scalar(@ARGV) != 2) {
    print STDERR <<END_MESG;
Error in using the Perl script "$0".
Usage:  perl $0 {message_file} {state_file} < {YACC_verbose_output}
END_MESG
    exit 1;
}

$message_file = shift(@ARGV);
$state_file   = shift(@ARGV);

if (! open(MESG_FILE, ">$message_file")) {
    print STDERR
	"Error:  Cannot open the file \"$message_file\" for output.\n";
    exit 1;
}

if (! open(STATE_FILE, ">$state_file")) {
    print STDERR
	"Error:  Cannot open the file \"$state_file\" for output.\n";
    exit 1;
}

#--------------------
#  The prefix that is stripped off the name of each token.
$prefix = 'TOKEN_';

#  Read the verbose file, storing those states with shifts actions and
#  no ". reduce" rule.

$have_line = 1;
while ($have_line) {
    #  Skip to start of a state.
    do {
	$have_line = read_line();
    } while ( $have_line && ($_ !~ /^state (\d+)$/) );
    if ($have_line) {
	$state = $1;
    } else {
	last;
    }

    #  Skip the grammar rules assocated with the state; a blank line marks
    #  the end of the rules.
    do {
	$have_line = read_line();
    } while ( $have_line && ($_ !~ /^\s*$/) );

    #  Now read any shift actions the state has.  Also look for the accept
    #  action.
    @tokens = ( );
    $dot_reduce = 0;

    $have_line = read_line();
    while ( $have_line && ($_ !~ /^\s*$/) ) {
	if ($_ =~ /^\s*([A-Za-z0-9_]+)\s+shift/ ) {
	    $token = $1;
	    $token =~ s/^$prefix// if $prefix ne '';
	    push @tokens, $token;
	} elsif ($_ =~ /^\s*\$end\s+accept/ ) {
	    push @tokens, '_EOI_';
	} elsif ($_ =~ /^\s*\.\s+reduce/) {
	    $dot_reduce = 1;
	}
	$have_line = read_line();
    }

    if (scalar(@tokens) > 0) {
	if (! $dot_reduce) {
	    push @states, $state;
	    $state_tokens{$state} = join(' ', @tokens);
	}
    }
}

#--------------------
#  Sort each individual list of tokens to a pre-defined order, and determine
#  each unique list.

%token_groups = (
	'end_of_line' => [ '_EOI_' ],
	'variable' => [ 'VAR_NAME' ],
	'number' => [ 'INTEGER', 'FLOAT' ],
	'constant' => [ 'PI', 'E' ],
	'distribution_type' => [ 'TRIANGULAR',
				 'UNIFORM',
				 'NORMAL',
				 'NEG_EXPONENTIAL', ],
	'query_command' => [	'STD_DEVIATION',
				'MEAN',
				'MEDIAN',
				'CORRELATION',
				'RANK_CORRELATION',
				'PERCENTILE_BOUNDS', ],
	'regression_command' => [ 'REGRESSION',
				 'REGRESSION_PERCENTILES', ],
	'output_command' => [ 'VALS_TO_CSV',
			      'HISTOGRAMIZE', ],
	'numeric_operator' => [ 'PLUS', 'MINUS', 'STAR', 'SLASH', 'CARET' ],
);

foreach $state (@states) {
    @tokens = split(/ /, $state_tokens{$state});

    #  Order the list first.
    @tokens = sort by_token_order @tokens;

    #  If all the members of a token group are present, then replace them
    #  with the group's name.
    $tokens = ' ' . join(' ', @tokens) . ' ';
    foreach my $group (keys(%token_groups)) {
	my $members = $token_groups{$group};
	my $first_member = '';
	my $first_member_pos = length($tokens);
	my $all_members_present = 1;

	foreach my $member (@$members) {
	    if ($tokens =~ / $member /) {
		my $pos = length($`);
		if ($pos < $first_member_pos) {
		    $first_member_pos = $pos;
		    $first_member = $member;
		}
	    } else {
		$all_members_present = 0;
		last;
	    }
	}

	if ($all_members_present) {
	    foreach my $member (@$members) {
		if ($member eq $first_member) {
		    $tokens =~ s/ $member / $group /;
		} else {
		    $tokens =~ s/ $member / /;
		}
	    }
	}
    }  #  foreach group

    #  Replace each token and group by its string representation.
    $tokens =~ s/^\s+//;
    $tokens =~ s/\s+$//;
    @tokens = split(/\s+/, $tokens);
    @token_strs = ( );
    foreach my $token (@tokens) {
	my $token_str = $Token_Strs{$token};
	if ($token_str eq '') {
	    #  It's a token group name.
	    ($token_str = $token) =~ s/_/ /g;
	} else {
	    $token_str = "\"$token_str\"";
	}
	push @token_strs, $token_str;
    }

    #  Construct the message explaining what was expected for the state.
    $message = "Expected ";
    $first_token_str = $token_strs[0];
    if ($first_token_str =~ /^end of line$/) {
	$message .= "the ";
    } elsif ($first_token_str =~ /^[aieouAIEOU]/) {
	$message .= "an ";
    } elsif ($first_token_str =~ /^[A-Za-z]/) {
	$message .= "a ";
    }
    $count = scalar(@token_strs);
    $pos = 0;
    foreach $token_str (@token_strs) {
	$message .= $token_str;
	$pos++;
	if ($pos == $count - 1) {
	    $message .= " or ";
	} elsif ($pos < $count - 1) {
	    $message .= ", ";
	}
    }

    #  Store each message if it's unique, and assign the message # to the
    #  state.
    $message_number = $message_nums{$message};
    if ($message_number eq '') {
	#  It's a new message
	$message_number = scalar(@messages);
	push @messages, $message;
	$message_nums{$message} = $message_number;
    }
    $state_mesg_nums{$state} = $message_number;
}

#--------------------
#  Print the message list, and the message numbers for each state.
select(MESG_FILE);
print "/* Error Messages */\n";
$mesg_num = 0;
$count = scalar(@messages);
$num_width = length($count);
foreach my $message (@messages) {
    print "  /* ", sprintf("%${num_width}d", $mesg_num), " */  \"";
    $message =~ s/"/\\"/g;
    print "$message\"";
    if ($mesg_num < $count - 1) {
	print ",";
    }
    print "\n";
    $mesg_num++;
}
close MESG_FILE;

#  Print the states and their message numbers.
select(STATE_FILE);
print "/* Potential error States and their corresponding Messages */\n";
$count = scalar(@states);
$pos = 0;
foreach my $state (@states) {
    print "\t{ $state, $state_mesg_nums{$state} }";
    if ($pos < $count - 1) {
	print ",";
    }
    print "\n";
    $pos++;
}
close STATE_FILE;

exit 0;

#------------------------------------------------------------------------------

#  The representations for each token name.

BEGIN {
    %Token_Strs = (
	'INTEGER'	=> 'integer',
	'FLOAT'		=> 'float',
	'VAR_NAME'	=> 'variable',
	'PI'		=> 'pi',
	'E'		=> 'e',
	'T'		=> 't',
	'PLUS'	 	=> '+',
	'MINUS'		=> '-',
	'STAR'		=> '*',
	'SLASH'		=> '/',
	'CARET'		=> '^',
	'EQUAL'		=> '=',
	'LEFT_PAREN'	=> '(',
	'RIGHT_PAREN'	=> ')',
	'COMMA'		=> ',',
	'GROW'		=> 'grow',
	'DECAY'		=> 'decay',

	'IF'		=> 'if',
	'AND'		=> 'and',
	'OR'		=> 'or',
	'NOT'		=> 'not',
	'LESS'		=> '<',
	'LESS_EQUAL'	=> '<=',
	'GREATER'	=> '>',
	'GREATER_EQUAL'	=> '>=',
	'LN'		=> 'ln',
	'LOG10'		=> 'log10',
	'MIN'		=> 'min',
	'MAX'		=> 'max',
	'CR'		=> 'CR',
	'MCR'		=> 'MCR',
    );
}

#------------------------------------------------------------------------------

#  This subroutine reads in the next line from standard input.  It skips
#  comment lines which are those that have a '#' as their first non-whitespace
#  character.
#
#  Returns:
#	1	A line has been read in, and assigned to the $_.
#
#	0	The end of input was reached.

sub read_line
{
    while (<>) {
	chomp;
	next if /^\s*#/;
	return 1;
    }
    return 0;
}

#------------------------------------------------------------------------------

#  This routine sorts tokens according to a pre-defined order.

sub by_token_order
{
    return $Token_Position{$a} <=> $Token_Position{$b};
}

BEGIN {
    @Token_Order = (
	'_EOI_',

	'TRIANGULAR',
	'UNIFORM',
	'NORMAL',
	'NEG_EXPONENTIAL',

	'INTEGER',
	'FLOAT',

	'VAR_NAME',

	'PI',
	'E',

	'PLUS',
	'MINUS',
	'STAR',
	'SLASH',
	'CARET',

	'RANK_CORRELATE',
	'STD_DEVIATION',
	'MEAN',
	'MEDIAN',
	'CORRELATION',
	'RANK_CORRELATION',
	'PERCENTILE_BOUNDS',

	'REGRESSION',
	'REGRESSION_PERCENTILES',

	'VALS_TO_CSV',
	'HISTOGRAMIZE',

	'EQUAL',
	'LEFT_PAREN',
	'COMMA',
	'RIGHT_PAREN',

	'STRING',
    );

    my $position = 0;
    foreach my $token (@Token_Order) {
	$Token_Position{$token} = $position;
	$position++;
    }
}
