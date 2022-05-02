#ifndef Includes
#include "Includes.h"
#endif


uintptr_t uninject_key = VK_HOME;

int WINAPI main_thread(HMODULE hModule) {

    Utils::display_message_box("SussySoutions", "Injected!");

    //startFeatures
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartNoRecoil, hModule, 0, 0);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartGlowEsp, hModule, 0, 0);

    //Handle UnInject shit (doesnt work rlly lmao)
    while (!GetAsyncKeyState(uninject_key)) {
        Sleep(1000);
    }

    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)main_thread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

