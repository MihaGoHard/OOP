@echo off

:: path to testing program gets from argument 1 of cmd
SET MyProgram="%~1" 

:: protecting from start without argument 1
if %MyProgram%=="" (
  echo Please specify path to programm
  exit /B 1
) 

SET OutputFile="%TEMP%\outputTest.txt"
:: MyProgram is variable included path to program.exe  

REM Copy empty file
  SET EmptyFile=".\tests\Empty.txt"
  %MyProgram% %EmptyFile% %OutputFile% || goto err
  fc %EmptyFile% %OutputFile% || goto err

REM Copy fill file
  SET FillFile=".\tests\Fill.txt"
  %MyProgram% %FillFile% %OutputFile% || goto err
  fc %FillFile% %OutputFile% || goto err


:: tests are succes
echo Tests comlited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

