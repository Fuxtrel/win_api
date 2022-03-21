//
// Created by a99so on 21.03.2022.
//



#include <iostream>
#include "win_shortcuts.h"

[[maybe_unused]] bool WinShortCut::createShortCut(LPSTR  path_to_exe, LPSTR args, LPSTR  path_to_shortcut,
                                                  LPSTR  description, int show_mode,
                                                  LPSTR  working_dir, LPSTR  icon_path, int icon_index) {
    bool result = E_INVALIDARG;
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


