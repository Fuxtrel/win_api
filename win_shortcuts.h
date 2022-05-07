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

extern "C" __declspec(dllexport)
int createLinkFile(const char* path_to_exe, const char* args, const char* path_to_shortcut,
                   const char* description, int show_mode,
                   const char* working_dir, const char* icon_path, int icon_index);

int createShortCut(LPSTR path_to_exe, LPSTR args, LPSTR path_to_shortcut,
                    LPSTR description, int show_mode,
                    LPSTR working_dir, LPSTR icon_path, int icon_index);

std::vector<std::string> split(std::string source, std::string separator);

extern "C" __declspec(dllexport)
int createProcess(const char *path, const char *arguments, const char *working_dir);

//HRESULT getScreenScale();

#endif //WIN_API_WIN_SHORTCUTS_H
