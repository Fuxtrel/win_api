#ifndef WIN_API_WIN_SHORTCUTS_H
#define WIN_API_WIN_SHORTCUTS_H


#include <string>
#include <utility>
#include <Windows.h>
#include <objbase.h>
#include <ShObjIdl.h>
#include <WinNls.h>
#include <ObjIdl.h>
#include <ShlGuid.h>
#include <iostream>
#include <processthreadsapi.h>
#include <vector>
#include <ShellScalingApi.h>
#include <tlhelp32.h>
#include <map>
#include <cstdio>
#include <string.h>

//"C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.19041.0\\um\\x64\\shcore.lib"

#pragma comment(lib, "shcore.lib")

int createShortCut(LPSTR path_to_exe, LPSTR args, LPSTR path_to_shortcut,
LPSTR description, int show_mode,
LPSTR working_dir, LPSTR icon_path, int icon_index);

std::vector<std::string> split(std::string source, std::string separator);

extern "C" __declspec(dllexport)
int createProcess(const char *path, const char *arguments, const char *working_dir);

extern "C" __declspec(dllexport)
int createLinkFile(char* path_to_exe, char* args, char* path_to_shortcut,
                   char* description, int show_mode,
                   char* working_dir, char* icon_path, int icon_index);

extern "C" __declspec(dllexport)
int getScreenScale();

std::map<int,std::string> getRunningProcesses();

bool processIsRunning(const char *processName);

std::map<std::string, std::string> getServices();

int getServiceStatus(const char* serviceName);

#endif //WIN_API_WIN_SHORTCUTS_H
