#pragma once
#include<Windows.h>
#include<stdio.h.>


HHOOK g_hook; //keyboard hook 

_declspec(dllexport) int InstallHook();

_declspec(dllexport) int UnInstallHook();

long CALLBACK KeyboardProc(int nCode,WPARAM wParam, LPARAM lParam);