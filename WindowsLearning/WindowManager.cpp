#include "WindowManager.h"

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
    {
        int width = LOWORD(lParam);
        int height = HIWORD(lParam);
        return 0;
    }

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
        return 0;
    }

    case WM_GETMINMAXINFO:
    {
        LPMINMAXINFO lpMMI = (LPMINMAXINFO)lParam;
        lpMMI->ptMinTrackSize.x = 300;
        lpMMI->ptMinTrackSize.y = 300;
        return 0;
    }

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

Window CreateEmptyWindowClass(HINSTANCE instance, LPCWSTR ClassName, LPCWSTR windowTitle, LPCWSTR cursor, INT Icon, WNDPROC callBackFunction)
{
    HCURSOR hCursor = LoadCursor(NULL, cursor);
    if (!hCursor) {
        MessageBox(NULL, L"Failed to load cursor", L"Error", MB_OK | MB_ICONERROR);
    }

	WNDCLASS wcMain = {};
	wcMain.lpfnWndProc = callBackFunction;
	wcMain.hInstance = instance;
	wcMain.lpszClassName = ClassName;
	wcMain.hCursor = hCursor;
	wcMain.hIcon = LoadIcon(instance, MAKEINTRESOURCE(Icon));
	ATOM atomMain = RegisterClass(&wcMain);
	assert(atomMain != 0);

	HWND hwnd = CreateWindowEx(
		0,
		ClassName,
		windowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		instance,
		NULL
	);

	assert(hwnd != NULL);
	
	return { wcMain,hwnd };
}

void Window::ShowWindowClass()
{
	ShowWindow(this->handle,1);
	UpdateWindow(this->handle);

}

void MainLoop()
{
	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
