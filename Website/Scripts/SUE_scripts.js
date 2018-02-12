// SUE_scripts.js
// Keith Olsen - 17 May 2017
//
// For use with the stochastic uncertainty estimator website

function validateSeed(oSrc, args) {
    args.IsValid = (args.Value % 2 == 1 && args.Value >= 1 && args.Value < 1000000);
}

function validateArg1(oSrc, args) {
    args.IsValid = IsNumeric(args.Value);
}

function validateMode(oSrc, args) {
    var lowerBound = document.getElementById("MainContent_textArg1");
    var upperBound = document.getElementById("MainContent_textArg2");
    args.IsValid = (args.Value >= lowerBound.value && args.Value <= upperBound.value);
}

function validateSD(oSrc, args) {
    args.IsValid = (args.Value >= 0);
}

function validateCorr(oSrc, args) {
    args.IsValid = (args.Value >= -1 && args.Value <= 1);
}

function validatePosInt(oSrc, args) {
    args.IsValid = (args.Value % 1 == 0 && args.Value >= 0);
}

function validatePercent(oSrc, args) {
    args.IsValid = (args.Value >= 0 && args.Value <= 100);
}

function validateExistParameterName(oSrc, args) {
    var e = document.getElementById("MainContent_ddlQueryParams1");
    args.IsValid = false;
    for (i = 0; i < e.options.length; i++) {
        // console.log(e.options[i].value);
        args.IsValid = (args.Value == e.options[i].value);
        if (args.IsValid) { break; }
    }
}

function validateParameterName(oSrc, args) {
    args.IsValid = (args.Value != "T" && args.Value != "e" && args.Value != "pi" && args.Value != "");
    if (args.IsValid) {
        args.IsValid = args.Value != "Uniform" && args.Value != "Triangular" && args.Value != "NegativeExponential" && args.Value != "Normal" && args.Value != "NormalBivariates" && args.Value != "rankCorrelate";
    }

    if (args.IsValid) {
        args.IsValid = args.Value != "uniform" && args.Value != "triangular" && args.Value != "negativeexponential" && args.Value != "normal" && args.Value != "normalbivariates" && args.Value != "rankcorrelate";
    }

    if (args.IsValid) {
        args.IsValid = args.Value.charAt(0).match(/[A-Z|a-z]/);
    }
}

function validateFileName(oSrc, args) {
    args.IsValid = args.Value.charAt(0).match(/[A-Z|a-z]/);

//    if (args.IsValid) {
//        args.IsValid = args.Value.substr(args.Value.length - 4) == ".csv";
//    }
}

function validateExpression(oSrc, args) {
    args.IsValid = args.Value.length > 0;
    var checkString = args.Value;
    var specialCharArray = ["e", "pi", "ln", "log10", "T"];

    if (args.IsValid) {
        var e = document.getElementById("MainContent_ddlQueryParams1");
        for (i = 0; i < e.options.length; i++) {
            console.log(e.options[i].value);
            var startIndex = checkString.indexOf(e.options[i].value)
            if (startIndex > -1) {
                var leftPart = checkString.substr(0, startIndex);
                var rightPart = checkString.substr(startIndex + e.options[i].value.length, checkString.length);
                checkString = leftPart + rightPart;
                console.log(checkString);
            }
        }

        for (i = 0; i < specialCharArray.length; i++) {
            console.log(specialCharArray[i]);
            var startIndex = checkString.indexOf(specialCharArray[i])
            if (startIndex > -1) {
                var leftPart = checkString.substr(0, startIndex);
                var rightPart = checkString.substr(startIndex + specialCharArray[i].length, checkString.length);
                checkString = leftPart + rightPart;
                console.log(checkString);
            }
        }

        args.IsValid = IsExpression(checkString);
    }
    // args.IsValid = false;
}

function validatePercentiles(oSrc, args) {
    var ValidChars = "(,).0123456789";
    var Char;

    args.IsValid = true;
    if (args.Value.length == 0)
        args.IsValid = false;

    if (args.IsValid) {
        for (i = 0; i < args.Value.length; i++) {
            Char = args.Value.charAt(i);
            if (ValidChars.indexOf(Char) == -1) {
                args.IsValid = false;
                break;
            }
        }
    }
}

function helpAlert(elID) {
    if (elID == "queryActions") {
        alert("Queries return information about the sample space. This may come in the form of returning information about the parameters (e.g., mean, standard deviation, correlation, rank correlation) or it may involve the generation of regression points for some function involving multiple parameters. One thing remains constant among queries: they do not alter the sample space in any way. This means they do not add, remove, or alter any of the parameters. Some of the queries result in answers being added to a csv type file (i.e., all those requesting a file name). Others will be provided on screen and also added to an output file describing the SUE run. This file will also include any error messages.\n\nWith expressions, one can add, subtract, multiply, or divide parameters (variables) you have described in terms of central tendency, variation, and correlation.  You can also create power and exponential functions. Expression can be used to create something as simple a combined uncertainty distribution of parameters or something as complicated as the distribution of uncertainty of several regression equations that have been combined.\n\nMany input variables are validated when the Add button is pressed.");
    } else if (elID == "parameterActions") {
        alert("Parameter Actions are those that create or modify the parameters of the sample space. In addition to describing individual parameters in terms of their mode and distribution, one can describe the relationship of parameters to each other. These relationships could be correlations (e.g., bivariate or rank) or via expressions that describe relationships. For example, parameter 3 might be the product of parameter 1 and parameter 2. One can also add, subtract, multiply, or divide parameters (variables) you have described in terms of central tendency, variation, and correlation.  You can also create power and exponential functions. Expression can be used to create something as simple a combined uncertainty distribution of parameters or something as complicated as the distribution of uncertainty of several regression equations that have been combined.\n\nMany input variables are validated when the Add button is pressed.");
    } else if (elID == "seedValue") {
        alert("Seed is the first action. Our pseudo-random number generator needs an odd integer with which to seed itself. The number following the keyword 'Seed' can be any odd integer between 1 and 1,000,000. Example: \n\nSeed 1283");
    } else if (elID == "sampleSpaceSize") {
        alert("SampleSpaceSize must be the second action of the input file. In order to generate a sample space with parameters, we must know how big the sample space is. The number following the keyword 'SampleSpaceSize' is the desired size. This number must be an integer between 2 and 1,000,000. In the interest of quick computations, it is recommended that the user restrict himself to sizes less than 100,000. Larger sizes may be attempted, but the run time of the program may get to be quite long. Example: \n\nSampleSpaceSize 10000");
    } else if (elID == "help_textBoxFile") {
        alert("Parameter and query actions in the text box may be modified or deleted directly in the text box. Changes made in this manner are not validated by the system.");
    } else {
        var e = document.getElementById(elID);
        // var selectedObj = e.options[e.selectedIndex].value;
        // console.log(e.value);
        if (e.value == "Uniform") {
            alert("parameterName = Uniform(lowerBound, upperBound) This action creates a new parameter that has uniformly distributed samples over the interval lowerBound to upperBound. The bounds can be any real numbers provided the first is smaller than the second. Example: \n\nVar1 = Uniform(4, 4.9)");
        } else if (e.value == "Triangular") {
            alert("parameterName = Triangular(lowerBound, mode, upperBound) This action creates a new parameter that has samples consistent with a triangular distribution with lowerBound, mode, and upperBound as specified. lowerBound, mode, and upperBound are real numbers where lowerBound <= mode <= upperBound. Example: \n\nLiveMax = Triangular(96.1, 99, 100)");
        } else if (e.value == "NegativeExponential") {
            alert("parameterName = NegativeExponential(lowerBound, standardDeviation) This action creates a parameter that has samples consistent with a negative exponential distribution with lowerBound and standardDeviation as specified. Restrictions are that the numbers must be real and standardDeviation must be positive. Example: \n\nVarIAblE = NegativeExponential(5.1, 3.2)");
        } else if (e.value == "Normal") {
            alert("parameterName = Normal(mode, standardDeviation) This action creates a parameter that has samples drawn from a normal distribution with mode and standardDeviation as specified. Example: \n\nVar = Normal(3, 1)");
        } else if (e.value == "NormalBivariates") {
            alert("param1, param2 = NormalBivariates(correlation, param1mode, param1stdDev, param2mode, param2stdDev) This action creates two parameters. These parameters are drawn as though from a normal distributions with correlation, modes and standardDeviations as specified. Correlation must be a real number between -1 and 1. In some cases parameters are correlated to each other. If the distributions of each parameter is a normal distribution, then one can describe both parameters at the same time and also describe their correlation. Example: \n\nb1, b2 = NormalBivariates(.5, .015, .001, 2, .1)");
        } else if (e.value == "Expression") {
            alert("parameterName = expression \nThis action creates a parameter that is calculated from the expression. Example: \n\nb3 = ln(LiveMax * (1-e^(-b1))^b2)\n\nAssignment expressions and regression expressions are identical except in one regard: regression functions should involve the free-variable 'T' and assignment functions should not. Outside of these restrictions, a valid expression can be any well-formed expression involving defined parameter names, numbers, constants (e and pi), parentheses, +, -, *, /, ^, log10, and ln.");
        } else if (e.value == "rankCorrelate") {
            alert("rankCorrelate(param1, param2, rankCorr, method) \nThis action produces a rank correlation of rankCorr in the two defined parameters param1 and param2. There are two different methods for this operation: 'grow' and 'decay'. These names have more to do with the implementation than the produced correlation. 'Grow' starts with the independently generated samples from param1 and param2 and partially sorts them relative to one-another until the desired rank correlation coefficient is obtained. 'Decay' fully sorts param1 and param2 relative to one another and then partially unsorts them until the desired rank correlation is obtained. When using rankCorrelate, try both methods and look at the differing scatter-plot spreads produced to get a feel for the difference. The specifics of the different algorithms produce different spread types - 'Grow' should produce a more uniform spread, whereas 'decay' should yield a spread that looks somewhat normally distributed about an imaginary spline of best fit for the graph. It may be the case that neither is appropriate for the data set that the user has in mind. The user should be aware that rank correlation is not the same as the more common correlation coefficient, though a high rank correlation implies a high correlation coefficient. The advantage of rank correlation is that it is better suited to describing correlation of parameters which come from different distribution types. In fact, certain combinations of correlation coefficients, and distribution types are logically impossible. Try to imagine a uniform distribution and a negative exponential distribution that have a correlation coefficient of 1. rankCorrelate allows the user to create correlated parameters from different distribution types.");
        } else if (e.value == "StandardDeviation") {
            alert("StandardDeviation(parameterName) \nThis action returns the standard deviation of the defined sample space parameter parameterName. Example: \n\nStandardDeviation(LiveMax)");
        } else if (e.value == "Mean") {
            alert("Mean(parameterName)\nThis action returns the mean value of the defined sample space parameter parameterName. Example: \n\nMean(LiveMax)");
        } else if (e.value == "Median") {
            alert("Median(parameterName) \nThis action returns the median value of the defined sample space parameter parameterName. Example: \n\nMedian(LiveMax)");
        } else if (e.value == "Correlation") {
            alert("Correlation(param1, param2) \nThis action returns the correlation coefficient of the defined sample space parameters param1 and param2. Example: \n\nCorrelation(LiveMax, b2)");
        } else if (e.value == "RankCorrelation") {
            alert("RankCorrelation(param1, param2) \nThis action returns the rank correlation coefficient of the defined sample space parameters param1 and param2. Example: \n\nRankCorrelation(LiveMax, b2)");
        } else if (e.value == "PercentileBounds") {
            alert("PercentileBounds(parameterName, percentile) \nThis action returns the two values that enclose the middle percentile percent of the values in sample space parameter parameterName. Note that this may involve a weighted average of two samples for both the upper and lower bound - so the values returned may or may not actually occur in the sample space. Example: \n\nPercentileBounds(LiveMax, 50.5)");
        } else if (e.value == "ValsToCSV") {
            alert("ValsToCSV(paramNameList, 'fileName')\nThis action sends the values of the sample space parameters in paramNameList to a .csv (comma separated value) file named 'fileName'. ParamNameList must be a series of defined parameter names, separated by commas. fileName must be enclosed in quotation marks and should end in '.csv' since it will be a comma separated value file (intended to be opened with Excel). Example: \n\nValsToCSV(LiveMax, b1, b2, Var1, 'vals.csv')");
        } else if (e.value == "Histogramize") {
            alert("Histogramize(paramName, boxes, excludedTailPercent, 'fileName')\nThis action creates a histogram of the valid sample space parameter paramName. The histogram comes in the form of a .csv file named filename that should end in '.csv' and is intended to be viewed with Excel. Boxes is the number of boxes/bins to use in the histogram. ExcludedTailPercent is the percent of extreme values in paramName to leave out of the histogram. For example, if excludedTailPercent were 5, the histogram would not account for the lowest 2.5% or the highest 2.5% of the values in paramName. ExcludedTailPercent should be set to 0 for most cases - however, when a parameter has very long, sparse tails, leaving out a small portion of the tail values can make the histogram show more detail about more densely populated regions. Obviously, excludedTailPercent must be between 0 and 100. Examples: \n\nHistogramize(VarIAblE, 20, 0, 'histWithTails.csv')\nHistogramize(VarIAblE, 20, 5, 'histMinus5%Tails.csv')");
        } else if (e.value == "Regression") {
            alert("Regression(functionOfParamsAndT, tStart, tFinish, steps, 'fileName')\nThe regression query does not create a regression per se.  However, it can be used to evaluate the uncertainty of a regression equation.  It does this by evaluating the regression’s uncertainty given parameter uncertainty at fixed intervals of the free-variable (i.e., independent variable) that drives the regression. To create the fixed intervals one specifies the range of the free-variable to be examined and the number of steps to be evaluated. Specifically, this action creates a comma separated value file named fileName with the raw results of performing the regression equation functionOfParamsAndT on the sample space of parameters mentioned in functionOfParamsAndT. functionOfParamsAndT can be any well-formed function that involves the free variable 'T'. 'T' is the hard-wired name of the free-variable (i.e., independent variable) in a regression equation and no other name will be accepted. Regression works by evaluating functionOfParamsAndT for each set of parameter samples at steps + 1 discrete (and evenly spaced) T-values, starting at tStart and finishing at tFinish. Upon completion of Regression a file specified by the user, filename will be created.  It will have two columns; the first will have free-variable values and the second will have solutions to functionOfParamsAndT for those free-variable values. With a large sample space size and a large steps value, this file can be very large and take a long time to create.\n\nSee the manual for examples");
        } else if (e.value == "RegressionPercentiles") {
            alert("RegressionPercentiles(functionOfParamsAndT, tStart, tFinish, steps, (percentiles), 'fileName')\nThis action is just as Regression only it takes another input - a list of comma-separated percentiles, percentiles, enclosed in parentheses. Rather than return the computed results for each set of parameter samples for each T-value, the enclosing values (at each T-value) for each percentile requested are returned in the .csv file. For example, a value of 20 in the percentile list requests the values that enclose the middle 20% of all result values at each T-value. A value of 0 in the percentile list requests the median for each T-value. Though RegressionPercentiles involves many more calculations (due to calculating the percentiles) than Regression, the output file may be much smaller. It therefore can accommodate larger sample space sizes in conjunction with large values of steps. Furthermore, with well-chosen percentiles values, RegressionPercentiles can give a better picture of the distribution of values in the regression results. Example: \n\nRegressionPercentiles( LiveMax * (1-e^(-b1*t))^b2, 0, 400, 50, (0,25,50,75.0,100), 'regressPercentiles.csv')");
        } else if (e.value = "Comment") {
            alert("Enter a comment into the input file. The SUE code will ignore this comment when it executes.");
        }

    }
}

function IsNumeric(sText) {
    var ValidChars = "-.0123456789";
    var IsNumber = true;
    var Char;

    if (sText.length == 0)
        IsNumber = false;

    for (i = 0; i < sText.length && IsNumber == true; i++) {
        Char = sText.charAt(i);
        if (ValidChars.indexOf(Char) == -1)
            IsNumber = false;
    }
    return IsNumber;
}

function IsExpression(sText) {
    var ValidChars = "-.0123456789()^/*+ ";
    var IsNumber = true;
    var Char;

    if (sText.length == 0)
        IsNumber = false;

    for (i = 0; i < sText.length && IsNumber == true; i++) {
        Char = sText.charAt(i);
        if (ValidChars.indexOf(Char) == -1)
            IsNumber = false;
    }
    return IsNumber;
}