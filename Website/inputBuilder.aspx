<%@ Page Title="Input File Builder" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="inputBuilder.aspx.cs" Inherits="inputBuilder" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <script src="Scripts/SUE_scripts.js" type="text/javascript" language="JavaScript"></script>
    <h2><%: Title %></h2>
    <h3>Step 1. Initilization Actions</h3>
    <div>
        <table>
            <tr>
                <td>Enter a seed value for the pseudo-random number generator. Number must be an odd integer between 1 and 999,999.
                    <a href="#" onclick="helpAlert('seedValue')">
                        <asp:Image ID="imgSeedValue" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a>
                </td>
                <td style="padding-left: 10px">
                    <asp:TextBox ID="textSeedVal" runat="server" MaxLength="7" Width="120px"
                        TabIndex="1">1283</asp:TextBox>
                    <asp:CustomValidator ID="CustomValidator_seedNum" runat="server"
                        ControlToValidate="textSeedVal"
                        ErrorMessage="Please enter an odd integer between 1 and 999,999"
                        ValidationGroup="AllValidators" ClientValidationFunction="validateSeed" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
            <tr>
                <td>Enter a sample space size. Number must be an integer between 2 and 1,000,000.
                    <a href="#" onclick="helpAlert('sampleSpaceSize')">
                        <asp:Image ID="imgSampleSpaceSize" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a>
                </td>
                <td style="padding-left: 10px">
                    <asp:TextBox ID="textSampleSpaceSize" runat="server" MaxLength="7" Width="120px"
                        TabIndex="2">10000</asp:TextBox>
                    <asp:RequiredFieldValidator
                        ID="RequiredFieldValidator_sampleSpaceSize" runat="server" ControlToValidate="textSampleSpaceSize"
                        ErrorMessage="Please enter an integer between 2 and 1,000,000" ValidationGroup="AllValidators"
                        SetFocusOnError="True">*</asp:RequiredFieldValidator>
                    <asp:RangeValidator ID="RangeValidator_sampleSpaceSize" runat="server"
                        ControlToValidate="textSampleSpaceSize"
                        ErrorMessage="Please enter an integer between 2 and 1,000,000"
                        ValidationGroup="AllValidators" SetFocusOnError="True" MaximumValue="1000000" MinimumValue="2" Type="Integer" ValidateEmptyText="True">*</asp:RangeValidator>
                </td>
            </tr>
        </table>
        <h3>Step 2. Parameter Actions
            <a href="#" onclick="helpAlert('parameterActions')">
                <asp:Image ID="imgParameter" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a></h3>
        <table>
            <tr>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblChooseParameter" Text="Choose parameter action" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:DropDownList ID="ddlParameterActions" runat="server" AutoPostBack="True" Height="30px" Width="200px" TabIndex="3" OnSelectedIndexChanged="ddlParameterActions_SelectedIndexChanged">
                        <asp:ListItem Value="default">Choose action</asp:ListItem>
                        <asp:ListItem Value="Uniform">Uniform</asp:ListItem>
                        <asp:ListItem Value="Triangular">Triangular</asp:ListItem>
                        <asp:ListItem Value="NegativeExponential">NegativeExponential</asp:ListItem>
                        <asp:ListItem Value="Normal">Normal</asp:ListItem>
                        <asp:ListItem Value="NormalBivariates">NormalBivariates</asp:ListItem>
                        <asp:ListItem Value="Expression">Expression</asp:ListItem>
                        <asp:ListItem Value="rankCorrelate">rankCorrelate</asp:ListItem>
                        <asp:ListItem Value="Comment">Comment</asp:ListItem>
                    </asp:DropDownList>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblParameterName" Text="parameter name" runat="server" Font-Size="Large"></asp:Label>
                    <asp:Label ID="lblCommentParam" Text="comment" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textParameterName" runat="server" Width="140px" TabIndex="4">
                    </asp:TextBox>
                    <asp:TextBox ID="textCommentParam" runat="server" Width="500px" TabIndex="4">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_ParameterName" runat="server"
                        ControlToValidate="textParameterName"
                        ErrorMessage="Parameter names must start with a letter, but can contain numbers and other symbols after the first character. No action keywords (normal, regression, etc) or constant names (e and pi) may be used as parameter names. Additionally, the name 'T' is reserved for the free variable name in regression equations."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateParameterName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_existParameterName" runat="server"
                        ControlToValidate="textParameterName"
                        ErrorMessage="Parameters for rankCorrelate must already exist."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateExistParameterName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblArg1" Text="Argument 1" runat="server" Font-Size="Large"></asp:Label>
                    <asp:Label ID="lblExpression" Text="expression" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textArg1" runat="server" Width="120px" TabIndex="5">
                    </asp:TextBox>
                    <asp:TextBox ID="textExpression" runat="server" Width="300px" TabIndex="5">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_expression" runat="server"
                        ControlToValidate="textExpression"
                        ErrorMessage="Assignment expressions and regression expressions are identical except in one regard: regression functions should involve the free-variable 'T' and assignment functions should not. Outside of these restrictions, a valid expression can be any well-formed expression involving defined parameter names, numbers, constants (e and pi), parentheses, +, -, *, /, ^, log10, and ln."
                        ValidationGroup="Validators_parameterActions" SetFocusOnError="True" ValidateEmptyText="True" ClientValidationFunction="validateExpression">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_arg1" runat="server"
                        ControlToValidate="textArg1"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_corr" runat="server"
                        ControlToValidate="textArg1"
                        ErrorMessage="Correlation values range from -1 to 1."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateCorr" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td>
                    <asp:Label ID="lblArg2" Text="Argument 2" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textArg2" runat="server" Width="120px" TabIndex="6">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_arg2" runat="server"
                        ControlToValidate="textArg2"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CompareValidator ID="compareValidator_lowerUpper" runat="server" 
                        ControlToValidate="textArg2" ControlToCompare="textArg1" Operator="GreaterThan" SetFocusOnError="True" ErrorMessage="The upperBound must be greater than the lowerBound."
                        ValidationGroup="Validators_parameterActions" Type="Double">*</asp:CompareValidator>
                    <asp:CustomValidator ID="customValidator_SD" runat="server"
                        ControlToValidate="textArg2"
                        ErrorMessage="Standard Deviation values must be positive."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateSD" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
            <tr>
                <td></td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblParameter2" Text="parameter 2" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textParameter2" runat="server" Width="140px" TabIndex="7">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_parameter2" runat="server"
                        ControlToValidate="textParameter2"
                        ErrorMessage="Parameter names must start with a letter, but can contain numbers and other symbols after the first character. No action keywords (normal, regression, etc) or constant names (e and pi) may be used as parameter names. Additionally, the name 'T' is reserved for the free variable name in regression equations."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateParameterName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_existParameterName2" runat="server"
                        ControlToValidate="textParameter2"
                        ErrorMessage="Parameters for rankCorrelate must already exist."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateExistParameterName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblArg3" Text="Argument 3" runat="server" Font-Size="Large"></asp:Label>
                    <asp:Label ID="lblMethod" Text="method" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textArg3" runat="server" Width="120px" TabIndex="8">
                    </asp:TextBox>
                    <asp:DropDownList ID="ddlMethod" runat="server" TabIndex="8" Width="120">
                        <asp:ListItem Value="grow">grow</asp:ListItem>
                        <asp:ListItem Value="decay">decay</asp:ListItem>
                    </asp:DropDownList>
                    <asp:CustomValidator ID="customValidator_arg3" runat="server"
                        ControlToValidate="textArg3"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_mode" runat="server"
                        ControlToValidate="textArg3"
                        ErrorMessage="lower bound <= mode <= upper bound."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateMode" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_SD3" runat="server"
                        ControlToValidate="textArg3"
                        ErrorMessage="Standard Deviation values must be positive."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateSD" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td>
                    <asp:Label ID="lblArg4" Text="Argument 4" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textArg4" runat="server" Width="120px" TabIndex="9">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_arg4" runat="server"
                        ControlToValidate="textArg4"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>

                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="btnAddParameter" runat="server" CssClass="btn btn-default" Text="Add Parameter" OnClick="btnAddParameter_Click" ValidationGroup="Validators_parameterActions" TabIndex="10" />&nbsp;&nbsp;
                        <a href="#" onclick="helpAlert('MainContent_ddlParameterActions')">
                            <asp:Image ID="img_help" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a>
                </td>
                <td></td>
                <td>
                    <asp:Label ID="lblArg5" Text="Argument 5" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textArg5" runat="server" Width="120px" TabIndex="9">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_arg5" runat="server"
                        ControlToValidate="textArg5"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_SD5" runat="server"
                        ControlToValidate="textArg5"
                        ErrorMessage="Standard Deviation values must be positive."
                        ValidationGroup="Validators_parameterActions" ClientValidationFunction="validateSD" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
        </table>

        <p>
            <br />
            <asp:Label ID="lblParameterActions" Text="File preview for parameter actions" runat="server" Font-Size="Large"></asp:Label>&nbsp;&nbsp;
            <a href="#" onclick="helpAlert('help_textBoxFile')">
                <asp:Image ID="img_helpFile" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a><br />
            <asp:TextBox ID="textFileParameterActions" Text="" Font-Names="Courier New" runat="server" Width="600px" Wrap="False" TextMode="MultiLine" Height="150px" TabIndex="11"></asp:TextBox>
        </p>
        <h3>Step 3. Query Actions
            <a href="#" onclick="helpAlert('queryActions')">
                <asp:Image ID="imgQuery" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a></h3>
        <table>
            <tr>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblChooseQuery" Text="Choose Query action" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:DropDownList ID="ddlQueryActions" runat="server" AutoPostBack="True" Height="30px" Width="200px" OnSelectedIndexChanged="ddlQueryActions_SelectedIndexChanged" TabIndex="12">
                        <asp:ListItem Value="default">Choose action</asp:ListItem>
                        <asp:ListItem Value="StandardDeviation">StandardDeviation</asp:ListItem>
                        <asp:ListItem Value="Mean">Mean</asp:ListItem>
                        <asp:ListItem Value="Median">Median</asp:ListItem>
                        <asp:ListItem Value="Correlation">Correlation</asp:ListItem>
                        <asp:ListItem Value="RankCorrelation">RankCorrelation</asp:ListItem>
                        <asp:ListItem Value="PercentileBounds">PercentileBounds</asp:ListItem>
                        <asp:ListItem Value="ValsToCSV">ValsToCSV</asp:ListItem>
                        <asp:ListItem Value="Histogramize">Histogramize..CSV</asp:ListItem>
                        <asp:ListItem Value="Regression">Regression..CSV</asp:ListItem>
                        <asp:ListItem Value="RegressionPercentiles">RegressionPercentiles..CSV</asp:ListItem>
                        <asp:ListItem Value="Comment">Comment</asp:ListItem>
                    </asp:DropDownList>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblQueryParams1" runat="server" Font-Size="Large"></asp:Label>
                    <asp:Label ID="lblCommentQuery" Text="comment" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:DropDownList ID="ddlQueryParams1" runat="server" Height="30px" Width="150px" TabIndex="13">
                    </asp:DropDownList>
                    <asp:TextBox ID="textCommentQuery" runat="server" Width="500px" TabIndex="4">
                    </asp:TextBox>
                    <asp:RequiredFieldValidator ID="reqFieldValidator_ddlQueryParams1" runat="server" 
                        ControlToValidate="ddlQueryParams1" 
                        ErrorMessage="Parameter names must be added in Step 2 before adding query actions." 
                        ValidationGroup="Validators_queryActions" SetFocusOnError="True">*</asp:RequiredFieldValidator>
                    <asp:Label ID="lblQueryParamsCbl" Text="choose parameter(s)" runat="server" Font-Size="Large"></asp:Label>
                    <asp:CheckBoxList ID="cblQueryParams1" runat="server" Height="30px" Width="180px" TabIndex="13">
                    </asp:CheckBoxList>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblQueryParams2" Text="choose parameter" runat="server" Font-Size="Large"></asp:Label>
                    <asp:Label ID="lblPercentiles" Text="percentiles" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:DropDownList ID="ddlQueryParams2" runat="server" Height="30px" Width="150px" TabIndex="14">
                    </asp:DropDownList>
                    <asp:TextBox ID="textPercentiles" runat="server" Width="150px" TabIndex="14">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_percentiles" runat="server"
                        ControlToValidate="textPercentiles"
                        ErrorMessage="List percentile values separated by commas."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validatePercentiles" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td>
                    <asp:Label ID="lblQueryExpression" Text="function of params and T" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textQueryExpression" runat="server" Width="300px" TabIndex="13">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_queryExpression" runat="server"
                        ControlToValidate="textQueryExpression"
                        ErrorMessage="Assignment expressions and regression expressions are identical except in one regard: regression functions should involve the free-variable 'T' and assignment functions should not. Outside of these restrictions, a valid expression can be any well-formed expression involving defined parameter names, numbers, constants (e and pi), parentheses, +, -, *, /, ^, log10, and ln."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validateExpression" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
            <tr>
                <td></td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblQueryArg1" Text="" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textQueryArg1" runat="server" Width="120px" TabIndex="20">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_queryArg1" runat="server"
                        ControlToValidate="textQueryArg1"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_percent" runat="server"
                        ControlToValidate="textQueryArg1"
                        ErrorMessage="The percent value should be a real number 0 to 100."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validatePercent" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_posInt" runat="server"
                        ControlToValidate="textQueryArg1"
                        ErrorMessage="The value should be a positive integer."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validatePosInt" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CompareValidator ID="compareValidator_tStart_tFinish" runat="server" 
                        ControlToValidate="textQueryArg2" ControlToCompare="textQueryArg1" Operator="GreaterThan" SetFocusOnError="True" ErrorMessage="tFinish must be greater than tStart."
                        ValidationGroup="Validators_queryActions" Type="Double">*</asp:CompareValidator>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblQueryArg2" Text="" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textQueryArg2" runat="server" Width="120px" TabIndex="20">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_queryArg2" runat="server"
                        ControlToValidate="textQueryArg2"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_percent2" runat="server"
                        ControlToValidate="textQueryArg2"
                        ErrorMessage="The percent value should be a real number 0 to 100."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validatePercent" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
                <td style="padding-right: 20px;">
                    <asp:Label ID="lblQueryArg3" Text="" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textQueryArg3" runat="server" Width="120px" TabIndex="20">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_queryArg3" runat="server"
                        ControlToValidate="textQueryArg3"
                        ErrorMessage="The value should be any real number."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validateArg1" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                    <asp:CustomValidator ID="customValidator_posInt3" runat="server"
                        ControlToValidate="textQueryArg3"
                        ErrorMessage="The value should be a positive integer."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validatePosInt" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="btnAddQuery" runat="server" CssClass="btn btn-default" Text="Add Query" OnClick="btnAddQuery_Click" ValidationGroup="Validators_queryActions" TabIndex="40" />&nbsp;&nbsp;
                        <a href="#" onclick="helpAlert('MainContent_ddlQueryActions')">
                            <asp:Image ID="imgHelpQuery" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a>
                </td>
                <td></td>
                <td>
                    <asp:Label ID="lblFileName" Text="file name" runat="server" Font-Size="Large"></asp:Label><br />
                    <asp:TextBox ID="textFileName" runat="server" Width="150px" TabIndex="30">
                    </asp:TextBox>
                    <asp:CustomValidator ID="customValidator_fileName" runat="server"
                        ControlToValidate="textFileName"
                        ErrorMessage="Enter a file name without spaces. The first character should be a letter."
                        ValidationGroup="Validators_queryActions" ClientValidationFunction="validateFileName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
                </td>
            </tr>
        </table>
        <p>
            <br />
            <asp:Label ID="lblQueryActions" Text="File preview for query actions" runat="server" Font-Size="Large"></asp:Label>&nbsp;&nbsp;
            <a href="#" onclick="helpAlert('help_textBoxFile')">
                <asp:Image ID="help_imgFile2" runat="server" ImageUrl="images/help-about-icon.png" AlternateText="help" /></a><br />
            <asp:TextBox ID="textFileQueryActions" Text="" Font-Names="Courier New" runat="server" Width="600px" Wrap="False" TextMode="MultiLine" Height="150px"></asp:TextBox>
        </p>

        <asp:ValidationSummary ID="ValidationSummary1" runat="server" ShowMessageBox="True"
            ValidationGroup="AllValidators" ShowSummary="False" />
        <asp:ValidationSummary ID="ValidationSummary_ParameterActions" runat="server" ShowMessageBox="True"
            ValidationGroup="Validators_parameterActions" ShowSummary="False" />
        <asp:ValidationSummary ID="ValidationSummary_QueryActions" runat="server" ShowMessageBox="True"
            ValidationGroup="Validators_queryActions" ShowSummary="False" />
        <br />
    </div>

    <p>
        <asp:TextBox ID="textInputFileName" runat="server" Width="180px" TabIndex="45"></asp:TextBox>
        <asp:Label ID="lblInputFileName" Text="file name for SUE input file" runat="server" Font-Size="Large"></asp:Label>
        <asp:CustomValidator ID="customValidator_inputFileName" runat="server"
                        ControlToValidate="textInputFileName"
                        ErrorMessage="Enter a file name without spaces. The first character should be a letter."
                        ValidationGroup="AllValidators" ClientValidationFunction="validateFileName" SetFocusOnError="True" ValidateEmptyText="True">*</asp:CustomValidator>
    </p>
    <p>
        <asp:Button ID="btnBuild" runat="server" CssClass="btn btn-default" OnClick="btnBuild_Click" Text="Download Input File" ValidationGroup="AllValidators" TabIndex="50" />
        &nbsp;&nbsp;&nbsp;*NOTE: Save the downloaded files in a new directory and run the .bat file to start SUE.
    </p><p>
        <asp:Button ID="btnStep3" runat="server" CssClass="btn btn-default" Text="Continue to the next step" ValidationGroup="AllValidators" TabIndex="51" PostBackUrl="~/runSUE.aspx" />
    </p>
    <p>&nbsp;</p>
    <p>SUE was developed by Jimm Domingo and Justin Goodman at the Oregon State University <a href="http://www.forestry.oregonstate.edu/">College of Forestry</a> (2002-2004) <br />under the direction of Dr. Mark Harmon</p>
    <p>Source code for SUE can be found on it's <a href="https://github.com/geoSpacer/SUE">gitHub</a> site</p>

</asp:Content>
