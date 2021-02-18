@echo off                          	

SET MyProgram="%~1" 

IF %MyProgram%=="" (
  ECHO Please specify path to programm
  EXIT /B 1
)  

SET OutputFile="%TEMP%\out.txt"
            
SET /p EmptyString=<"%~dp0Empty.txt"
SET EmptyStringOut="%~dp0Empty-out.txt"
                  
SET /p OneString=<"%~dp0OneString.txt"         
SET OneStringOut="%~dp0OneString-out.txt"

SET /p SomeStrings=<"%~dp0SomeStrings.txt"
SET SomeStringsOut="%~dp0SomeStrings-out.txt" 
                                          
SET /p NumString=<"%~dp0NumString.txt"
SET NumStringOut="%~dp0NumString-out.txt"
 
SET /p NegativeNum=<"%~dp0NegativeNum.txt"
SET NegativeNumOut="%~dp0NegativeNum-out.txt"

SET /p SomeNumArgs=<"%~dp0SomeNumArgs.txt"
SET SomeNumArgsOut="%~dp0SomeNumArgs-out.txt"
 
SET /p NumLowBorder=<"%~dp0NumLowBorder.txt"
SET NumLowBorderOut="%~dp0NumLowBorder-out.txt" 

SET /p NumHighBorder=<"%~dp0NumHighBorder.txt"
SET NumHighBorderOut="%~dp0NumHighBorder-out.txt" 

SET /p Overflow=<"%~dp0Overflow.txt"
SET OverflowOut="%~dp0Overflow-out.txt" 

SET /p Number=<"%~dp0Number.txt"
SET NumberOut="%~dp0Number-out.txt"

REM Empty string 
  %MyProgram% %EmptyString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %EmptyStringOut% %OutputFile% > NUL || GOTO err 
  ECHO test1 passed

REM One string
  %MyProgram% %OneString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OneStringOut% %OutputFile% > NUL || GOTO err 
  ECHO test2 passed

REM Some strings
  %MyProgram% %SomeStrings% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %SomeStringsOut% %OutputFile% > NUL || GOTO err 
  echo test3 passed      

REM Num & String 
  %MyProgram% %NumString% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %NumStringOut% %OutputFile% > NUL || GOTO err 
  echo test4 passed      

REM NegativeNum 
  %MyProgram% %NegativeNum% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %NegativeNumOut% %OutputFile% > NUL || GOTO err 
  echo test5 passed      

REM Overflow 
  %MyProgram% %Overflow% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %OverflowOut% %OutputFile% > NUL || GOTO err 
  echo test6 passed

REM Some Num Args 
  %MyProgram% %SomeNumArgs% > %OutputFile%
  IF NOT %ERRORLEVEL% == 1 GOTO err
  fc %SomeNumArgsOut% %OutputFile% > NUL || GOTO err 
  echo test7 passed
      
REM Num Low Border 
  %MyProgram% %NumLowBorder% > %OutputFile% || GOTO err
  fc %NumLowBorderOut% %OutputFile% > NUL || GOTO err 
  echo test8 passed      

REM Num High Border 
  %MyProgram% %NumHighBorder% > %OutputFile% || GOTO err
  fc %NumHighBorderOut% %OutputFile% > NUL || GOTO err 
  echo test9 passed      

REM Number 
  %MyProgram% %Number% > %OutputFile% || GOTO err
  fc %NumberOut% %OutputFile% > NUL || GOTO err 
  echo test10 passed      


:: tests are succes                		
echo All tests complited successfully
exit /B 0

:: tests are faild
:err 
  echo Test faild
  exit /B 1

