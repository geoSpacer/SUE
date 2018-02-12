<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <img style="float:right" src="images/uncertaintyImage.jpg" />
        <h1>Stochastic Uncertainty Estimator</h1>
        <p class="lead">SUE is a scientific tool to simulate the uncertainty in a given mathematical relationship. It utilizes Monte Carlo methods to simulate repeated samplings from an input distribution.</p>
        <p><a href="SUEguide.aspx" class="btn btn-primary btn-lg">Learn more &raquo;</a></p>
    </div>

    <div class="row">
        <div class="col-md-4">
            <h2>Step 1 - Download SUE</h2>
            <p>
                Pull the current compiled version of SUE to your local windows PC. This is the SUE executable.
                Create a directory on your local C: drive called 'SUE' and save the SUE.exe file in that directory.
            </p>
            <p>
                <a class="btn btn-default" href="Download\SUE.exe">Download SUE &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>Step 2 - Build Input</h2>
            <p>
                Enter parameters for SUE to run <a href="download\test_params.txt">(view example file)</a>. The input file consists of initialization, parameter, and query actions.
                Each tool has an information icon where you can learn how the tool works, and actions are added to the file preview as they are entered and validated.
                When all the actions have been entered, click Download Input File and save the input file and it's .bat file in a new directory on your local computer.
            </p>
            <p>
                <a class="btn btn-default" href="inputBuilder.aspx">Make input file &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>Step 3 - Run SUE</h2>
            <p>
                To run SUE, double click the .bat file, and output will be saved to 'SUE_output.txt'. For detailed instructions click Run SUE.
            </p>
            <p>
                <a class="btn btn-default" href="runSUE.aspx">Run SUE &raquo;</a>
            </p>
        </div>
    </div>
    

</asp:Content>
