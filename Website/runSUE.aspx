<%@ Page Title="Run the Uncertainty Estimator" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="runSUE.aspx.cs" Inherits="runSUE" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <h2><%: Title %></h2>
    <table>
        <tr>
            <td style="vertical-align: top; padding-right:10px">
                <h3>1. Download SUE</h3>
                <p>
                    Create a directory on your C: drive called SUE. Download the <a href="Download\SUE.exe">Stocastic Uncertainty Estimator</a>, and save it in C:\SUE\SUE.exe.
                </p>

            </td>
            <td style="padding-bottom: 10px;">
                <img src="images/runSUE_step1_v2.jpg" />
            </td>
        </tr>
        <tr>
            <td style="vertical-align: top; padding-right:10px"">
                <h3>2. Build and download the SUE input file</h3>
                <p>
                   After <a href="inputBuilder.aspx">building an input file and downloading the zip file</a>, save the files in the zip in a new directory. This directory will be your working directory for this SUE run.
                </p>

            </td>
            <td style="padding-bottom: 10px;">
                <img src="images/runSUE_step2_v2.jpg" />
            </td>
        </tr>
        <tr>
            <td style="vertical-align: top; padding-right:10px"">
                <h3>3. Start SUE</h3>
                <p>
                    To start SUE double click on the .bat file. Output from SUE will be saved to a file called SUE_Output_[your input file name].txt.
                    Named output files from the input parameters will also appear in the same directory as the .bat file.
                </p>

            </td>
            <td style="padding-bottom: 10px;">
                <img src="images/runSUE_step3_v2.jpg" />
            </td>
        </tr>
    </table>
    <h3>4. View Output</h3>
    <img src="images/runSUE_step4_v2.jpg" />
    <p>&nbsp;</p>

    <p>SUE was developed by Jimm Domingo and Justin Goodman at the Oregon State University <a href="http://www.forestry.oregonstate.edu/">College of Forestry</a> (2002-2004) <br />under the direction of Dr. Mark Harmon</p>
    <p>Source code for SUE can be found on it's <a href="https://github.com/geoSpacer/SUE">gitHub</a> site</p>

</asp:Content>
