
@ECHO OFF

echo Did you change the path to the Flex/Air SDK?
echo Then remove this message
pause 

REM CHANGE PATH TO ADL FIRST
REM use full path to allow running from flashbuilder


D:\frameworks\flex_sdk_4.6_Air3.8\bin\adl.exe -profile extendedDesktop -extdir "bin-debug\tmp" "bin-debug\As3Example.as" "bin-debug"

@ECHO ON