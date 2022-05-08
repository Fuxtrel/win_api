#include "win_api.h"


int main() {
    //    unsigned int start_time = clock();
//    DISPLAY_DEVICE_TYPE displayDeviceType;
//    std::cout << GetScaleFactorForDevice(DEVICE_PRIMARY) << std::endl;
//    unsigned int end_time = clock();
//    std::cout << "Time spent " << end_time - start_time;
//    bool err = FreeConsole();
//    using namespace std::chrono_literals;
//    std::string wd = R"(C:\StorageUp\StorageUp\)";
//    std::string exe = R"(C:\StorageUp\StorageUp\start_keeper.exe)";
//    std::string ico = R"(C:\StorageUp\StorageUp\StorageUp.ico)";
//    std::string d = "description";
//    std::string lnk = R"(C:\Users\a99so\Desktop\StartKeeper.lnk)";
//    std::string args;
//    LPSTR working_dir = wd.data();
//    LPSTR storageup_dir_path = exe.data();
//    int show_mode = SW_FORCEMINIMIZE;
//    LPSTR icon_path = ico.data();
//    int icon_index = 0;
//    LPSTR lnk_path = lnk.data();
//    LPSTR description = d.data();
//    createShortCut(storageup_dir_path, args.data(),
//                           lnk_path, description, show_mode,
//                           working_dir, icon_path, icon_index);
//    killProcessByName("Discord.exe");
    char a[] = "ab";
    a[0] = 0x61;
    createRegKey("Software\\StorageUp\\test", "DisplayVersion", a);
//    getScreenScale();
//    DISPLAY_DEVICE_TYPE displayDeviceType = DEVICE_IMMERSIVE;
//    DEVICE_SCALE_FACTOR abr = GetScaleFactorForDevice(displayDeviceType);
//    std::this_thread::sleep_for(2000ms);
}
