# Microsoft Developer Studio Project File - Name="common_lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=common_lib - Win32 Debug_MD
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "common_lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "common_lib.mak" CFG="common_lib - Win32 Debug_MD"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "common_lib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "common_lib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "common_lib - Win32 Release_MD" (based on "Win32 (x86) Static Library")
!MESSAGE "common_lib - Win32 Debug_MD" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "common_lib"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "common_lib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"$(OutDir)/common.lib"
# Begin Special Build Tool
OutDir=.\Release
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c build_date.cpp
# End Special Build Tool

!ELSEIF  "$(CFG)" == "common_lib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"$(OutDir)/common.lib"
# Begin Special Build Tool
OutDir=.\Debug
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c build_date.cpp
# End Special Build Tool

!ELSEIF  "$(CFG)" == "common_lib - Win32 Release_MD"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "common_lib___Win32_Release_MD"
# PROP BASE Intermediate_Dir "common_lib___Win32_Release_MD"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_MD"
# PROP Intermediate_Dir "Release_MD"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GR /GX /O2 /I "include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"$(OutDir)/common.lib"
# ADD LIB32 /nologo /out:"$(OutDir)/common.lib"
# Begin Special Build Tool
OutDir=.\Release_MD
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c build_date.cpp
# End Special Build Tool

!ELSEIF  "$(CFG)" == "common_lib - Win32 Debug_MD"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "common_lib___Win32_Debug_MD"
# PROP BASE Intermediate_Dir "common_lib___Win32_Debug_MD"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_MD"
# PROP Intermediate_Dir "Debug_MD"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /ZI /Od /I "include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "LOCAL_CONFIG" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"$(OutDir)/common.lib"
# ADD LIB32 /nologo /out:"$(OutDir)/common.lib"
# Begin Special Build Tool
OutDir=.\Debug_MD
SOURCE="$(InputPath)"
PreLink_Cmds=cl /Fo$(OutDir)\ /c build_date.cpp
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "common_lib - Win32 Release"
# Name "common_lib - Win32 Debug"
# Name "common_lib - Win32 Release_MD"
# Name "common_lib - Win32 Debug_MD"
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "miscellaneous"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Academic_Free_License.h
# End Source File
# Begin Source File

SOURCE=.\include\info_as_str.h
# End Source File
# Begin Source File

SOURCE=.\include\Inline_Attribute.h
# End Source File
# Begin Source File

SOURCE=.\include\lib_info.h
# End Source File
# Begin Source File

SOURCE=.\include\Release_Type.h
# End Source File
# Begin Source File

SOURCE=.\include\Version_Number.h
# End Source File
# Begin Source File

SOURCE=.\include\Version_Number.inl
# End Source File
# End Group
# Begin Group "assertions and errors"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Assert_That.h
# End Source File
# Begin Source File

SOURCE=.\include\Assertion_Error.h
# End Source File
# Begin Source File

SOURCE=.\include\Assertion_Error.inl
# End Source File
# Begin Source File

SOURCE=.\include\Assertion_Test.h
# End Source File
# Begin Source File

SOURCE=.\include\Error.h
# End Source File
# Begin Source File

SOURCE=.\include\Error.inl
# End Source File
# Begin Source File

SOURCE=.\include\internalErr.h
# End Source File
# End Group
# Begin Group "boolean types"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Enum_With_2_Values.h
# End Source File
# Begin Source File

SOURCE=.\include\Forward_or_Reverse.h
# End Source File
# Begin Source File

SOURCE=.\include\Leave_or_Remove.h
# End Source File
# Begin Source File

SOURCE=.\include\Read_or_Skip.h
# End Source File
# Begin Source File

SOURCE=.\include\Required_or_Optional.h
# End Source File
# Begin Source File

SOURCE=.\include\str_to_bool.h
# End Source File
# Begin Source File

SOURCE=.\include\Truncate_or_Append.h
# End Source File
# End Group
# Begin Group "strings and text"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\all_whitespace.h
# End Source File
# Begin Source File

SOURCE=.\include\all_whitespace.inl
# End Source File
# Begin Source File

SOURCE=.\include\extra_text_after.h
# End Source File
# Begin Source File

SOURCE=.\include\has_whitespace.h
# End Source File
# Begin Source File

SOURCE=.\include\Ignore_Case.h
# End Source File
# Begin Source File

SOURCE=.\include\Ignore_Case.inl
# End Source File
# Begin Source File

SOURCE=.\include\Multi_Line_Text.h
# End Source File
# Begin Source File

SOURCE=.\include\Multi_Line_Text.inl
# End Source File
# Begin Source File

SOURCE=.\include\read_chars.h
# End Source File
# Begin Source File

SOURCE=.\include\replace_macros.h
# End Source File
# Begin Source File

SOURCE=.\include\Str_Equal_Func.h
# End Source File
# Begin Source File

SOURCE=.\include\Str_To_Value.h
# End Source File
# Begin Source File

SOURCE=.\include\trim_whitespace.h
# End Source File
# End Group
# Begin Group "lists, vectors, maps"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\map_merge.h
# End Source File
# Begin Source File

SOURCE=.\include\map_merge.inl
# End Source File
# Begin Source File

SOURCE=.\include\vector_of.h
# End Source File
# End Group
# Begin Group "enumerated types"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Enum_assign.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Circulator.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Circulator.inl
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Circulator_Base.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Contiguous_Sequence.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Sequence.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Vector.h
# End Source File
# Begin Source File

SOURCE=.\include\Enum_Vector.inl
# End Source File
# Begin Source File

SOURCE=.\include\with_each.h
# End Source File
# End Group
# Begin Group "dates and times"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\annual_average.h
# End Source File
# Begin Source File

SOURCE=.\include\Date.h
# End Source File
# Begin Source File

SOURCE=.\include\Date.inl
# End Source File
# Begin Source File

SOURCE=.\include\Date_Time.h
# End Source File
# Begin Source File

SOURCE=.\include\Date_Time.inl
# End Source File
# Begin Source File

SOURCE=.\include\leap_year.h
# End Source File
# Begin Source File

SOURCE=.\include\Month.h
# End Source File
# Begin Source File

SOURCE=.\include\Time_Of_Day.h
# End Source File
# Begin Source File

SOURCE=.\include\Time_Of_Day.inl
# End Source File
# End Group
# Begin Group "numbers"

# PROP Default_Filter ""
# Begin Group "formatting"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Exp_Fmt.h
# End Source File
# Begin Source File

SOURCE=.\include\Exp_Fmt.inl
# End Source File
# Begin Source File

SOURCE=.\include\Fix_Fmt.h
# End Source File
# Begin Source File

SOURCE=.\include\Fix_Fmt.inl
# End Source File
# Begin Source File

SOURCE=.\include\Float_Format.h
# End Source File
# Begin Source File

SOURCE=.\include\Float_Format.inl
# End Source File
# Begin Source File

SOURCE=.\include\format.h
# End Source File
# Begin Source File

SOURCE=.\include\format.inl
# End Source File
# Begin Source File

SOURCE=.\include\Gen_Fmt.h
# End Source File
# Begin Source File

SOURCE=.\include\Gen_Fmt.inl
# End Source File
# Begin Source File

SOURCE=.\include\Int_Fmt.h
# End Source File
# Begin Source File

SOURCE=.\include\Int_Fmt.inl
# End Source File
# Begin Source File

SOURCE=.\include\Leading_Zeroes.h
# End Source File
# Begin Source File

SOURCE=.\include\Numeric_Format.h
# End Source File
# Begin Source File

SOURCE=.\include\Numeric_Format.inl
# End Source File
# Begin Source File

SOURCE=.\include\numeric_formats.h
# End Source File
# Begin Source File

SOURCE=.\include\Sci_Fmt.h
# End Source File
# Begin Source File

SOURCE=.\include\Sci_Fmt.inl
# End Source File
# End Group
# Begin Group "random"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\MTRand.h
# End Source File
# Begin Source File

SOURCE=.\include\Random_Exponential.h
# End Source File
# Begin Source File

SOURCE=.\include\Random_Number.h
# End Source File
# Begin Source File

SOURCE=.\include\Random_Uniform.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\as_percent.h
# End Source File
# Begin Source File

SOURCE=.\include\Default_Epsilon.h
# End Source File
# Begin Source File

SOURCE=.\include\Default_Epsilon.inl
# End Source File
# Begin Source File

SOURCE=.\include\default_precision.h
# End Source File
# Begin Source File

SOURCE=.\include\equal.h
# End Source File
# Begin Source File

SOURCE=.\include\is_decimal_number.h
# End Source File
# Begin Source File

SOURCE=.\include\is_integer.h
# End Source File
# Begin Source File

SOURCE=.\include\numeric_limits.h
# End Source File
# Begin Source File

SOURCE=.\include\numeric_limits.inl
# End Source File
# Begin Source File

SOURCE=.\include\percent.h
# End Source File
# Begin Source File

SOURCE=.\include\Range.h
# End Source File
# Begin Source File

SOURCE=.\include\Range.inl
# End Source File
# Begin Source File

SOURCE=.\include\str_to_float.h
# End Source File
# Begin Source File

SOURCE=.\include\str_to_int.h
# End Source File
# End Group
# Begin Group "program options"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Program_Arguments.h
# End Source File
# Begin Source File

SOURCE=.\include\Program_Option.h
# End Source File
# Begin Source File

SOURCE=.\include\Program_Options.h
# End Source File
# End Group
# Begin Group "files and directories"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\File_Error.h
# End Source File
# Begin Source File

SOURCE=.\include\File_Error.inl
# End Source File
# Begin Source File

SOURCE=.\include\File_Name_And_Desc.h
# End Source File
# Begin Source File

SOURCE=.\include\File_Name_And_Desc.inl
# End Source File
# Begin Source File

SOURCE=.\include\File_Path.h
# End Source File
# Begin Source File

SOURCE=.\include\File_Path.inl
# End Source File
# Begin Source File

SOURCE=.\include\File_Stat.h
# End Source File
# Begin Source File

SOURCE=.\include\File_Stat.inl
# End Source File
# Begin Source File

SOURCE=.\include\File_Type.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Text_File.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Text_File.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Title.h
# End Source File
# Begin Source File

SOURCE=.\include\make_dir.h
# End Source File
# Begin Source File

SOURCE=.\include\no_lines_after.h
# End Source File
# Begin Source File

SOURCE=.\include\Output_File.h
# End Source File
# Begin Source File

SOURCE=.\include\Output_File_With_Entries.h
# End Source File
# Begin Source File

SOURCE=.\include\Output_File_With_Entries.inl
# End Source File
# Begin Source File

SOURCE=.\include\Output_Title.h
# End Source File
# End Group
# Begin Group "standard lib fixes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\min_max.h
# End Source File
# Begin Source File

SOURCE=.\include\void_mem_fun.h
# End Source File
# End Group
# Begin Group "input values & vars"

# PROP Default_Filter ""
# Begin Group "input values"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Input_Formatted_Value.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Formatted_Value.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Bool.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Enum.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Enum.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Enum_List.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Enum_List.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Error.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Error.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Float.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Format_Error.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Format_Error.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Int.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Location.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Location.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Num.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Num.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Str.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Str_List.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Type.h
# End Source File
# Begin Source File

SOURCE=.\include\input_values.h
# End Source File
# End Group
# Begin Group "input vars"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Input_Var.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Bool.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Enum.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Enum.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Enum_List.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Enum_List.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Float.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Int.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Num.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Num.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_Str.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_With_List.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Var_With_List.inl
# End Source File
# Begin Source File

SOURCE=.\include\input_vars.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\Input_Value_error_message.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Line.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_Line.inl
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_read.h
# End Source File
# Begin Source File

SOURCE=.\include\Input_Value_read.inl
# End Source File
# End Group
# Begin Group "output columns"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\Column_Group.h
# End Source File
# Begin Source File

SOURCE=.\include\Column_Group.inl
# End Source File
# Begin Source File

SOURCE=.\include\Column_or_Group.h
# End Source File
# Begin Source File

SOURCE=.\include\Column_or_Group.inl
# End Source File
# Begin Source File

SOURCE=.\include\Float_Column.h
# End Source File
# Begin Source File

SOURCE=.\include\Float_Column.inl
# End Source File
# Begin Source File

SOURCE=.\include\Horizontal_Alignment.h
# End Source File
# Begin Source File

SOURCE=.\include\Int_Column.h
# End Source File
# Begin Source File

SOURCE=.\include\Int_Column.inl
# End Source File
# Begin Source File

SOURCE=.\include\Output_Column.h
# End Source File
# Begin Source File

SOURCE=.\include\Output_Column.inl
# End Source File
# Begin Source File

SOURCE=.\include\output_columns.h
# End Source File
# Begin Source File

SOURCE=.\include\Str_Column.h
# End Source File
# Begin Source File

SOURCE=.\include\Str_Column.inl
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\_sample.h
# End Source File
# End Group
# Begin Group "source code"

# PROP Default_Filter ""
# Begin Group "miscellaneous."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Academic_Free_License.cpp
# End Source File
# Begin Source File

SOURCE=.\build_date.cpp
# End Source File
# Begin Source File

SOURCE=.\build_date.h
# End Source File
# Begin Source File

SOURCE=.\info_as_str.cpp
# End Source File
# Begin Source File

SOURCE=.\lib_info.cpp
# End Source File
# Begin Source File

SOURCE=.\pragmas.h
# End Source File
# Begin Source File

SOURCE=.\Release_Type.cpp
# End Source File
# Begin Source File

SOURCE=.\Version_Number.cpp
# End Source File
# End Group
# Begin Group "assertions and errors."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Assertion_Error.cpp
# End Source File
# Begin Source File

SOURCE=.\Assertion_Test.cpp
# End Source File
# Begin Source File

SOURCE=.\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\internalErr.cpp

!IF  "$(CFG)" == "common_lib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "common_lib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "common_lib - Win32 Release_MD"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "common_lib - Win32 Debug_MD"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "boolean types."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\str_to_bool.cpp
# End Source File
# End Group
# Begin Group "strings and text."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\all_whitespace.cpp
# End Source File
# Begin Source File

SOURCE=.\extra_text_after.cpp
# End Source File
# Begin Source File

SOURCE=.\has_whitespace.cpp
# End Source File
# Begin Source File

SOURCE=.\Ignore_Case.cpp
# End Source File
# Begin Source File

SOURCE=.\Multi_Line_Text.cpp
# End Source File
# Begin Source File

SOURCE=.\read_chars.cpp
# End Source File
# Begin Source File

SOURCE=.\replace_macros.cpp
# End Source File
# Begin Source File

SOURCE=.\trim_whitespace.cpp
# End Source File
# End Group
# Begin Group "enumerated types."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Enum_Circulator_Base.cpp
# End Source File
# End Group
# Begin Group "dates and times."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\annual_average.cpp
# End Source File
# Begin Source File

SOURCE=.\Date.cpp
# End Source File
# Begin Source File

SOURCE=.\Date_Time.cpp
# End Source File
# Begin Source File

SOURCE=.\leap_year.cpp
# End Source File
# Begin Source File

SOURCE=.\Month.cpp
# End Source File
# Begin Source File

SOURCE=.\Time_Of_Day.cpp
# End Source File
# End Group
# Begin Group "numbers."

# PROP Default_Filter ""
# Begin Group "formatting."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Exp_Fmt.cpp
# End Source File
# Begin Source File

SOURCE=.\Fix_Fmt.cpp
# End Source File
# Begin Source File

SOURCE=.\Gen_Fmt.cpp
# End Source File
# Begin Source File

SOURCE=.\Int_Fmt.cpp
# End Source File
# Begin Source File

SOURCE=.\Numeric_Format.cpp
# End Source File
# Begin Source File

SOURCE=.\Sci_Fmt.cpp
# End Source File
# End Group
# Begin Group "random."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MTRand.cpp
# End Source File
# Begin Source File

SOURCE=.\Random_Exponential.cpp
# End Source File
# Begin Source File

SOURCE=.\Random_Uniform.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Default_Epsilon.cpp
# End Source File
# Begin Source File

SOURCE=.\is_decimal_number.cpp
# End Source File
# Begin Source File

SOURCE=.\is_integer.cpp
# End Source File
# Begin Source File

SOURCE=.\str_to_float.cpp
# End Source File
# Begin Source File

SOURCE=.\str_to_int.cpp
# End Source File
# End Group
# Begin Group "program options."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Program_Arguments.cpp
# End Source File
# Begin Source File

SOURCE=.\Program_Option.cpp
# End Source File
# Begin Source File

SOURCE=.\Program_Options.cpp
# End Source File
# End Group
# Begin Group "files and directories."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\File_Error.cpp
# End Source File
# Begin Source File

SOURCE=.\File_Name_And_Desc.cpp
# End Source File
# Begin Source File

SOURCE=.\File_Path.cpp
# End Source File
# Begin Source File

SOURCE=.\File_Stat.cpp
# End Source File
# Begin Source File

SOURCE=.\File_Type.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Text_File.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Title.cpp
# End Source File
# Begin Source File

SOURCE=.\make_dir.cpp
# End Source File
# Begin Source File

SOURCE=.\no_lines_after.cpp
# End Source File
# Begin Source File

SOURCE=.\Output_File.cpp
# End Source File
# Begin Source File

SOURCE=.\Output_File_With_Entries.cpp
# End Source File
# Begin Source File

SOURCE=.\Output_Title.cpp
# End Source File
# End Group
# Begin Group "input values & vars."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Input_Formatted_Value.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_Error.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_error_message.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_Format_Error.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_Line.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_read.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_Str.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Value_Str_List.cpp
# End Source File
# Begin Source File

SOURCE=.\Input_Var_Str.cpp
# End Source File
# End Group
# Begin Group "output columns."

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Column_Group.cpp
# End Source File
# Begin Source File

SOURCE=.\Column_or_Group.cpp
# End Source File
# Begin Source File

SOURCE=.\Float_Column.cpp
# End Source File
# Begin Source File

SOURCE=.\Int_Column.cpp
# End Source File
# Begin Source File

SOURCE=.\Output_Column.cpp
# End Source File
# Begin Source File

SOURCE=.\output_columns.cpp
# End Source File
# Begin Source File

SOURCE=.\Str_Column.cpp
# End Source File
# End Group
# End Group
# End Target
# End Project
