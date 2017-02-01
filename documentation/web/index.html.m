%DEFINE %TITLE [HUE - Harmon Uncertainty Estimator]
%DEFINE %STYLE_SHEET [../../app]

%DEFINE_SCRIPT %NAV_CONTENTS
{
    nav_contents(<<END);
Software		url=../../index.html
  Programs
    StandCarb		url=../standCarb/index.html
    MaxCarb		url=../maxCarb/index.html
    HUE <<
  Libraries
    Climate		url=../../libs/climate/index.html
END
}
%END_DEFINE

%DEFINE %CONTENTS

    <p class=head1>
	HUE - Harmon Uncertainty Estimator
    <p>
	A tool for estimating how uncertainty or error is propagated in
	calculations involving variables that have a degree of uncertainty.

    <p class=head2>
	Documentation

    <p>
	A concise and complete <a href="Users_Guide.html">Users Guide</a> is
	available.

    <p class=head2>
	Download
    <p>
	The <a href="HUE_2002-09-03.zip">current version of the program</a>
	was built on 3 Sept 2002.

    <p class=head2>
	Development
    <p>
	The next version is currently under development, and will include a
	graphical user interface.

%END_DEFINE

%INCLUDE [page_template.m]
