@echo off                          	

SET MyProgram="%~1" 

IF %MyProgram%=="" (
  ECHO Please specify path to programm
  EXIT /B 1
)  

SET OutputFile="%TEMP%\out.txt"
            
SET EmptyFile1=".\Tests\empty1.txt"
SET EmptyFile2=".\Tests\empty2.txt"
SET EmptyFilesOut="%~dp0emptyOut.txt"
                  
REM Empty files 
  %MyProgram% %EmptyFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %EmptyFilesOut% %OutputFile% > NUL || GOTO err 
  ECHO test1 passed


SET IncorrectFile1=".\Tests\incorrectEmpty1.txt"
SET EmptyFile2=".\Tests\incorrectEmpty2.txt"
SET IncorrectEmptyOut="%~dp0incorrectEmptyOut.txt"

REM First-incorrect second-empty 
  %MyProgram% %IncorrectFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %IncorrectEmptyOut% %OutputFile% > NUL || GOTO err 
  ECHO test2 passed


SET CorrectFile1=".\Tests\correctEmpty1.txt"
SET EmptyFile2=".\Tests\correctEmpty2.txt"
SET CorrectEmptyOut="%~dp0CorrectEmptyOut.txt"

REM First-correct second-empty 
  %MyProgram% %CorrectFile1% %EmptyFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %CorrectEmptyOut% %OutputFile% > NUL || GOTO err 
  ECHO test3 passed


SET CorrectFile1=".\Tests\correctIncorrect1.txt"
SET IncorrectFile2=".\Tests\correctIncorrect2.txt"
SET CorrectIncorrectOut="%~dp0CorrectIncorrectOut.txt"

REM First-correct second-incorrect 
  %MyProgram% %CorrectFile1% %IncorrectFile2% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %CorrectIncorrectOut% %OutputFile% > NUL || GOTO err 
  ECHO test4 passed



:: tests are succes                		
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

