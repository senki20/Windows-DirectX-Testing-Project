#pragma once
#include <Windows.h>
#include <assert.h>
#include "resource.h"
#include <Commctrl.h>


struct Window {
	WNDCLASS wndClass;
	HWND handle;
	bool shouldCloseProgram = 1;

	void ShowWindowClass();
};

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

Window CreateEmptyWindowClass(HINSTANCE instance, LPCWSTR ClassName, LPCWSTR windowTitle, LPCWSTR cursor = IDC_ARROW,INT Icon = IDI_ICON1, WNDPROC callBackFunction = &MainWindowProc);

void MainLoop();
