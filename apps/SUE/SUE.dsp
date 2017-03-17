# Microsoft Developer Studio Project File - Name="SUE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=SUE - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SUE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SUE.mak" CFG="SUE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SUE - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "SUE - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SUE - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\..\..\libs\include\common\2.0" /I "C:\Program Files\Parser Generator 2\Cpp\Include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 yl.lib common_2.0-rc1.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /libpath:"C:\local\soft-dev\libs\Release" /libpath:"C:\Program Files\Parser Generator 2\Cpp\Lib\msvc32"
# Begin Special Build Tool
OutDir=.\Release
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c buildDate.cpp
# End Special Build Tool

!ELSEIF  "$(CFG)" == "SUE - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\..\..\libs\include\common\2.0" /I "C:\Program Files\Parser Generator 2\Cpp\Include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "YYDEBUG" /FD /GZ /c
# SUBTRACT CPP /X /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 yld.lib common_2.0-rc1.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"libc" /pdbtype:sept /libpath:"C:\local\soft-dev\libs\Debug" /libpath:"C:\Program Files\Parser Generator 2\Cpp\Lib\msvc32"
# SUBTRACT LINK32 /nodefaultlib
# Begin Special Build Tool
OutDir=.\Debug
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c buildDate.cpp
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "SUE - Win32 Release"
# Name "SUE - Win32 Debug"
# Begin Group "main, cmd-line args, prog info"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\buildDate.cpp
# End Source File
# Begin Source File

SOURCE=.\buildDate.h
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\pragmas.h
# End Source File
# Begin Source File

SOURCE=.\process_cmd_line.cpp
# End Source File
# Begin Source File

SOURCE=.\process_cmd_line.h
# End Source File
# Begin Source File

SOURCE=.\prog_parms.cpp
# End Source File
# Begin Source File

SOURCE=.\prog_parms.h
# End Source File
# Begin Source File

SOURCE=.\progInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\progInfo.h
# End Source File
# Begin Source File

SOURCE=.\version.cpp
# End Source File
# End Group
# Begin Group "parser"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\parser\Action_Lexer.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\Action_Lexer.h
# End Source File
# Begin Source File

SOURCE=.\parser\Action_Lexer.inl
# End Source File
# Begin Source File

SOURCE=.\parser\error_mesgs.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\parser\error_states.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\parser\myparser.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\myparser.h
# End Source File
# Begin Source File

SOURCE=.\parser\myparser.v

!IF  "$(CFG)" == "SUE - Win32 Release"

# Begin Custom Build
InputPath=.\parser\myparser.v

BuildCmds= \
	C:\local\\Perl\bin\perl.exe  parser\make_error_mesgs.pl parser\error_mesgs.c parser\error_states.c < $(InputPath)

"parser\error_mesgs.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"parser\error_states.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "SUE - Win32 Debug"

# Begin Custom Build
InputPath=.\parser\myparser.v

BuildCmds= \
	C:\local\\Perl\bin\perl.exe  parser\make_error_mesgs.pl parser\error_mesgs.c parser\error_states.c < $(InputPath)

"parser\error_mesgs.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"parser\error_states.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\parser\myparser.y
# End Source File
# Begin Source File

SOURCE=.\parser\parse_action.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\parse_action.h
# End Source File
# Begin Source File

SOURCE=.\parser\Parser_Error.h
# End Source File
# Begin Source File

SOURCE=.\parser\Parser_Error.inl
# End Source File
# Begin Source File

SOURCE=.\parser\parser_impl.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\parser_impl.h
# End Source File
# End Group
# Begin Group "computation engine"

# PROP Default_Filter ""
# Begin Group "actions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Action.cpp
# End Source File
# Begin Source File

SOURCE=.\Action.h
# End Source File
# Begin Source File

SOURCE=.\actions.h
# End Source File
# Begin Source File

SOURCE=.\AssignFromEquationAction.cpp
# End Source File
# Begin Source File

SOURCE=.\AssignFromEquationAction.h
# End Source File
# Begin Source File

SOURCE=.\CorrelationAction.cpp
# End Source File
# Begin Source File

SOURCE=.\CorrelationAction.h
# End Source File
# Begin Source File

SOURCE=.\HistogramAction.cpp
# End Source File
# Begin Source File

SOURCE=.\HistogramAction.h
# End Source File
# Begin Source File

SOURCE=.\MeanAction.cpp
# End Source File
# Begin Source File

SOURCE=.\MeanAction.h
# End Source File
# Begin Source File

SOURCE=.\MedianAction.cpp
# End Source File
# Begin Source File

SOURCE=.\MedianAction.h
# End Source File
# Begin Source File

SOURCE=.\NegExpAction.cpp
# End Source File
# Begin Source File

SOURCE=.\NegExpAction.h
# End Source File
# Begin Source File

SOURCE=.\NormalAction.cpp
# End Source File
# Begin Source File

SOURCE=.\NormalAction.h
# End Source File
# Begin Source File

SOURCE=.\NormalBivariatesAction.cpp
# End Source File
# Begin Source File

SOURCE=.\NormalBivariatesAction.h
# End Source File
# Begin Source File

SOURCE=.\PercentileBoundsAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PercentileBoundsAction.h
# End Source File
# Begin Source File

SOURCE=.\rankCorrelateAction.cpp
# End Source File
# Begin Source File

SOURCE=.\rankCorrelateAction.h
# End Source File
# Begin Source File

SOURCE=.\rankCorrelationAction.cpp
# End Source File
# Begin Source File

SOURCE=.\rankCorrelationAction.h
# End Source File
# Begin Source File

SOURCE=.\RegressionAction.cpp
# End Source File
# Begin Source File

SOURCE=.\RegressionAction.h
# End Source File
# Begin Source File

SOURCE=.\RegressionPercentilesAction.cpp
# End Source File
# Begin Source File

SOURCE=.\RegressionPercentilesAction.h
# End Source File
# Begin Source File

SOURCE=.\StandardDeviationAction.cpp
# End Source File
# Begin Source File

SOURCE=.\StandardDeviationAction.h
# End Source File
# Begin Source File

SOURCE=.\TriangularAction.cpp
# End Source File
# Begin Source File

SOURCE=.\TriangularAction.h
# End Source File
# Begin Source File

SOURCE=.\UniformAction.cpp
# End Source File
# Begin Source File

SOURCE=.\UniformAction.h
# End Source File
# Begin Source File

SOURCE=.\ValsToCSVAction.cpp
# End Source File
# Begin Source File

SOURCE=.\ValsToCSVAction.h
# End Source File
# End Group
# Begin Group "distributions"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\distributionTypes.h
# End Source File
# Begin Source File

SOURCE=.\DistTyp.cpp
# End Source File
# Begin Source File

SOURCE=.\distTyp.h
# End Source File
# Begin Source File

SOURCE=.\NegExp.cpp
# End Source File
# Begin Source File

SOURCE=.\negExp.h
# End Source File
# Begin Source File

SOURCE=.\Normal.cpp
# End Source File
# Begin Source File

SOURCE=.\normal.h
# End Source File
# Begin Source File

SOURCE=.\Triangular.cpp
# End Source File
# Begin Source File

SOURCE=.\triangular.h
# End Source File
# Begin Source File

SOURCE=.\Uniform.cpp
# End Source File
# Begin Source File

SOURCE=.\uniform.h
# End Source File
# End Group
# Begin Group "computed variables"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Command.cpp
# End Source File
# Begin Source File

SOURCE=.\Command.h
# End Source File
# Begin Source File

SOURCE=.\Command.inl
# End Source File
# Begin Source File

SOURCE=.\Command_Code.cpp
# End Source File
# Begin Source File

SOURCE=.\Command_Code.h
# End Source File
# Begin Source File

SOURCE=.\command_codes.h
# End Source File
# Begin Source File

SOURCE=.\Command_Sequence.h
# End Source File
# Begin Source File

SOURCE=.\execute_cmd_seq.cpp
# End Source File
# Begin Source File

SOURCE=.\execute_cmd_seq.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ComputationEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationEngine.h
# End Source File
# Begin Source File

SOURCE=.\correlationStuff.cpp
# End Source File
# Begin Source File

SOURCE=.\correlationStuff.h
# End Source File
# Begin Source File

SOURCE=.\vectorOps.cpp
# End Source File
# Begin Source File

SOURCE=.\vectorOps.h
# End Source File
# End Group
# End Target
# End Project
