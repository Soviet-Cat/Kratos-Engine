@echo off

if /I "%1"=="help" goto showHelp
if /I "%1"=="header" goto createHeader
if /I "%1"=="source" goto createSource
if /I "%2"=="" goto showHelp

goto showHelp

:createHeader
if /I "%3"=="public" (
    set "location=%CD%\src\%2"
) else if /I "%3"=="private" (
    set "location=%CD%\src\%2"
) else goto showHelp

for /f "usebackq delims=" %%I in (`powershell -NoProfile -Command "$str='%3'; $first=$str.Substring(0,1).ToLower(); $rest=$str.Substring(1); Write-Output ($first + $rest)"`) do set "prefix=%%~I"

for %%A in ("%location%") do set "directory=%%~dpA"
if not exist %directory% mkdir %directory%

type "%CD%\base\header_%prefix%.hpp" > %location%
exit /b

:createSource
set "location=%CD%\src\%2"

for %%A in ("%location%") do set "directory=%%~dpA"
if not exist %directory% mkdir %directory%

type "%CD%\base\source.cpp" > %location%
exit /b

:showHelp
echo Usage: %~n0 [Header^|Source] [Location] [Public^|Private](Only for headers!)
exit /b