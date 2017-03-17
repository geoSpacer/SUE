#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 1 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 03/12/03
# Time: 16:02:48
# 
# AYACC Version: 1.97 (Beta Release)
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : action $end

    1  action : variable_defn
    2         | rank_correlate
    3         | stats_query
    4         | regression
    5         | output

    6  var_name : TOKEN_VAR_NAME

    7  integer : TOKEN_INTEGER

    8  number : integer
    9         | TOKEN_FLOAT

   10  variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN
   11                | var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
   12                | var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
   13                | var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
   14                | var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

   15  $$1 :

   16  variable_defn : var_name TOKEN_EQUAL $$1 expr

   17  expr : TOKEN_INTEGER
   18       | TOKEN_FLOAT
   19       | constant
   20       | function
   21       | TOKEN_VAR_NAME
   22       | TOKEN_T
   23       | TOKEN_MINUS expr
   24       | expr TOKEN_PLUS expr
   25       | expr TOKEN_MINUS expr
   26       | expr TOKEN_STAR expr
   27       | expr TOKEN_SLASH expr
   28       | expr TOKEN_CARET expr
   29       | TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN

   30  constant : TOKEN_PI
   31           | TOKEN_E

   32  function : ln_function
   33           | log10_function

   34  ln_function : TOKEN_LN TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN

   35  log10_function : TOKEN_LOG10 TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN

   36  rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

   37  grow_or_decay : TOKEN_GROW
   38                | TOKEN_DECAY

   39  stats_query : TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
   40              | TOKEN_MEAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
   41              | TOKEN_MEDIAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
   42              | TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN
   43              | TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN
   44              | TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA number TOKEN_RIGHT_PAREN

   45  filename : TOKEN_STRING

   46  $$2 :

   47  $$3 :

   48  regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

   49  $$4 :

   50  $$5 :

   51  regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

   52  percentiles : TOKEN_LEFT_PAREN percentile more_percentiles TOKEN_RIGHT_PAREN

   53  percentile : number

   54  more_percentiles :
   55                   | TOKEN_COMMA percentile more_percentiles

   56  output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN
   57         | TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

   58  more_vars :
   59            | var_name TOKEN_COMMA more_vars


##############################################################################
# States
##############################################################################

state 0
	$accept : . action $end

	TOKEN_VAR_NAME  shift 1
	TOKEN_RANK_CORRELATE  shift 2
	TOKEN_STD_DEVIATION  shift 3
	TOKEN_MEAN  shift 4
	TOKEN_MEDIAN  shift 5
	TOKEN_CORRELATION  shift 6
	TOKEN_RANK_CORRELATION  shift 7
	TOKEN_PERCENTILE_BOUNDS  shift 8
	TOKEN_REGRESSION  shift 9
	TOKEN_REGRESSION_PERCENTILES  shift 10
	TOKEN_VALS_TO_CSV  shift 11
	TOKEN_HISTOGRAMIZE  shift 12

	action  goto 13
	variable_defn  goto 14
	rank_correlate  goto 15
	stats_query  goto 16
	regression  goto 17
	output  goto 18
	var_name  goto 19


state 1
	var_name : TOKEN_VAR_NAME .  (6)

	.  reduce 6


state 2
	rank_correlate : TOKEN_RANK_CORRELATE . TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 20


state 3
	stats_query : TOKEN_STD_DEVIATION . TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 21


state 4
	stats_query : TOKEN_MEAN . TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 22


state 5
	stats_query : TOKEN_MEDIAN . TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 23


state 6
	stats_query : TOKEN_CORRELATION . TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 24


state 7
	stats_query : TOKEN_RANK_CORRELATION . TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 25


state 8
	stats_query : TOKEN_PERCENTILE_BOUNDS . TOKEN_LEFT_PAREN var_name TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 26


state 9
	regression : TOKEN_REGRESSION . $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN
	$$2 : .  (46)

	.  reduce 46

	$$2  goto 27


state 10
	regression : TOKEN_REGRESSION_PERCENTILES . $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN
	$$4 : .  (49)

	.  reduce 49

	$$4  goto 28


state 11
	output : TOKEN_VALS_TO_CSV . TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 29


state 12
	output : TOKEN_HISTOGRAMIZE . TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 30


state 13
	$accept : action . $end  (0)

	$end  accept


state 14
	action : variable_defn .  (1)

	.  reduce 1


state 15
	action : rank_correlate .  (2)

	.  reduce 2


state 16
	action : stats_query .  (3)

	.  reduce 3


state 17
	action : regression .  (4)

	.  reduce 4


state 18
	action : output .  (5)

	.  reduce 5


state 19
	variable_defn : var_name . TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name . TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name . TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name . TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name . TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name . TOKEN_EQUAL $$1 expr

	TOKEN_COMMA  shift 31
	TOKEN_EQUAL  shift 32


state 20
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN . var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 33


state 21
	stats_query : TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN . var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 34


state 22
	stats_query : TOKEN_MEAN TOKEN_LEFT_PAREN . var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 35


state 23
	stats_query : TOKEN_MEDIAN TOKEN_LEFT_PAREN . var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 36


state 24
	stats_query : TOKEN_CORRELATION TOKEN_LEFT_PAREN . var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 37


state 25
	stats_query : TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN . var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 38


state 26
	stats_query : TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN . var_name TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 39


state 27
	regression : TOKEN_REGRESSION $$2 . TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 40


state 28
	regression : TOKEN_REGRESSION_PERCENTILES $$4 . TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 41


state 29
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN . var_name TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 42


state 30
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN . var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 43


state 31
	variable_defn : var_name TOKEN_COMMA . var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 44


state 32
	variable_defn : var_name TOKEN_EQUAL . TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name TOKEN_EQUAL . TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name TOKEN_EQUAL . TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name TOKEN_EQUAL . TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	variable_defn : var_name TOKEN_EQUAL . $$1 expr
	$$1 : .  (15)

	TOKEN_TRIANGULAR  shift 45
	TOKEN_UNIFORM  shift 46
	TOKEN_NORMAL  shift 47
	TOKEN_NEG_EXPONENTIAL  shift 48
	.  reduce 15

	$$1  goto 49


state 33
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name . TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 50


state 34
	stats_query : TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN var_name . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 51


state 35
	stats_query : TOKEN_MEAN TOKEN_LEFT_PAREN var_name . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 52


state 36
	stats_query : TOKEN_MEDIAN TOKEN_LEFT_PAREN var_name . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 53


state 37
	stats_query : TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name . TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 54


state 38
	stats_query : TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name . TOKEN_COMMA var_name TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 55


state 39
	stats_query : TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 56


state 40
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN . expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 67
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 41
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN . expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 72
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 42
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name . TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 73


state 43
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name . TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 74


state 44
	variable_defn : var_name TOKEN_COMMA var_name . TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_EQUAL  shift 75


state 45
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR . TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 76


state 46
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM . TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 77


state 47
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL . TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 78


state 48
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL . TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 79


state 49
	variable_defn : var_name TOKEN_EQUAL $$1 . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 80
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 50
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA . var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 81


state 51
	stats_query : TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN .  (39)

	.  reduce 39


state 52
	stats_query : TOKEN_MEAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN .  (40)

	.  reduce 40


state 53
	stats_query : TOKEN_MEDIAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN .  (41)

	.  reduce 41


state 54
	stats_query : TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA . var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 82


state 55
	stats_query : TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA . var_name TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 1

	var_name  goto 83


state 56
	stats_query : TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 87


state 57
	expr : TOKEN_VAR_NAME .  (21)

	.  reduce 21


state 58
	expr : TOKEN_LEFT_PAREN . expr TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 88
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 59
	expr : TOKEN_MINUS . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 89
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 60
	expr : TOKEN_INTEGER .  (17)

	.  reduce 17


state 61
	expr : TOKEN_FLOAT .  (18)

	.  reduce 18


state 62
	constant : TOKEN_PI .  (30)

	.  reduce 30


state 63
	constant : TOKEN_E .  (31)

	.  reduce 31


state 64
	expr : TOKEN_T .  (22)

	.  reduce 22


state 65
	ln_function : TOKEN_LN . TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 90


state 66
	log10_function : TOKEN_LOG10 . TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 91


state 67
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr . $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN
	$$3 : .  (47)

	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96
	.  reduce 47

	$$3  goto 97


state 68
	expr : constant .  (19)

	.  reduce 19


state 69
	expr : function .  (20)

	.  reduce 20


state 70
	function : ln_function .  (32)

	.  reduce 32


state 71
	function : log10_function .  (33)

	.  reduce 33


state 72
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr . $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN
	$$5 : .  (50)

	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96
	.  reduce 50

	$$5  goto 98


state 73
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA . more_vars filename TOKEN_RIGHT_PAREN
	more_vars : .  (58)

	TOKEN_VAR_NAME  shift 1
	.  reduce 58

	var_name  goto 99
	more_vars  goto 100


state 74
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA . integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84

	integer  goto 101


state 75
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL . TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_NORMAL_BIVARIATES  shift 102


state 76
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN . number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 103


state 77
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN . number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 104


state 78
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN . number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 105


state 79
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN . number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 106


state 80
	variable_defn : var_name TOKEN_EQUAL $$1 expr .  (16)
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96
	.  reduce 16


state 81
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name . TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 107


state 82
	stats_query : TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 108


state 83
	stats_query : TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 109


state 84
	integer : TOKEN_INTEGER .  (7)

	.  reduce 7


state 85
	number : TOKEN_FLOAT .  (9)

	.  reduce 9


state 86
	number : integer .  (8)

	.  reduce 8


state 87
	stats_query : TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 110


state 88
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr
	expr : TOKEN_LEFT_PAREN expr . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 111
	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96


state 89
	expr : TOKEN_MINUS expr .  (23)
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	.  reduce 23


state 90
	ln_function : TOKEN_LN TOKEN_LEFT_PAREN . expr TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 112
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 91
	log10_function : TOKEN_LOG10 TOKEN_LEFT_PAREN . expr TOKEN_RIGHT_PAREN

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 113
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 92
	expr : expr TOKEN_PLUS . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 114
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 93
	expr : expr TOKEN_MINUS . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 115
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 94
	expr : expr TOKEN_STAR . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 116
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 95
	expr : expr TOKEN_SLASH . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 117
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 96
	expr : expr TOKEN_CARET . expr

	TOKEN_VAR_NAME  shift 57
	TOKEN_LEFT_PAREN  shift 58
	TOKEN_MINUS  shift 59
	TOKEN_INTEGER  shift 60
	TOKEN_FLOAT  shift 61
	TOKEN_PI  shift 62
	TOKEN_E  shift 63
	TOKEN_T  shift 64
	TOKEN_LN  shift 65
	TOKEN_LOG10  shift 66

	expr  goto 118
	constant  goto 68
	function  goto 69
	ln_function  goto 70
	log10_function  goto 71


state 97
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 . TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 119


state 98
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 . TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 120


state 99
	more_vars : var_name . TOKEN_COMMA more_vars

	TOKEN_COMMA  shift 121


state 100
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars . filename TOKEN_RIGHT_PAREN

	TOKEN_STRING  shift 122

	filename  goto 123


state 101
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer . TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 124


state 102
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES . TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 125


state 103
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number . TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 126


state 104
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 127


state 105
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 128


state 106
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 129


state 107
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA . number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 130


state 108
	stats_query : TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN .  (42)

	.  reduce 42


state 109
	stats_query : TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN .  (43)

	.  reduce 43


state 110
	stats_query : TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (44)

	.  reduce 44


state 111
	expr : TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN .  (29)

	.  reduce 29


state 112
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr
	ln_function : TOKEN_LN TOKEN_LEFT_PAREN expr . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 131
	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96


state 113
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr
	log10_function : TOKEN_LOG10 TOKEN_LEFT_PAREN expr . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 132
	TOKEN_PLUS  shift 92
	TOKEN_MINUS  shift 93
	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96


state 114
	expr : expr TOKEN_PLUS expr .  (24)
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96
	.  reduce 24


state 115
	expr : expr . TOKEN_PLUS expr
	expr : expr TOKEN_MINUS expr .  (25)
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	TOKEN_STAR  shift 94
	TOKEN_SLASH  shift 95
	TOKEN_CARET  shift 96
	.  reduce 25


state 116
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr TOKEN_STAR expr .  (26)
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	TOKEN_CARET  shift 96
	.  reduce 26


state 117
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr TOKEN_SLASH expr .  (27)
	expr : expr . TOKEN_SLASH expr
	expr : expr . TOKEN_CARET expr

	TOKEN_CARET  shift 96
	.  reduce 27


state 118
	expr : expr . TOKEN_PLUS expr
	expr : expr . TOKEN_MINUS expr
	expr : expr . TOKEN_STAR expr
	expr : expr . TOKEN_SLASH expr
	expr : expr TOKEN_CARET expr .  (28)
	expr : expr . TOKEN_CARET expr

	TOKEN_CARET  shift 96
	.  reduce 28


state 119
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA . number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 133


state 120
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA . number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 134


state 121
	more_vars : var_name TOKEN_COMMA . more_vars
	more_vars : .  (58)

	TOKEN_VAR_NAME  shift 1
	.  reduce 58

	var_name  goto 99
	more_vars  goto 135


state 122
	filename : TOKEN_STRING .  (45)

	.  reduce 45


state 123
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars filename . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 136


state 124
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA . number TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 137


state 125
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN . number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 138


state 126
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA . number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 139


state 127
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 140


state 128
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 141


state 129
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 142


state 130
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number . TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 143


state 131
	ln_function : TOKEN_LN TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN .  (34)

	.  reduce 34


state 132
	log10_function : TOKEN_LOG10 TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN .  (35)

	.  reduce 35


state 133
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number . TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 144


state 134
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number . TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 145


state 135
	more_vars : var_name TOKEN_COMMA more_vars .  (59)

	.  reduce 59


state 136
	output : TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN .  (56)

	.  reduce 56


state 137
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number . TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 146


state 138
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number . TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 147


state 139
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 148


state 140
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 149


state 141
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 150


state 142
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 151


state 143
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA . grow_or_decay TOKEN_RIGHT_PAREN

	TOKEN_GROW  shift 152
	TOKEN_DECAY  shift 153

	grow_or_decay  goto 154


state 144
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA . number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 155


state 145
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA . number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 156


state 146
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA . filename TOKEN_RIGHT_PAREN

	TOKEN_STRING  shift 122

	filename  goto 157


state 147
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA . number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 158


state 148
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 159


state 149
	variable_defn : var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (11)

	.  reduce 11


state 150
	variable_defn : var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (12)

	.  reduce 12


state 151
	variable_defn : var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (13)

	.  reduce 13


state 152
	grow_or_decay : TOKEN_GROW .  (37)

	.  reduce 37


state 153
	grow_or_decay : TOKEN_DECAY .  (38)

	.  reduce 38


state 154
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 160


state 155
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number . TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 161


state 156
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number . TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 162


state 157
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 163


state 158
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number . TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 164


state 159
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 165


state 160
	rank_correlate : TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN .  (36)

	.  reduce 36


state 161
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA . integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84

	integer  goto 166


state 162
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA . integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84

	integer  goto 167


state 163
	output : TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN .  (57)

	.  reduce 57


state 164
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA . number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 168


state 165
	variable_defn : var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (10)

	.  reduce 10


state 166
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer . TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 169


state 167
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer . TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 170


state 168
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number . TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 171


state 169
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA . filename TOKEN_RIGHT_PAREN

	TOKEN_STRING  shift 122

	filename  goto 172


state 170
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA . percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_LEFT_PAREN  shift 173

	percentiles  goto 174


state 171
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA . number TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 175


state 172
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 176


state 173
	percentiles : TOKEN_LEFT_PAREN . percentile more_percentiles TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 177
	percentile  goto 178


state 174
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles . TOKEN_COMMA filename TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 179


state 175
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number . TOKEN_COMMA number TOKEN_RIGHT_PAREN

	TOKEN_COMMA  shift 180


state 176
	regression : TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN .  (48)

	.  reduce 48


state 177
	percentile : number .  (53)

	.  reduce 53


state 178
	percentiles : TOKEN_LEFT_PAREN percentile . more_percentiles TOKEN_RIGHT_PAREN
	more_percentiles : .  (54)

	TOKEN_COMMA  shift 181
	.  reduce 54

	more_percentiles  goto 182


state 179
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA . filename TOKEN_RIGHT_PAREN

	TOKEN_STRING  shift 122

	filename  goto 183


state 180
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA . number TOKEN_RIGHT_PAREN

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 184


state 181
	more_percentiles : TOKEN_COMMA . percentile more_percentiles

	TOKEN_INTEGER  shift 84
	TOKEN_FLOAT  shift 85

	integer  goto 86
	number  goto 177
	percentile  goto 185


state 182
	percentiles : TOKEN_LEFT_PAREN percentile more_percentiles . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 186


state 183
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 187


state 184
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number . TOKEN_RIGHT_PAREN

	TOKEN_RIGHT_PAREN  shift 188


state 185
	more_percentiles : TOKEN_COMMA percentile . more_percentiles
	more_percentiles : .  (54)

	TOKEN_COMMA  shift 181
	.  reduce 54

	more_percentiles  goto 189


state 186
	percentiles : TOKEN_LEFT_PAREN percentile more_percentiles TOKEN_RIGHT_PAREN .  (52)

	.  reduce 52


state 187
	regression : TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN .  (51)

	.  reduce 51


state 188
	variable_defn : var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN .  (14)

	.  reduce 14


state 189
	more_percentiles : TOKEN_COMMA percentile more_percentiles .  (55)

	.  reduce 55


##############################################################################
# Summary
##############################################################################

39 token(s), 26 nonterminal(s)
60 grammar rule(s), 190 state(s)


##############################################################################
# End of File
##############################################################################
