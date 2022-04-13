#include <iostream>
#include <thread>
#include "win_shortcuts.h"
#include <chrono>
#include <psapi.h>
#include <winuser.h>
#include <processthreadsapi.h>



bool createProcess(){
    std::string exe_path = R"(C:\StorageUp\StorageUp\storageup.exe)";
    std::string working_dir_path = R"(C:\StorageUp\StorageUp\)";
    return CreateProcessA(exe_path, nullptr, nullptr, nullptr, false, NORMAL_PRIORITY_CLASS, nullptr, working_dir_path, );
}

int main() {

    unsigned int start_time = clock();
    std::cout.flush() << "Hello" << std::endl;
    unsigned int end_time = clock();
    std::cout << "Time spent " << end_time - start_time;
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
