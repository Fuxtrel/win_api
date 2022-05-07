#include "win_shortcuts.h"

int createShortCut(LPSTR path_to_exe, LPSTR args, LPSTR path_to_shortcut,
                   LPSTR description, int show_mode,
                   LPSTR working_dir, LPSTR icon_path, int icon_index) {
    HRESULT result = E_INVALIDARG;
    IShellLink *p_shell_link = nullptr;
    IPersistFile *p_persist_file = nullptr;
    WCHAR wsz_link_file[MAX_PATH];
    int count_written_wide_characters;

    CoInitialize(nullptr);
    if (
            (strlen(path_to_exe) > 0) &&
            (strlen(path_to_shortcut) > 0) &&
            (show_mode >= 0) &&
            (strlen(icon_path) > 0) &&
            (icon_index >= 0)
            ) {
        result = CoCreateInstance(
                CLSID_ShellLink,     /* pre-defined CLSID of the IShellLink object */
                nullptr,         /* pointer to parent interface if part of aggregate */
                CLSCTX_INPROC_SERVER, /* caller and called code are in same process */
                IID_IShellLink,      /* pre-defined interface of the IShellLink object */
                (LPVOID *) &p_shell_link);         /* Returns a pointer to the IShellLink object */
        if (SUCCEEDED(result)) {
            /* Set the fields in the IShellLink object */
            result = p_shell_link->SetPath(path_to_exe);
            result = p_shell_link->SetArguments(args);
            if (strlen(description) > 0) {
                result = p_shell_link->SetDescription(description);
            }
            if (show_mode > 0) {
                result = p_shell_link->SetShowCmd(show_mode);
                std::cout << result;
            }
            if (strlen(working_dir) > 0) {
                result = p_shell_link->SetWorkingDirectory(working_dir);
            }
            if (strlen(icon_path) > 0 && icon_index >= 0) {
                result = p_shell_link->SetIconLocation(icon_path, icon_index);
            }

            /* Use the IPersistFile object to save the shell link */
            result = p_shell_link->QueryInterface(
                    IID_IPersistFile,         /* pre-defined interface of the IPersistFile object */
                    (LPVOID *) &p_persist_file);            /* returns a pointer to the
                                        IPersistFile object */
            if (SUCCEEDED(result)) {
                count_written_wide_characters = MultiByteToWideChar(CP_ACP, 0,
                                                                    path_to_shortcut, -1,
                                                                    wsz_link_file, MAX_PATH);
                result = p_persist_file->Save(wsz_link_file, TRUE);
                p_persist_file->Release();
            }
            p_shell_link->Release();
        }
    }
    CoUninitialize();
    return result;
}


int createLinkFile(char* path_to_exe, char* args, char* path_to_shortcut,
                   char* description, int show_mode,
                   char* working_dir, char* icon_path, int icon_index){
    HRESULT result = createShortCut(path_to_exe, args, path_to_shortcut, description, show_mode, working_dir, icon_path, icon_index);
    return result;
}

std::vector<std::string> split(std::string source, std::string separator) {
    std::vector<std::string> result;
    size_t pos = 0;
    while ((pos = source.find(separator)) != std::string::npos) {
        result.push_back(source.substr(0, pos));
        source.erase(0, pos + separator.length());
    }
    result.push_back(source.substr(0, pos));
    return result;
}

int createProcess(const char *path, const char *arguments, const char *working_dir) {
    std::cout << path << "\t" << arguments << "\t" << working_dir << std::endl;

    std::vector<std::string> args = split(std::string(arguments), "|");

    PROCESS_INFORMATION process_information;
    ZeroMemory(&process_information, sizeof(process_information));

    std::string cmd(path);

    for (auto &argument: args) {
        cmd += " " + argument;
    }
    std::cout << cmd << std::endl;
    STARTUPINFOA startupinfo;
    ZeroMemory(&startupinfo, sizeof(startupinfo));
    startupinfo.cb = sizeof(startupinfo);

    auto result = CreateProcessA(
            path,
            cmd.data(),
            nullptr,
            nullptr,
            false,
            REALTIME_PRIORITY_CLASS | CREATE_NO_WINDOW,
            nullptr,
            working_dir,
            &startupinfo,
            &process_information
    );
//    std::cout << GetLastError() << std::endl;
    return result;
}

//HRESULT getScreenScale() {
//    DISPLAY_DEVICE_TYPE displayDeviceType = DEVICE_PRIMARY;
//    GetScaleFactorForDevice(displayDeviceType);
//    if(deviceScaleFactor == nullptr){
//        std::cout << (int(*deviceScaleFactor)) << std::endl;
//    }
//    HRESULT hresult = 0;
//    return hresult;
//}


