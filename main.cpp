#include <iostream>
#include <thread>
#include "win_shortcuts.h"
#include <chrono>
#include <psapi.h>
#include <winuser.h>
#include <processthreadsapi.h>
#include <vector>


bool createProcess(std::string path, std::vector<std::string> &arguments, std::string working_dir) {
    PROCESS_INFORMATION process_information;
    ZeroMemory(&process_information, sizeof(process_information));

    std::string cmd = path;

    for(int i = 0; i < arguments.size(); i++){
        cmd += "" + arguments[i];
    }

    STARTUPINFO startupinfo;
    ZeroMemory(&startupinfo, sizeof(startupinfo));
    startupinfo.cb = sizeof(startupinfo);
    auto res =  CreateProcessA(
            path.data(),
            cmd.data(),
            nullptr,
            nullptr,
            false,
            REALTIME_PRIORITY_CLASS | CREATE_NO_WINDOW,
            nullptr,
            working_dir.data(),
            &startupinfo,
            &process_information
    );
    std::cout << res;
}


int main() {
    PROCESS_INFORMATION process_information;
    ZeroMemory(&process_information, sizeof(process_information));

    STARTUPINFO startupinfo;
    ZeroMemory(&startupinfo, sizeof(startupinfo));
    startupinfo.cb = sizeof(startupinfo);

    std::string working_dir_path = R"(C:\StorageUp\StorageUp)";
    std::string exe_path = R"(C:\StorageUp\StorageUp\ups_update.exe)";
    std::vector<std::string> arguments = {};


    auto res1 = createProcess(exe_path, arguments, working_dir_path);
    printf("CreateProcess failed (%d).\n", GetLastError());
    std::cout << "My func " << res1 << std::endl;


//    unsigned int start_time = clock();
//
//    std::cout.flush() << "Hello" << std::endl;
//
//
//    unsigned int end_time = clock();
//    std::cout << "Time spent " << end_time - start_time;

//    bool err = FreeConsole();
//    using namespace std::chrono_literals;
//    LPSTR working_dir = "C:\\StorageUp\\StorageUp\\";
//    LPSTR storageup_dir_path = "C:\\StorageUp\\StorageUp\\storageup.exe";
//    int show_mode = SW_SHOWMAXIMIZED;
//    LPSTR icon_path = "C:\\Users\\a99so\\Desktop\\src\\src\\StorageUp.ico";
//    WinShortCut win_api;
//    int icon_index = 0;
//    LPSTR description = "description";
//    win_api.createShortCut(storageup_dir_path, "",
//                           "C:\\Users\\a99so\\Desktop\\StorageUp.lnk", description, show_mode,
//                           working_dir, icon_path, icon_index);
//    std::this_thread::sleep_for(2000ms);
//    system("start /min C:\\Users\\a99so\\CLionProjects\\win_api\\cmake-build-debug\\1.exe");
}
