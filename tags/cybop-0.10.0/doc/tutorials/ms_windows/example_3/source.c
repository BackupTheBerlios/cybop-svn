#include <windows.h>
#include "resource.h"

HINSTANCE hInst;
#define szTitle "Fenstertest"
#define szWindowClass "MyWindowClass"


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
PAINTSTRUCT ps;
HDC hdc;

	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_ABOUT:
			MessageBox (NULL, "Copyright by FonzieX!", "Hallo Fred",MB_OK);
			break;
		case IDM_GRAY:
			EnableMenuItem(GetMenu(hWnd), IDM_ABOUT, MF_GRAYED);
			break;
		case IDM_AKTIV:
			EnableMenuItem(GetMenu(hWnd), IDM_ABOUT, MF_ENABLED);
			break;	
		
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// do the painting of the window
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
WNDCLASSEX wcex = {0};

	wcex.cbSize        = sizeof(WNDCLASSEX); 
	wcex.style         = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc   = (WNDPROC)WndProc;
	wcex.hInstance     = hInstance;
	wcex.hIcon         = LoadIcon(hInstance, (LPCTSTR)IDI_RAHMEN);
	wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName  = (LPCSTR)IDC_RAHMEN;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm       = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	return RegisterClassEx(&wcex);
}

BOOL InitMainWindow(HINSTANCE hInstance, int nCmdShow)
{
HWND hWnd;

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd) return FALSE;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine, int       nCmdShow)
{
MSG msg;
HACCEL hAccelTable;

	MyRegisterClass(hInstance);
	hInst = hInstance;

	if (!InitMainWindow (hInstance, nCmdShow)) return FALSE;

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_RAHMEN);

	while (GetMessage(&msg, NULL, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

