using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
// using System.Diagnostics;
using Ionic.Zip; //DotNetZip

public partial class inputBuilder : Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            ddlQueryParams1.Items.Clear();
            clearParameterFields();
            clearQueryFields();
            textFileParameterActions.Text = "";
            textFileQueryActions.Text = "";

            ddlParameterActions.SelectedIndex = ddlParameterActions.Items.IndexOf(ddlParameterActions.Items.FindByValue("default"));
        }
    }

    protected void btnBuild_Click(object sender, EventArgs e)
    {
        // check if file name ends with .txt and fix if necessary
        int startIndex = textInputFileName.Text.IndexOf(".");
        if (startIndex > 0)
        {
            textInputFileName.Text = textInputFileName.Text.Substring(0, startIndex);
        } 

        string inputFileName = "Download\\" + textInputFileName.Text + ".txt";
        string batFileName = "Download\\" + textInputFileName.Text + ".bat";

        // get the physical folder; currently on Charcoal
        string appPath = Request.PhysicalApplicationPath;
        using (StreamWriter sw = new StreamWriter(appPath + inputFileName))
        {
            sw.WriteLine(">-------------------------------------------------");
            sw.WriteLine(">Stochastic Uncertainty Estimator (SUE) Input file");
            sw.WriteLine(">Run built on " + DateTime.Now.Date.ToString() + "  " + DateTime.Now.TimeOfDay.ToString());
            sw.WriteLine(">-------------------------------------------------");
            sw.WriteLine("");
            sw.WriteLine("Seed " + textSeedVal.Text);
            sw.WriteLine("");
            sw.WriteLine("SampleSpaceSize " + textSampleSpaceSize.Text);
            sw.WriteLine("");
            sw.Write(textFileParameterActions.Text);
            sw.Write(textFileQueryActions.Text);
        }

        // write .bat file to go with input file
        using (StreamWriter sw2 = new StreamWriter(appPath + batFileName))
        {
            sw2.WriteLine("@echo off");
            sw2.WriteLine("C:/SUE/SUE.exe " + textInputFileName.Text + ".txt > SUE_Output_" + textInputFileName.Text + ".txt");
            sw2.WriteLine("pause");
        }

        try
        {
            using (ZipFile outputZipFile = new ZipFile())
            {

                // note: this does not recurse directories! 
                //string[] filenames = System.IO.Directory.GetFiles(userDirectory.Value + "\\OutputFiles", "*");
                //outputZipFile.AddDirectory(userDirectory.Value, runName.Value);
                outputZipFile.AddFile(appPath + inputFileName,"");
                outputZipFile.AddFile(appPath + batFileName,"");
                outputZipFile.Comment = "Added by the Stochastic Uncertainty Estimator (SUE)";

                // This is just a sample, provided to illustrate the DotNetZip interface.  
                // This logic does not recurse through sub-directories.
                // If you are zipping up a directory, you may want to see the AddDirectory() method, 
                // which operates recursively. 
                // foreach (String filename in filenames)
                // {
                // Console.WriteLine("Adding {0}...", filename);
                //    ZipEntry e = outputZipFile.AddFile(filename);
                //    e.Comment = "Added by the Forest Sector Carbon Calculator";
                // }

                // outputZipFile.Comment = String.Format("This zip archive was created by the CreateZip example application on machine '{0}'",
                //   System.Net.Dns.GetHostName());

                outputZipFile.Save(appPath + "Download\\" + textInputFileName.Text + ".zip");
            }

        }
        catch (System.Exception ex1)
        {
            System.Console.Error.WriteLine("exception: " + ex1);
        }


        // download output file
        Response.ContentType = "application/x-zip-compressed";
        Response.AppendHeader("Content-Disposition", "attachment; filename=" + textInputFileName.Text + ".zip");
        Response.TransmitFile(appPath + "Download\\" + textInputFileName.Text + ".zip");
        Response.End();

        // return to home page
        // Response.Redirect("Default.aspx", true);
    }

    protected void ddlParameterActions_SelectedIndexChanged(object sender, EventArgs e)
    {
        clearParameterFields();
        clearQueryFields();
        ddlQueryActions.SelectedIndex = ddlQueryActions.Items.IndexOf(ddlQueryActions.Items.FindByValue("default"));

        if (ddlParameterActions.SelectedItem.Text == "Uniform")
        {
            lblParameterName.Visible = true;
            lblArg1.Visible = true;
            lblArg2.Visible = true;
            textParameterName.Visible = true;
            textArg1.Visible = true;
            textArg2.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_arg2.Visible = true;
            compareValidator_lowerUpper.Visible = true;

            lblArg1.Text = "lowerBound";
            lblArg2.Text = "upperBound";
        }
        else if (ddlParameterActions.SelectedItem.Text == "Triangular")
        {
            lblParameterName.Visible = true;
            lblArg1.Visible = true;
            lblArg2.Visible = true;
            textParameterName.Visible = true;
            textArg1.Visible = true;
            textArg2.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_arg2.Visible = true;
            lblArg3.Visible = true;
            textArg3.Visible = true;
            customValidator_arg3.Visible = true;
            compareValidator_lowerUpper.Visible = true;
            customValidator_mode.Visible = true;

            lblArg1.Text = "lowerBound";
            lblArg2.Text = "upperBound";
            lblArg3.Text = "mode";
        }
        else if (ddlParameterActions.SelectedItem.Text == "NegativeExponential")
        {
            lblParameterName.Visible = true;
            lblArg1.Visible = true;
            lblArg2.Visible = true;
            textParameterName.Visible = true;
            textArg1.Visible = true;
            textArg2.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_arg2.Visible = true;
            customValidator_SD.Visible = true;

            lblArg1.Text = "lowerBound";
            lblArg2.Text = "standardDeviation";
        }
        else if (ddlParameterActions.SelectedItem.Text == "Normal")
        {
            lblParameterName.Visible = true;
            lblArg1.Visible = true;
            lblArg2.Visible = true;
            textParameterName.Visible = true;
            textArg1.Visible = true;
            textArg2.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_arg2.Visible = true;
            customValidator_SD.Visible = true;

            lblArg1.Text = "mode";
            lblArg2.Text = "standardDeviation";
        }
        else if (ddlParameterActions.SelectedItem.Text == "NormalBivariates")
        {
            lblParameterName.Visible = true;
            lblParameter2.Visible = true;
            lblArg1.Visible = true;
            lblArg2.Visible = true;
            lblArg3.Visible = true;
            lblArg4.Visible = true;
            lblArg5.Visible = true;
            textParameterName.Visible = true;
            textParameter2.Visible = true;
            textArg1.Visible = true;
            textArg2.Visible = true;
            textArg3.Visible = true;
            textArg4.Visible = true;
            textArg5.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_parameter2.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_arg2.Visible = true;
            customValidator_arg3.Visible = true;
            customValidator_arg4.Visible = true;
            customValidator_arg5.Visible = true;
            customValidator_corr.Visible = true;
            customValidator_SD3.Visible = true;
            customValidator_SD5.Visible = true;

            lblArg1.Text = "correlation";
            lblArg2.Text = "param1mode";
            lblArg3.Text = "param1stdDev";
            lblArg4.Text = "param2mode";
            lblArg5.Text = "param2stdDev";
        }
        else if (ddlParameterActions.SelectedItem.Text == "rankCorrelate")
        {
            lblParameterName.Visible = true;
            textParameterName.Visible = true;
            customValidator_ParameterName.Visible = true;
            customValidator_existParameterName.Visible = true;

            lblParameter2.Visible = true;
            textParameter2.Visible = true;
            customValidator_parameter2.Visible = true;
            customValidator_existParameterName2.Visible = true;

            lblArg1.Visible = true;
            textArg1.Visible = true;
            customValidator_arg1.Visible = true;
            customValidator_corr.Visible = true;

            lblMethod.Visible = true;
            ddlMethod.Visible = true;

            lblParameterName.Text = "param1";
            lblParameter2.Text = "param2";
            lblArg1.Text = "rankCorr";

            // turn on query params 1 to access list of params
            ddlQueryParams1.Visible = true;
        }
        else if (ddlParameterActions.SelectedItem.Text == "Expression")
        {
            lblParameterName.Visible = true;
            textParameterName.Visible = true;
            customValidator_ParameterName.Visible = true;
            lblExpression.Visible = true;
            textExpression.Visible = true;
            customValidator_expression.Visible = true;

            // turn on query params 1 to access list of params
            ddlQueryParams1.Visible = true;
        }
        else if (ddlParameterActions.SelectedItem.Text == "Comment")
        {
            lblCommentParam.Visible = true;
            textCommentParam.Visible = true;
        }
    }

    protected void clearParameterFields()
    {
        lblParameterName.Text = "parameter name";
        textParameterName.Text = "";
        textParameter2.Text = "";
        textArg1.Text = "";
        textArg2.Text = "";
        textArg3.Text = "";
        textArg4.Text = "";
        textArg5.Text = "";
        textExpression.Text = "";
        textCommentParam.Text = "";

        lblParameterName.Visible = false;
        lblParameter2.Visible = false;
        lblArg1.Visible = false;
        lblArg2.Visible = false;
        lblArg3.Visible = false;
        lblArg4.Visible = false;
        lblArg5.Visible = false;
        lblExpression.Visible = false;
        lblMethod.Visible = false;
        lblCommentParam.Visible = false;

        textParameterName.Visible = false;
        textParameter2.Visible = false;
        textArg1.Visible = false;
        textArg2.Visible = false;
        textArg3.Visible = false;
        textArg4.Visible = false;
        textArg5.Visible = false;
        textExpression.Visible = false;
        ddlMethod.Visible = false;
        textCommentParam.Visible = false;

        customValidator_ParameterName.Visible = false;
        customValidator_parameter2.Visible = false;
        customValidator_arg1.Visible = false;
        customValidator_arg2.Visible = false;
        customValidator_arg3.Visible = false;
        customValidator_arg4.Visible = false;
        customValidator_arg5.Visible = false;
        customValidator_expression.Visible = false;
        compareValidator_lowerUpper.Visible = false;
        customValidator_mode.Visible = false;
        customValidator_SD.Visible = false;
        customValidator_SD3.Visible = false;
        customValidator_SD5.Visible = false;
        customValidator_corr.Visible = false;
        customValidator_existParameterName.Visible = false;
        customValidator_existParameterName2.Visible = false;
    }

    protected void clearQueryFields()
    {
        textQueryArg1.Text = "";
        textQueryArg2.Text = "";
        textQueryArg3.Text = "";
        textFileName.Text = "";
        textExpression.Text = "";
        textPercentiles.Text = "";
        textCommentQuery.Text = "";
        lblQueryParams1.Text = "choose parameter";
        textQueryExpression.Text = "";

        lblQueryParams1.Visible = false;
        lblQueryParams2.Visible = false;
        lblCommentQuery.Visible = false;
        lblQueryParamsCbl.Visible = false;
        lblQueryExpression.Visible = false;
        lblFileName.Visible = false;
        lblPercentiles.Visible = false;
        lblQueryArg1.Visible = false;
        lblQueryArg2.Visible = false;
        lblQueryArg3.Visible = false;

        ddlQueryParams1.Visible = false;
        ddlQueryParams2.Visible = false;
        cblQueryParams1.Visible = false;

        textQueryExpression.Visible = false;
        textFileName.Visible = false;
        textPercentiles.Visible = false;
        textCommentQuery.Visible = false;
        textQueryArg1.Visible = false;
        textQueryArg2.Visible = false;
        textQueryArg3.Visible = false;

        customValidator_queryArg1.Visible = false;
        customValidator_queryArg2.Visible = false;
        customValidator_queryArg3.Visible = false;
        customValidator_expression.Visible = false;
        customValidator_percentiles.Visible = false;
        customValidator_fileName.Visible = false;
        reqFieldValidator_ddlQueryParams1.Visible = false;
        customValidator_percent.Visible = false;
        customValidator_percent2.Visible = false;
        customValidator_posInt.Visible = false;
        customValidator_posInt3.Visible = false;
        compareValidator_tStart_tFinish.Visible = false;
    }

    protected void btnAddParameter_Click(object sender, EventArgs e)
    {
        if (ddlParameterActions.SelectedItem.Text == "Uniform" || ddlParameterActions.SelectedItem.Text == "NegativeExponential" || ddlParameterActions.SelectedItem.Text == "Normal")
        {
            textFileParameterActions.Text += textParameterName.Text + " = " + ddlParameterActions.SelectedItem.Text + "(" + textArg1.Text + ", " + textArg2.Text + ")\n";
        }
        else if (ddlParameterActions.SelectedItem.Text == "Triangular")
        {
            textFileParameterActions.Text += textParameterName.Text + " = " + ddlParameterActions.SelectedItem.Text + "(" + textArg1.Text + ", " + textArg3.Text + ", " + textArg2.Text + ")\n";
        }
        else if (ddlParameterActions.SelectedItem.Text == "rankCorrelate")
        {
            textFileParameterActions.Text += ddlParameterActions.SelectedItem.Text + "(" + textParameterName.Text + ", " + textParameter2.Text + ", " + textArg1.Text + ", " + ddlMethod.SelectedItem.Text + ")\n";
        }
        else if (ddlParameterActions.SelectedItem.Text == "NormalBivariates")
        {
            textFileParameterActions.Text += textParameterName.Text + ", " + textParameter2.Text + " = " + ddlParameterActions.SelectedItem.Text + "(" + textArg1.Text + ", " + textArg2.Text + ", " + textArg3.Text + ", " + textArg4.Text + ", " + textArg5.Text + ")\n";
        }
        else if (ddlParameterActions.SelectedItem.Text == "Expression")
        {
            textFileParameterActions.Text += textParameterName.Text + " = " + textExpression.Text + "\n";
        }
        else if (ddlParameterActions.SelectedItem.Text == "Comment")
        {
            textFileParameterActions.Text += ">" + textCommentParam.Text + "\n";
        }

        // load parameter values into ddl for query
        if (textParameterName.Visible == true)
        {
            if (ddlQueryParams1.Items.FindByText(textParameterName.Text) == null)
            {
                ddlQueryParams1.Items.Add(new ListItem(textParameterName.Text));
            }
        }
        if (textParameter2.Visible == true)
        {
            if (ddlQueryParams1.Items.FindByText(textParameter2.Text) == null)
            {
                ddlQueryParams1.Items.Add(new ListItem(textParameter2.Text));
            }
        }
    }

    protected void btnAddQuery_Click(object sender, EventArgs e)
    {
        if (textFileName.Visible)
        {
            // check if file name ends with .csv and fix if necessary
            int startIndex = textFileName.Text.IndexOf(".");
            if (startIndex > 0)
            {
                textFileName.Text = textFileName.Text.Substring(0, startIndex) + ".csv";
            } else {
                textFileName.Text += ".csv";
            }
        }

        if (ddlQueryActions.SelectedItem.Value == "StandardDeviation" || ddlQueryActions.SelectedItem.Value == "Mean" || ddlQueryActions.SelectedItem.Value == "Median")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + ddlQueryParams1.SelectedItem.Text + ")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "Correlation" || ddlQueryActions.SelectedItem.Value == "RankCorrelation")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + ddlQueryParams1.SelectedItem.Text + ", " + ddlQueryParams2.SelectedItem.Text + ")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "PercentileBounds")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + ddlQueryParams1.SelectedItem.Text + ", " + textQueryArg1.Text + ")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "ValsToCSV")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(";
            foreach (ListItem paramList in cblQueryParams1.Items)
            {
                if (paramList.Selected)
                {
                    textFileQueryActions.Text += paramList.Text + ", ";
                }
            }

            textFileQueryActions.Text += "\"" + textFileName.Text + "\")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "Histogramize")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + ddlQueryParams1.SelectedItem.Text + ", " + textQueryArg1.Text + ", " + textQueryArg2.Text + ", " + "\"" + textFileName.Text + "\")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "Regression")
        {
            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + textQueryExpression.Text + ", " + textQueryArg1.Text + ", " + textQueryArg2.Text + ", " + textQueryArg3.Text + ", " + "\"" + textFileName.Text + "\")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "RegressionPercentiles")
        {
            if (textPercentiles.Text[0] != '(')
            {
                textPercentiles.Text = "(" + textPercentiles.Text;
            }
            if (textPercentiles.Text[textPercentiles.Text.Length - 1] != ')')
            {
                textPercentiles.Text += ")";
            }

            textFileQueryActions.Text += ddlQueryActions.SelectedItem.Value + "(" + textQueryExpression.Text + ", " + textQueryArg1.Text + ", " + textQueryArg2.Text + ", " + textQueryArg3.Text + ", " + textPercentiles.Text + ", " + "\"" + textFileName.Text + "\")\n";
        }
        else if (ddlQueryActions.SelectedItem.Value == "Comment")
        {
            textFileQueryActions.Text += ">" + textCommentQuery.Text + "\n";
        }
    }


    protected void ddlQueryActions_SelectedIndexChanged(object sender, EventArgs e)
    {
        clearQueryFields();
        clearParameterFields();
        ddlParameterActions.SelectedIndex = ddlParameterActions.Items.IndexOf(ddlParameterActions.Items.FindByValue("default"));

        if (ddlQueryActions.SelectedItem.Value == "StandardDeviation" || ddlQueryActions.SelectedItem.Value == "Mean" || ddlQueryActions.SelectedItem.Value == "Median")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            reqFieldValidator_ddlQueryParams1.Visible = true;
        }
        else if (ddlQueryActions.SelectedItem.Value == "Correlation" || ddlQueryActions.SelectedItem.Value == "RankCorrelation")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            reqFieldValidator_ddlQueryParams1.Visible = true;

            lblQueryParams2.Visible = true;
            ddlQueryParams2.Visible = true;
            ddlQueryParams2.Items.Clear();
            foreach (ListItem paramItem in ddlQueryParams1.Items)
            {
                ddlQueryParams2.Items.Add(new ListItem(paramItem.Text));
            }
        }
        else if (ddlQueryActions.SelectedItem.Value == "PercentileBounds")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            reqFieldValidator_ddlQueryParams1.Visible = true;

            lblQueryArg1.Text = "percentile";
            lblQueryArg1.Visible = true;
            textQueryArg1.Visible = true;
            customValidator_queryArg1.Visible = true;
            customValidator_percent.Visible = true;
        }
        else if (ddlQueryActions.SelectedItem.Value == "ValsToCSV")
        {
            lblQueryParamsCbl.Visible = true;
            cblQueryParams1.Visible = true;
            lblFileName.Visible = true;
            textFileName.Visible = true;
            customValidator_fileName.Visible = true;

            cblQueryParams1.Items.Clear();
            foreach (ListItem paramItem in ddlQueryParams1.Items)
            {
                cblQueryParams1.Items.Add(new ListItem(paramItem.Text));
            }

        }
        else if (ddlQueryActions.SelectedItem.Value == "Histogramize")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            reqFieldValidator_ddlQueryParams1.Visible = true;

            lblQueryArg1.Text = "boxes";
            lblQueryArg1.Visible = true;
            textQueryArg1.Visible = true;
            customValidator_queryArg1.Visible = true;

            lblQueryArg2.Text = "excludedTailPercent";
            lblQueryArg2.Visible = true;
            textQueryArg2.Visible = true;
            customValidator_queryArg2.Visible = true;
            customValidator_percent2.Visible = true;
            customValidator_posInt.Visible = true;

            lblFileName.Visible = true;
            textFileName.Visible = true;
            customValidator_fileName.Visible = true;
        }
        else if (ddlQueryActions.SelectedItem.Value == "Regression")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            lblQueryParams1.Text = "parameters";
  
            lblQueryExpression.Visible = true;
            textQueryExpression.Visible = true;
            customValidator_queryExpression.Visible = true;

            lblQueryArg1.Text = "tStart";
            lblQueryArg1.Visible = true;
            textQueryArg1.Visible = true;
            customValidator_queryArg1.Visible = true;
            compareValidator_tStart_tFinish.Visible = true;

            lblQueryArg2.Text = "tFinish";
            lblQueryArg2.Visible = true;
            textQueryArg2.Visible = true;
            customValidator_queryArg2.Visible = true;

            lblQueryArg3.Text = "steps";
            lblQueryArg3.Visible = true;
            textQueryArg3.Visible = true;
            customValidator_queryArg3.Visible = true;
            customValidator_posInt3.Visible = true;

            lblFileName.Visible = true;
            textFileName.Visible = true;
            customValidator_fileName.Visible = true;
        }
        else if (ddlQueryActions.SelectedItem.Value == "RegressionPercentiles")
        {
            lblQueryParams1.Visible = true;
            ddlQueryParams1.Visible = true;
            lblQueryParams1.Text = "parameters";

            lblQueryExpression.Visible = true;
            textQueryExpression.Visible = true;
            customValidator_queryExpression.Visible = true;

            lblQueryArg1.Text = "tStart";
            lblQueryArg1.Visible = true;
            textQueryArg1.Visible = true;
            customValidator_queryArg1.Visible = true;
            compareValidator_tStart_tFinish.Visible = true;

            lblQueryArg2.Text = "tFinish";
            lblQueryArg2.Visible = true;
            textQueryArg2.Visible = true;
            customValidator_queryArg2.Visible = true;

            lblQueryArg3.Text = "steps";
            lblQueryArg3.Visible = true;
            textQueryArg3.Visible = true;
            customValidator_queryArg3.Visible = true;
            customValidator_posInt3.Visible = true;

            lblFileName.Visible = true;
            textFileName.Visible = true;
            customValidator_fileName.Visible = true;

            lblPercentiles.Visible = true;
            textPercentiles.Visible = true;
            customValidator_percentiles.Visible = true;
        }
        else if (ddlQueryActions.SelectedItem.Value == "Comment")
        {
            lblCommentQuery.Visible = true;
            textCommentQuery.Visible = true;
        }
    }
}