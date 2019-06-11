// Win32Project1.cpp : ����Ӧ�ó������ڵ㡣
//

/*#include "stdafx.h"
#include "Win32Project1.h"

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
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT1);
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
	RECT rect;
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...
		GetClientRect(hWnd,&rect);
		DrawText(hdc,TEXT("HELLO WORLD"),-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONUP:
		MessageBox(hWnd, TEXT("��������rap������"),TEXT("����̫��"), MB_OK);
		return 0;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("��ȷ��Ҫ�ر���"), TEXT("��ر�"), MB_YESNO) == IDYES)
			DestroyWindow(hWnd);
		else
			return 0;
	case WM_DESTROY:
		    PostQuitMessage(0);
		    return 0;
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
}*/
/*
#include "stdafx.h"


#include<windows.h>
#include<tchar.h>

#include<mmsystem.h>

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("��������"), NULL);
		return 1;
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PtStr;
	HBRUSH hBrush;
	HPEN hPen;
	static int dispMode = 1;
	LPCTSTR str;
	switch (message)
	{
	case WM_LBUTTONDOWN:
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &PtStr);
		dispMode = (dispMode + 1) % 6;
		switch (dispMode)
		{
		case 0:
			str = _T("ӳ�䷽ʽMM_TEXT:ȱʡ��ӳ�䷽ʽ");
			SetMapMode(hDC, MM_TEXT);
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 1:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ20*20��ӳ��Ϊ�ӿڳߴ�Ϊ10*10��ͼ����С1��");
			SetMapMode(hDC, MM_ISOTROPIC);                //����ӳ��ģʽ
			SetWindowExtEx(hDC, 20, 20, NULL);              //���ھ���Ϊ20*20
			SetViewportExtEx(hDC, 10, 10, NULL);            //ӳ��Ϊ�ӿڵľ���Ϊ10*10
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 2:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*20��ͼ��Ŵ�1��");
			SetMapMode(hDC, MM_ISOTROPIC);                //����ӳ��ģʽ
			SetWindowExtEx(hDC, 10, 10, NULL);              //���ھ���Ϊ10*10
			SetViewportExtEx(hDC, 20, 20, NULL);            //ӳ��Ϊ�ӿڵľ���Ϊ20*20
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 3:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*10��ͼ�κ���Ŵ�1�������򲻱�");
			SetMapMode(hDC, MM_ANISOTROPIC);                //����ӳ��ģʽ
			SetWindowExtEx(hDC, 10, 10, NULL);              //���ھ���Ϊ10*10
			SetViewportExtEx(hDC, 20, 10, NULL);            //ӳ��Ϊ�ӿڵľ���Ϊ20*10
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 4:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*5��ͼ�κ���Ŵ�1����������С1��");
			SetMapMode(hDC, MM_ANISOTROPIC);                //����ӳ��ģʽ
			SetWindowExtEx(hDC, 10, 10, NULL);              //���ھ���Ϊ10*10
			SetViewportExtEx(hDC, 20, 5, NULL);            //ӳ��Ϊ�ӿڵľ���Ϊ20*5
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 5:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*5��ͼ�κ���Ŵ�1�������򲻱�");
			SetMapMode(hDC, MM_ISOTROPIC);                //����ӳ��ģʽ
			SetWindowExtEx(hDC, 10, 10, NULL);              //���ھ���Ϊ10*10
			SetViewportExtEx(hDC, 20, 5, NULL);            //ӳ��Ϊ�ӿڵľ���Ϊ20*5
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		}
		hPen = (HPEN)GetStockObject(BLACK_PEN);  //���û���ΪϵͳԤ����ĺ�ɫ����
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);  //���ɫ��ˢ
		SelectObject(hDC, hBrush);   //ѡ��ˢ
		SelectObject(hDC, hPen);   //ѡ�񻭱�
		RoundRect(hDC, 50, 120, 100, 200, 15, 15);  //Բ�Ǿ���
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //���ɫ��ˢ
		SelectObject(hDC, hBrush);   //ѡ��ˢ
		Ellipse(hDC, 150, 50, 200, 150);  //��Բ
		hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);  //����ϵͳԤ������黯ˢ
		SelectObject(hDC, hBrush);   //ѡ��ˢ
		Pie(hDC, 250, 50, 300, 100, 250, 20, 300, 50);  //����
		EndPaint(hWnd, &PtStr);       //������ͼ
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		//����PostQuitMessage����WM_QUIT��Ϣ
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);//Ĭ��ʱ����ϵͳ��ϢĬ�ϴ�����
		break;
	}
	return 0;
}
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	TCHAR szWindowClass[] = L"����ʾ��";
	TCHAR szTitle[] = L"ӳ��ģʽ�����ʾ��ͼ";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex))
		return FALSE;
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}
*/

#include "stdafx.h"
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define PI 3.1415926 
long WINAPI WndProc(HWND hWnd,UINT iMessage,UINT wParam,LONG lParam); 
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{	
	MSG Message;	
	HWND hwnd;	
	WNDCLASS wndclass;	
	wndclass.cbClsExtra = 0;	
	wndclass.cbWndExtra = 0;	
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);	
	wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = _T("SS");
	wndclass.lpszMenuName = NULL;
	wndclass.style = 0;		
	if(!RegisterClass(&wndclass))	{
		MessageBeep(0);		
		return FALSE;	
	}	
	hwnd = CreateWindow(_T("SS"),_T("�����"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd,nCmdShow);	
	UpdateWindow(hwnd); 
	while(GetMessage(&Message,0,0,0)){
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}	
	return Message.wParam;
}
long WINAPI WndProc(HWND hWnd,UINT iMessage,UINT wParam,LONG lParam)
{	
	HDC hDC;
	HBRUSH hBrush;	
	HPEN hPen;	
	PAINTSTRUCT PtStr;	
	int i=0,j=0;	//������ζ���	
	POINT ww[5];	//������ζ���	
	POINT nw[5];	//�����ζ���	
	POINT s[3];	   //��������	
	POINT line[2];	//��Բ�뾶	
	double rw = 200.0;	//��Բ�뾶	
	double rn = rw*sin(PI/180*18)/cos(PI/180*36);		//���㶥���ֵ	
	for(i=0;i<5;i++){
		ww[i].x = (long)(rw*cos(i*72.0/180*PI));
		ww[i].y = (long)(rw*sin(i*72.0/180*PI));
		nw[i].x = (long)(rn*cos(i*72.0/180*PI+36.0/180*PI));
		nw[i].y = (long)(rn*sin(i*72.0/180*PI+36.0/180*PI));	
	} 	
	switch(iMessage){
	   case WM_PAINT:
		   hDC = BeginPaint(hWnd,&PtStr);		
		   SetMapMode(hDC,MM_ANISOTROPIC);		//����ԭ�����꣨-300,-200��
		   SetWindowOrgEx(hDC,-300,-200,NULL);				
		   hPen = CreatePen(PS_SOLID,1,RGB(255,0,0));		
		   SelectObject(hDC,hPen);		//1.�����������		
		   Polygon(hDC,ww,5);		//2.�����ڵ�����		
		   for(j=0;j<5;j++){
			   DeleteObject(hPen);			//��ͬ��ɫ�Ļ���			
			   hPen = CreatePen(PS_SOLID,1,RGB((j*50)%255,(j*30)%255,(j*20)%255));		
			   SelectObject(hDC,hPen);		
			   line[0] = ww[j%5];			
			   line[1] = ww[(j+2)%5];		
			   Polyline(hDC,line,2);		
			   Sleep(1000);		
		   }		
		   //3.�ò�ͬ�Ļ�ˢ��ɫ����������������γɵ�ͼ���е�ÿһ������		
		   //3.1��ӵ��������Բ�����������		
		   for(i=0;i<5;i++){ 
			   s[0] = ww[i%5];
			   s[1] = nw[i%5];
			   s[2] = ww[(i+1)%5];
			   hBrush = CreateSolidBrush(RGB((i* 80) % 255 , (i * 60) % 255 , (i * 40)% 255));
			   SelectObject(hDC , hBrush);	
			   Polygon(hDC,s,3);		
			   Sleep(100);		
		   }		
		   //3.2��ӵ��һ����Բ����
		   for (i = 0 ; i <5 ; i++){
			   if(i-1 == -1){
				   s[0] = ww[i%5];	
				   s[1] = nw[(i)%5];
				   s[2] = nw[(4)%5];
			   }else{		
				   s[0] = ww[i%5];
				   s[1] = nw[(i) % 5];
				   s[2] = nw[(i-1)%5];	
			   }						
			   DeleteObject(hPen);		
			   hBrush = CreateSolidBrush(RGB((89 + i * 80) % 255 , (70 + i * 60) % 255 , (130 + i * 60)% 255));	
			   SelectObject(hDC,hBrush);		
			   Polygon(hDC,s,3);		
			   Sleep(100);		
		   }		
		   //3.3���м�������		
		   hBrush = CreateSolidBrush(RGB(255,0,0));		
		   SelectObject(hDC , hBrush);	
		   Polygon(hDC,nw,5); 		
		   DeleteObject(hPen);	
		   DeleteObject(hBrush);
		   EndPaint(hWnd,&PtStr);
		   return 0;	
	   case WM_DESTROY:	
		   PostQuitMessage(0);	
		   return 0;	
	   default:		
		   return(DefWindowProc(hWnd,iMessage,wParam,lParam));	
	}
}
/*
#include<windows.h>
#include "stdafx.h"
#include<stdlib.h>

#include<string.h>

#include<math.h>

#define Pi 3.1415926

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam);
double dfTheta = 0, dfRange = 100.0;
long i = 0, j = 0;
long lCentreX = 0, lCentreY = 0, lRadious = (long)(0.2*dfRange);
POINT lpSin[100];
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG Message;
	WNDCLASS wndclass;
	wndclass.cbClsExtra = 0;                  //����������չ
	wndclass.cbWndExtra = 0;               //����ʵ������չ
	wndclass.hInstance = hInstance;       //��ǰʵ�����
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);      //���ڲ��ü�ͷ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //���ڱ���Ϊ��ɫ
	wndclass.lpszMenuName = NULL; //�������޲˵�
	wndclass.lpszClassName = _T("SIN");  //��������Ϊ"����"
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //���ڵ���С��ͼ��Ϊȱʡͼ��
	wndclass.lpfnWndProc = WndProc;   //���崰�ڴ�����
	wndclass.style = 0;
	if (!RegisterClass(&wndclass))       //���ע��ʧ���򷢳�����
	{
		MessageBeep(0);
		return FALSE;
	}

	//---------------- �������� -------------------

	hwnd = CreateWindow(
		_T("SIN"),        //��������
		_T("�������ƶ�"),                  //����ʵ���ı�����
		WS_OVERLAPPEDWINDOW,   //���ڵķ��
		CW_USEDEFAULT,
		0,      //�������Ͻ�����Ϊȱʡֵ
		CW_USEDEFAULT,
		0,      //���ڵĸߺͿ�Ϊȱʡֵ
		NULL,                          //�˴����޸�����
		NULL,                          //�˴��������˵�
		hInstance,              //�����˴��ڵ�Ӧ�ó���ĵ�ǰ���
		NULL                          //��ʹ�ø�ֵ
		);

	//--------------- ��ʾ���� ----------------------
	ShowWindow(hwnd, nCmdShow);
	//-------------- �����û��� ---------------------
	UpdateWindow(hwnd);
	//--------------- ��Ϣѭ�� ----------------------
	for (int j = 0; j<100; j++)    //�����������ߵĵ�����
	{
		lpSin[j].x = (long)(j * 2 * Pi / 100 * 60);
		lpSin[j].y = (long)(dfRange*sin(j * 2 * Pi / 100));
	}

	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;       //��Ϣѭ��������������ֹʱ����Ϣ����ϵͳ
}

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
	HDC hDC;                   //����ָ���豸�ľ��
	HBRUSH hBrush;     //����ָ��ˢ�ľ��
	HPEN hPen;                 //����ָ�򻭱ʵľ��
	PAINTSTRUCT PtStr;//����ָ�������ͼ��Ϣ�Ľṹ�����
	switch (iMessage)                                             //������Ϣ
	{
	case WM_PAINT:                                         //�����ͼ��Ϣ
		hDC = BeginPaint(hWnd, &PtStr);
		SetWindowOrgEx(hDC, -200, -200, NULL);       //����ӳ��ģʽ
		hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));         //��ɫ����
		SelectObject(hDC, hPen);       //ѡ�񻭱�
		Polyline(hDC, lpSin, 100);
		if (i <= 25)                       //��һ��1/4����
		{
			hPen = CreatePen(PS_DASH, 1, RGB(125, 0, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(125, 0, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//����뾶
		}
		else if (i <= 50)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 125, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 125, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//����뾶
		}
		else if (i <= 75)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 125));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 125));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//����뾶
		}
		else
		{
			hPen = CreatePen(PS_DASH, 1, RGB(255, 255, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 255, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//����뾶
		}
		SelectObject(hDC, hBrush);     //ѡ��ˢ
		SelectObject(hDC, hPen);
		lCentreX = lpSin[i].x;                  //Բ��x����
		lCentreY = lpSin[i].y;              //Բ��y����
		Ellipse(hDC, lCentreX - lRadious, lCentreY - lRadious,
			lCentreX + lRadious, lCentreY + lRadious);   //��Բ
		i++;
		DeleteObject(hPen);               //ɾ������
		DeleteObject(hBrush);  //ɾ����ˢ
		EndPaint(hWnd, &PtStr);       //ɾ���豸����ָ��
		Sleep(100);                    //ͣ0.1��
		if (i<100) InvalidateRect(hWnd, NULL, 1);         //ˢ���û���
		return 0;
	case WM_DESTROY:          //�رմ���
		PostQuitMessage(0);
		return 0;
	default:
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}*/