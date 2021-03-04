@echo off                          	

SET MyProgram="%~1" 

IF %MyProgram%=="" (
  ECHO Please specify path to programm
  EXIT /B 1
)  

SET OutputFile="%TEMP%\out.txt"

REM No args
  %MyProgram% && goto err 
  ECHO test1 passed	

             
REM Empty string                                      
  SET /p EmptyString=<"%~dp0Empty.txt"
  SET EmptyStringOut="%~dp0Empty-out.txt"
 
  %MyProgram% %EmptyString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %EmptyStringOut% %OutputFile% > NUL || GOTO err 
  ECHO test2 passed


REM One string
  SET /p OneString=<"%~dp0OneString.txt"         
  SET OneStringOut="%~dp0OneString-out.txt"

  %MyProgram% %OneString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OneStringOut% %OutputFile% > NUL || GOTO err 
  ECHO test3 passed


REM Some strings
  SET /p SomeStrings=<"%~dp0SomeStrings.txt"
  SET SomeStringsOut="%~dp0SomeStrings-out.txt"

  %MyProgram% %SomeStrings% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %SomeStringsOut% %OutputFile% > NUL || GOTO err 
  echo test4 passed      


REM Number & String
  SET /p NumString=<"%~dp0NumString.txt"
  SET NumStringOut="%~dp0NumString-out.txt"
 
  %MyProgram% %NumString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %NumStringOut% %OutputFile% > NUL || GOTO err 
  echo test5 passed      


REM Negative number
  SET /p NegativeNum=<"%~dp0NegativeNum.txt"
  SET NegativeNumOut="%~dp0NegativeNum-out.txt"
 
  %MyProgram% %NegativeNum% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %NegativeNumOut% %OutputFile% > NUL || GOTO err 
  echo test6 passed

      
REM Not decimal number
  SET /p NotDecimalNum=<"%~dp0NotDecimalNumber.txt"
  SET NotDecimalNumOut="%~dp0NotDecimalNumber-out.txt"
 
  %MyProgram% %NegativeNum% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %NotDecimalNumOut% %OutputFile% > NUL || GOTO err 
  echo test7 passed


REM 0 if first digit	
  SET /p ZeroFirst=<"%~dp0ZeroFirst.txt"
  SET ZeroFirstOut="%~dp0ZeroFirst-out.txt" 
 
  %MyProgram% %ZeroFirst% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %ZeroFirstOut% %OutputFile% > NUL || GOTO err 
  echo test8 passed      


REM Overflow
  SET /p Overflow=<"%~dp0Overflow.txt"
  SET OverflowOut="%~dp0Overflow-out.txt" 
 
  %MyProgram% %Overflow% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OverflowOut% %OutputFile% > NUL || GOTO err 
  echo test9 passed


REM Some Num Args
  SET /p SomeNumArgs=<"%~dp0SomeNumArgs.txt"
  SET SomeNumArgsOut="%~dp0SomeNumArgs-out.txt"
 
  %MyProgram% %SomeNumArgs% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %SomeNumArgsOut% %OutputFile% > NUL || GOTO err 
  echo test10 passed
 

REM Num Low Border
  SET /p NumLowBorder=<"%~dp0NumLowBorder.txt"
  SET NumLowBorderOut="%~dp0NumLowBorder-out.txt"      
 
  %MyProgram% %NumLowBorder% > %OutputFile% || GOTO err
  fc %NumLowBorderOut% %OutputFile% > NUL || GOTO err 
  echo test11 passed      


REM Number high Border
  SET /p NumHighBorder=<"%~dp0NumHighBorder.txt"
  SET NumHighBorderOut="%~dp0NumHighBorder-out.txt" 
 
  %MyProgram% %NumHighBorder% > %OutputFile% || GOTO err
  fc %NumHighBorderOut% %OutputFile% > NUL || GOTO err 
  echo test12 passed      


REM Decimal Number
  SET /p Number=<"%~dp0Number.txt"
  SET NumberOut="%~dp0Number-out.txt"
 
  %MyProgram% %Number% > %OutputFile% || GOTO err
  fc %NumberOut% %OutputFile% > NUL || GOTO err 
  echo test13 passed      


:: tests are succes                		
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

