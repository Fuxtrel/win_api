#ifndef WIN_API_WIN_SHORTCUTS_H
#define WIN_API_WIN_SHORTCUTS_H

#include <string>
#include <utility>
#include <windows.h>
#include <objbase.h>
#include <shobjidl.h>
#include <winnls.h>
#include <objidl.h>
#include <shlguid.h>
#include <iostream>
#include <processthreadsapi.h>
#include <vector>




//class WinShortCut {

//public:
//    const std::string app_folder_path;
//    const std::string storageup_path;
//
//    WinShortCut() = default;
//    ~WinShortCut() = default;
//
//    [[maybe_unused]] bool createShortCut(LPSTR  path_to_exe, LPSTR args, LPSTR  path_to_shortcut,
//                                         LPSTR  description, int show_mode,
//                                         LPSTR  working_dir, LPSTR  icon_path, int icon_index);
//
//};

std::vector<std::string> split(std::string source, std::string separator);

extern "C" __declspec(dllexport)
bool createProcess(char* path, char* arguments, char* working_dir);

#endif //WIN_API_WIN_SHORTCUTS_H
