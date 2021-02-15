@echo off

:: path to testing program gets from argument 1 of cmd
:: MyProgram is variable, which includes path to program.exe
SET MyProgram="%~1" 

:: protecting from start without argument 1
if %MyProgram%=="" (
  echo Please specify path to programm
  exit /B 1
) 

SET OutputFile="%TEMP%\outputTest.txt" 
SET EmptyFile=".\tests\Empty.txt"
SET FillFile=".\tests\Fill.txt"
SET MissingFile=".\tests\MissFile.txt" 


REM Copy empty file
  %MyProgram% %EmptyFile% %OutputFile% || goto err
  fc %EmptyFile% %OutputFile% > nul || goto err 
  echo test1 passed   

:: comand " > nul " redirect echo to nul from cmd

REM Copy fill file
  %MyProgram% %FillFile% %OutputFile% || goto err
  fc %FillFile% %OutputFile% > nul || goto err
  echo test2 passed

REM Copy missing file
  %MyProgram% %MissFile% %OutputFile% && goto err
  echo test3 passed

REM No OutputFile arg
  %MyProgram% %MissFile% && goto err
  echo test4 passed

REM No args 
  %MyProgram% && goto err
  echo test5 passed



:: tests are succes
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

