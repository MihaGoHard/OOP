@echo off                          	

SET MyProgram="%~1" 

IF %MyProgram%=="" (
  ECHO Please specify path to programm
  EXIT /B 1
)  

SET OutputFile="%TEMP%\out.txt"
            
SET EmptyFile1=".\Tests\empty1.txt"
SET EmptyFile2=".\Tests\empty2.txt"
SET EmptyFile3=".\Tests\empty3.txt"
SET EmptyFilesOut="%~dp0emptyOut.txt"
SET OneArgFileOut="%~dp0oneArgOut.txt"


REM No args
  %MyProgram% && goto err 
  ECHO test1 passed	


REM One arg
  %MyProgram% %EmptyFile1% && goto err   
  ECHO test2 passed	


REM Many args
  %MyProgram% %EmptyFile1% %EmptyFile2% %EmptyFile3% && goto err   
  ECHO test3 passed	

                  
REM Empty files 
  %MyProgram% %EmptyFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %EmptyFilesOut% %OutputFile% > NUL || GOTO err 
  ECHO test4 passed


REM First-invalid second-empty
  SET InvalidFile1=".\Tests\invalid_empty_1.txt"
  SET EmptyFile2=".\Tests\invalid_empty_2.txt"
  SET InvalidEmptyOut="%~dp0invalid_empty_out.txt"

  %MyProgram% %InvalidFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %InvalidEmptyOut% %OutputFile% > NUL || GOTO err 
  ECHO test5 passed


REM First-valid second-empty
  SET ValidFile1=".\Tests\valid_empty_1.txt"
  SET EmptyFile2=".\Tests\valid_empty_2.txt"
  SET ValidEmptyOut="%~dp0valid_empty_out.txt"
 
  %MyProgram% %ValidFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %ValidEmptyOut% %OutputFile% > NUL || GOTO err 
  ECHO test6 passed


REM First-valid second-invalid
  SET ValidFile1=".\Tests\valid_invalid_1.txt"
  SET InvalidFile2=".\Tests\valid_invalid_2.txt"
  SET ValidInvalidOut="%~dp0valid_invalid_out.txt"
 
  %MyProgram% %ValidFile1% %InvalidFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %ValidInvalidOut% %OutputFile% > NUL || GOTO err 
  ECHO test7 passed


SET File1_2x3_2x3=".\Tests\m_2x3_2x3_1.txt"
SET File2_2x3_2x3=".\Tests\m_2x3_2x3_2.txt"
SET OutFile_2x3_2x3="%~dp0m_2x3_2x3_out.txt"

REM matrices 2X3 2X3 
  %MyProgram% %File1_2x3_2x3% %File2_2x3_2x3% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OutFile_2x3_2x3% %OutputFile% > NUL || GOTO err 
  ECHO test8 passed


SET File1_3x3_2x3=".\Tests\m_3x3_2x3_1.txt"
SET File2_3x3_2x3=".\Tests\m_3x3_2x3_2.txt"
SET OutFile_3x3_2x3="%~dp0m_3x3_2x3_out.txt"

REM matrices 3X3 2X3 
  %MyProgram% %File1_3x3_2x3% %File2_3x3_2x3% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OutFile_3x3_2x3% %OutputFile% > NUL || GOTO err 
  ECHO test9 passed


SET File1_3x3_4x3=".\Tests\m_3x3_4x3_1.txt"
SET File2_3x3_4x3=".\Tests\m_3x3_4x3_2.txt"
SET OutFile_3x3_4x3="%~dp0m_3x3_4x3_out.txt"

REM matrices 3X3 4X3 
  %MyProgram% %File1_3x3_4x3% %File2_3x3_4x3% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OutFile_3x3_4x3% %OutputFile% > NUL || GOTO err 
  ECHO test10 passed


SET File1_2x4_3x3=".\Tests\m_2x4_3x3_1.txt"
SET File2_2x4_3x3=".\Tests\m_2x4_3x3_2.txt"
SET OutFile_2x4_3x3="%~dp0m_2x4_3x3_out.txt"

REM matrices 2X4 3X3 
  %MyProgram% %File1_2x4_3x3% %File2_2x4_3x3% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OutFile_2x4_3x3% %OutputFile% > NUL || GOTO err 
  ECHO test11 passed


SET File1_3x3_3x3=".\Tests\m_3x3_3x3_1.txt"
SET File2_3x3_3x3=".\Tests\m_3x3_3x3_2.txt"
SET OutFile_3x3_3x3="%~dp0m_3x3_3x3_out.txt"

REM matrices 3X3 3X3 
  %MyProgram% %File1_3x3_3x3% %File2_3x3_3x3% > %OutputFile%
  IF %ERRORLEVEL% == 1 GOTO err
  fc %OutFile_3x3_3x3% %OutputFile% > NUL || GOTO err 
  ECHO test12 passed


:: tests are succes                		
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

