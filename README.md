# XtionUtil
This is a Windows plugin for Unity to access Xtion2 camera from inside Unity <br>
**Warning**: I don't have an Xtion camera anymore and further development is not possible at the moment.
This was working as the time of writing but I can't guarantee on new versions of Windows, or OpenNI SDKs. Please just use this as a reference for now

# Dependencies
* OpenNI2 sdk for Xtion2. Download [here](https://www.asus.com/3D-Sensor/Xtion-2/HelpDesk_Download/).
* Tested on Windows 10 with Visual Studio Community 2017 and Unity 2017.2

# Building
* Run the installer to install the OpenNI SDK.
* Check the SDK installation is successful by building the included samples.
* Note : Although the samples built successfully you will need to have RvcLib.dll and SenDuck.dll during runtime. These two files can
be found in the root folder of the SDK installation folder.
* Edit the CMakelists.txt in the repository and build this project.
* In build/Release you will find XtionCapture.dll.
* Copy this DLL to your Unity project's Plugins/x64 or x86 folders depending on your architecture and build settings.
