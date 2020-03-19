Socket Connection Library (SCL) - Linux/Window/Mac
===============================================================================
Assignment to create/close socket connection using new Socket Connection Library. Socket Connection libraries has to create for Windows and Linux. Below provided steps to create libraries for Windows and Linux. In this assignment MAC not tested because oflack of MAC enviroment. Aim is to generate the ELF with corresponding libaries and produce the executable. At the compilation library has to link and exection will takesplace accordingly.

Windows - SCL  - Steps
======================
1. File -> New  -> Project -> Win32 Console Project  -> Application Settings (Static Library) -> Finis
2. Go to Solution Explorer -> copy window/stdafx.cpp in 'Source Files' directory
3. Go to Solution Explorer -> copy window/stdafx.h and windows/socket-connection.h in 'Header Files' directory
4. Build -> Build Solution
	- Static Libary will be created ( <name>.lib )
5. File -> New -> Project -> Empty Project 
6. Go to Solution Explorer -> copy server.cpp in 'Source Files' directory
7. Properties -> Linker -> Input -> Addtional Dependencies -> Edit 
	- Add Ws2_32.lib
	- Add <name>.lib
8. Properties -> Configuration Properties -> VC++ Directories -> General -> Include Directories
	- Add path of windows/socket-connection.h path
9. Properties -> Configuration Properties -> VC++ Directories -> General -> Library Directories
	- Add path of Library got from Step 4
10. Build -> Build Solution
11. Debug -> Start without Debugging

Linux - SCL  - Steps
======================
1. Run CompileLinux.sh
2. ./linux-out


