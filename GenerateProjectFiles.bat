@echo off

echo Generating Project Files...

if not exist "Engine\Extras\ThirdParty\premake\premake5.exe" goto Error_Premake5WrongLocation 
call Engine\Extras\ThirdParty\premake\premake5.exe vs2019
goto Success

:Error_Premake5WrongLocation
echo GenerateProjectFiles ERROR: The premake5 file does not appear to be located in the root FE directory. This script must be run from within that directory.

:Success
echo Successfully Created Project Files.
PAUSE