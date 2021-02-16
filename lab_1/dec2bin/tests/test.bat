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
SET NoArgs="%~dp0No_args.txt"
SET NoArgsOut="%~dp0No_args_out.txt" 

echo %NoArgs%



REM Copy empty file
  %MyProgram%  "" > %OutputFile% || goto err
  ::fc %NoArgsFile% %OutputFile% > nul || goto err 
  echo test1 passed   



:: tests are succes
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

