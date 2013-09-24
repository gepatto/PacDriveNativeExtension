AS3Library
--
This project contains both the AS3 part of the PacDriveNativeExtension and a flex-demo

> This project has been built on the air3.8 sdk and FlashBuilder 4.7

 - copy the PacDrive.dll found in extensions/src/windows to windows/system32
   otherwise you'll probably be getting 'context-errors' 

- If needed change the SDK in the project properties (you will still see errors)

###The first build must be done using the ant-build file
  - change the sdk_home property in build.xml
  - run the default task by right-clicking on build.xml and selecting -> run as -> ant build

this will build the Ane and Compile the demo.

All FlashBuilder-errors should be gone now