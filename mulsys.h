#ifndef _MULSYS_H_
#define _MULSYS_H_

#include<stdlib.h>
#include<stdio.h>

using namespace std;

void crosscmd(const char* Windows_command, const char* Darwin_command, const char* Linux_Unix_command)
{
	#ifdef _WIN32
        system (Windows_command);  
	#elif __APPLE__
    	system (Darwin_command);
	#elif __unix__
        system (Linux_Unix_command);
	#elif __linux__
        system (Linux_Unix_command);
	#elif __ANDROID__
		system (Linux_Unix_command);
	#else
		printf("crosscmd(): System error: Unfortunately, crosscmd() can only be used on Windows, Linux, Apple's OSes, Unix and Android. You can go to this tutorial to learn more about cross platform programming.\n  >> https://iq.opengenus.org/detect-operating-system-in-c/");
	#endif
	// https://cyfangnotepad.blogspot.com/2015/02/c.html?m=1
}

void wlcmd(const char* Windows_command, const char* Linux_command)
{
	#ifdef _WIN32
        system (Windows_command); 
	#elif __linux__
		system (Linux_command);
	#else
		printf("wlcmd(): System error: wlcmd() can only be used on Windows and Linux. Please use crosscmd() or applecmd() and try again.\n");
	#endif
}

void wincmd(const char* command)
{
	#ifdef _WIN32
		system (command);
	#else
		printf("wincmd(): System error: wincmd() can only be used on Windows. Please use crosscmd() or other and try again.\n");
	#endif
}

void lnxcmd(const char* command)
{
	#ifdef __linux__
		system (command);
	#else
		printf("lnxcmd(): System error: lnxcmd() can only be used on Linux. Please use crosscmd() or other and try again.\n");
	#endif
}

void applecmd(const char* command)
{
	#ifdef __APPLE__
		system (command);
	#else
		printf("applecmd(): System error: applecmd() can only be used on OSes that is made by Apple such as macOS, iOS, iOS stimulator or iOS embedded. Please use crosscmd() or other and try again.\n");
	#endif
}

void clearscr()
{
	#ifdef _WIN32
        system ("cls");  
	#elif __APPLE__
    	system ("clear");
	#elif __unix__
        system ("clear");
	#elif __linux__
        system ("clear");
	#elif __ANDROID__
		system ("clear");
	#else
		printf("clearscr(): System error: Unfortunately, clearscr() can only be used on Windows, Linux, Apple's OSes, Unix and Android. You can go to this tutorial to learn more about cross platform programming.\n  >> https://iq.opengenus.org/detect-operating-system-in-c/");
	#endif
}

bool isSys(const char* system_name)
{
	if (system_name == "win" || system_name == "windows" || system_name == "Windows")
	{
		#ifdef _WIN32
        	return true;
		#else
			return false;
		#endif
	}
	else if (system_name == "lnx" || system_name == "linux" || system_name == "Linux")
	{
		#ifdef __linux__
        	return true;
		#else
			return false;
		#endif
	}
	else if (system_name == "unx" || system_name == "unix" || system_name == "Unix")
	{
		#ifdef __unix__
        	return true;
		#else
			return false;
		#endif
	}
	else if (system_name == "apl" || system_name == "apple" || system_name == "Apple" ||
				system_name == "drw" || system_name == "darwin" || system_name == "Darwin")
	{
		#ifdef __APPLE__
        	return true;
		#else
			return false;
		#endif
	}
	else if (system_name == "and" || system_name == "android" || system_name == "Android")
	{
		#ifdef __ANDROID__
        	return true;
		#else
			return false;
		#endif
	}
	else
	{
		printf("isSys(): argument error: This function can judge if the guest machine is target system and return true or false (bool).\n");
		printf("         Usage: isSys(\"[target system name]\");\n");
		printf("         Return value: true / false (boolean type)\n\n");
		printf("         For example, if you want to judge if guest machine is Windows:\n");
		printf("             isSys(\"win\");   // If guest machine is Windows, return true. If not, return false.\n");
		printf("         If you want to judge if guest machine is Linux:\n");
		printf("             isSys(\"linux\");   // If guest machine is Linux, return true. If not, return false.\n");
		printf("         More information on dev's online manual webite: https://www.google.com/ \n\n");

		return false;
	}
}

#endif