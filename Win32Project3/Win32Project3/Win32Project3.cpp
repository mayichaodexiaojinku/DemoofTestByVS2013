// Win32Project3.cpp : 定义应用程序的入口点。
//
/*
#include "stdafx.h"
#include "Win32Project3.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT3);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HPEN hPen;
	HBRUSH hBrush;
	static char cUp[] = "You had hitted the key up";
	static char cCtrl[] = "You had hitted the CTRL key";
	static char cShift[] = "You had hitted the SHIFT key";
	static char cCtrl_A[] = "You had hitted the Ctrl+A key";
	static char cShift_B[] = "You had hitted the SHIFT+B key";
	static bool nUpKeyDown = false,
		nShiftKeyDown = false,
		nCtrlKeyDown = false,
		nShiftBKeyDown = false,
		nCtrlAKeyDown = false;

	switch (message)
	{
	case WM_KEYDOWN:
	{
					   switch (wParam)
					   {
					   case VK_UP:
						   nUpKeyDown = true;
						   break;
					   case VK_SHIFT:
						   nShiftKeyDown = true;
					   case VK_CONTROL:
						   nCtrlKeyDown = true;
					   default:
						   break;
					   }
    }
		break;
	case WM_KEYUP:
		InvalidateRect(hWnd,NULL,false);
		break;
	case WM_CHAR:
		if (wParam == (65 & VK_CONTROL)){
			nCtrlAKeyDown = true;
			nCtrlKeyDown = false;
		}
		if (wParam == 98 || wParam == 66){
			if (nShiftKeyDown == true){
				nShiftBKeyDown = true;
				nShiftKeyDown = false;
			}
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  在此添加任意绘图代码...
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
		hPen = (HPEN)GetStockObject(WHITE_PEN);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		if (nUpKeyDown == true){
			Rectangle(hdc,0,0,300,200);
			TextOut(hdc,0,100,cUp,strlen(cUp));
			nUpKeyDown = false;
		}
		else if (nCtrlAKeyDown == true){
			TextOut(hdc, 0, 200, cCtrl_A, strlen(cCtrl_A));
			nCtrlAKeyDown = false;
			nCtrlKeyDown = false;
		}
		else if(nCtrlKeyDown == true &&	nCtrlAKeyDown == false){
			TextOut(hdc, 0, 300, cCtrl, strlen(cCtrl));
			nCtrlKeyDown = false;
		}
		else if(nShiftBKeyDown == true){
			TextOut(hdc, 0, 400, cShift_B, strlen(cShift_B));
			nShiftBKeyDown = false;
			nShiftKeyDown = false;
		}
		else if (nShiftKeyDown == true && nShiftBKeyDown == false){
			TextOut(hdc, 0, 500, cShift, strlen(cShift));
			nShiftKeyDown = false;
		}
		else{
			printf("error");
		}
		DeleteObject(hPen);
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
*/


#include "stdafx.h"
#include "Win32Project3.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT3));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT3);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	WORD x, y;
	HCURSOR hCursor;
	HBRUSH hBrush;
	LPSIZE lpSize = NULL;
	RECT ClientRect;
	static char cLeft[] = "LEFT BUTTON";
	static char cRight[] = "RIGHT BUTTON";
	static bool nLeftDown = false, nRightDown = false;;
	switch (message)
	{
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		GetClientRect(hWnd,&ClientRect);
		if (y > 0 && y <= ClientRect.bottom){
			if (y >= 0 && y <= ClientRect.bottom / 5){
				hCursor = LoadCursor(NULL,IDC_ARROW);
				SetCursor(hCursor);
			}
			else if (y >= ClientRect.bottom / 5 && y <= ClientRect.bottom / 5*2){
				hCursor = LoadCursor(NULL, IDC_CROSS);
				SetCursor(hCursor);
			}
			else if (y >= ClientRect.bottom / 5 *2 && y <= ClientRect.bottom / 5 * 3){
				hCursor = LoadCursor(NULL, IDC_SIZENESW);
				SetCursor(hCursor);
			}
			else if (y >= ClientRect.bottom / 5 * 3 && y <= ClientRect.bottom / 5 * 4){
				hCursor = LoadCursor(NULL, IDC_SIZENS);
				SetCursor(hCursor);
			}
			else {
				hCursor = LoadCursor(NULL, IDC_WAIT);
				SetCursor(hCursor);
			}
		}
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc, 0, 0, cLeft, strlen(cLeft));
		ReleaseDC(hWnd,hdc);
		break;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hWnd);
		TextOut(hdc, 0, 0, cRight, strlen(cRight));
		ReleaseDC(hWnd, hdc);
		break;
	case WM_SIZE:
		hdc = GetDC(hWnd);
		SetMapMode(hdc, MM_ANISOTROPIC);
		SetViewportExtEx(hdc,LOWORD(lParam),HIWORD(lParam),lpSize);
		SetWindowExtEx(hdc,100,50,lpSize);
		hBrush = CreateSolidBrush(RGB(255,255,255));
		SelectObject(hdc,hBrush);
		Rectangle(hdc,0,0,100,10);
		DeleteObject(hBrush);

		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, 0, 10, 100, 20);
		DeleteObject(hBrush);

		hBrush = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, 0, 20, 100, 30);
		DeleteObject(hBrush);

		hBrush = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, 0, 30, 100, 40);
		DeleteObject(hBrush);

		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, 0, 40, 100, 50);
		DeleteObject(hBrush);
		ReleaseDC(hWnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

