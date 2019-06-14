// Win32Project3.cpp : ����Ӧ�ó������ڵ㡣
//
/*
#include "stdafx.h"
#include "Win32Project3.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
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

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// ����Ϣѭ��: 
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
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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
		// TODO:  �ڴ���������ͼ����...
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

// �����ڡ������Ϣ�������
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

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
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

	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT3, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT3));

	// ����Ϣѭ��: 
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
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
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

// �����ڡ������Ϣ�������
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

