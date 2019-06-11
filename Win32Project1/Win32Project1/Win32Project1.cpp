// Win32Project1.cpp : 定义应用程序的入口点。
//

/*#include "stdafx.h"
#include "Win32Project1.h"

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
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT1);
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
	RECT rect;
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
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
		// TODO:  在此添加任意绘图代码...
		GetClientRect(hWnd,&rect);
		DrawText(hdc,TEXT("HELLO WORLD"),-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONUP:
		MessageBox(hWnd, TEXT("唱、跳、rap、篮球"),TEXT("及你太美"), MB_OK);
		return 0;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("请确认要关闭吗？"), TEXT("请关闭"), MB_YESNO) == IDYES)
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
		MessageBox(NULL, _T("创建窗口失败！"), _T("创建窗口"), NULL);
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
			str = _T("映射方式MM_TEXT:缺省的映射方式");
			SetMapMode(hDC, MM_TEXT);
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 1:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为20*20，映射为视口尺寸为10*10，图像缩小1倍");
			SetMapMode(hDC, MM_ISOTROPIC);                //设置映射模式
			SetWindowExtEx(hDC, 20, 20, NULL);              //窗口矩形为20*20
			SetViewportExtEx(hDC, 10, 10, NULL);            //映射为视口的矩形为10*10
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 2:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*20，图像放大1倍");
			SetMapMode(hDC, MM_ISOTROPIC);                //设置映射模式
			SetWindowExtEx(hDC, 10, 10, NULL);              //窗口矩形为10*10
			SetViewportExtEx(hDC, 20, 20, NULL);            //映射为视口的矩形为20*20
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 3:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*10，图形横向放大1倍，纵向不变");
			SetMapMode(hDC, MM_ANISOTROPIC);                //设置映射模式
			SetWindowExtEx(hDC, 10, 10, NULL);              //窗口矩形为10*10
			SetViewportExtEx(hDC, 20, 10, NULL);            //映射为视口的矩形为20*10
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 4:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*5，图形横向放大1倍，纵向缩小1倍");
			SetMapMode(hDC, MM_ANISOTROPIC);                //设置映射模式
			SetWindowExtEx(hDC, 10, 10, NULL);              //窗口矩形为10*10
			SetViewportExtEx(hDC, 20, 5, NULL);            //映射为视口的矩形为20*5
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		case 5:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*5，图形横向放大1倍，纵向不变");
			SetMapMode(hDC, MM_ISOTROPIC);                //设置映射模式
			SetWindowExtEx(hDC, 10, 10, NULL);              //窗口矩形为10*10
			SetViewportExtEx(hDC, 20, 5, NULL);            //映射为视口的矩形为20*5
			TextOut(hDC, 0, 0, str, _tcsclen(str));
			break;
		}
		hPen = (HPEN)GetStockObject(BLACK_PEN);  //设置画笔为系统预定义的黑色画笔
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);  //深灰色画刷
		SelectObject(hDC, hBrush);   //选择画刷
		SelectObject(hDC, hPen);   //选择画笔
		RoundRect(hDC, 50, 120, 100, 200, 15, 15);  //圆角矩形
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //深灰色画刷
		SelectObject(hDC, hBrush);   //选择画刷
		Ellipse(hDC, 150, 50, 200, 150);  //椭圆
		hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);  //采用系统预定义的虚化刷
		SelectObject(hDC, hBrush);   //选择画刷
		Pie(hDC, 250, 50, 300, 100, 250, 20, 300, 50);  //饼形
		EndPaint(hWnd, &PtStr);       //结束绘图
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		//调用PostQuitMessage发出WM_QUIT消息
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);//默认时采用系统消息默认处理函数
		break;
	}
	return 0;
}
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	TCHAR szWindowClass[] = L"窗口示例";
	TCHAR szTitle[] = L"映射模式及填充示例图";
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
	hwnd = CreateWindow(_T("SS"),_T("五边形"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,NULL);
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
	int i=0,j=0;	//外五边形顶点	
	POINT ww[5];	//内五边形顶点	
	POINT nw[5];	//三角形顶点	
	POINT s[3];	   //两点连线	
	POINT line[2];	//外圆半径	
	double rw = 200.0;	//内圆半径	
	double rn = rw*sin(PI/180*18)/cos(PI/180*36);		//计算顶点的值	
	for(i=0;i<5;i++){
		ww[i].x = (long)(rw*cos(i*72.0/180*PI));
		ww[i].y = (long)(rw*sin(i*72.0/180*PI));
		nw[i].x = (long)(rn*cos(i*72.0/180*PI+36.0/180*PI));
		nw[i].y = (long)(rn*sin(i*72.0/180*PI+36.0/180*PI));	
	} 	
	switch(iMessage){
	   case WM_PAINT:
		   hDC = BeginPaint(hWnd,&PtStr);		
		   SetMapMode(hDC,MM_ANISOTROPIC);		//设置原点坐标（-300,-200）
		   SetWindowOrgEx(hDC,-300,-200,NULL);				
		   hPen = CreatePen(PS_SOLID,1,RGB(255,0,0));		
		   SelectObject(hDC,hPen);		//1.绘制外五边形		
		   Polygon(hDC,ww,5);		//2.不相邻点连线		
		   for(j=0;j<5;j++){
			   DeleteObject(hPen);			//不同颜色的画笔			
			   hPen = CreatePen(PS_SOLID,1,RGB((j*50)%255,(j*30)%255,(j*20)%255));		
			   SelectObject(hDC,hPen);		
			   line[0] = ww[j%5];			
			   line[1] = ww[(j+2)%5];		
			   Polyline(hDC,line,2);		
			   Sleep(1000);		
		   }		
		   //3.用不同的画刷颜色填充用上述方法所形成的图形中的每一个区域		
		   //3.1画拥有两个外圆顶点的三角形		
		   for(i=0;i<5;i++){ 
			   s[0] = ww[i%5];
			   s[1] = nw[i%5];
			   s[2] = ww[(i+1)%5];
			   hBrush = CreateSolidBrush(RGB((i* 80) % 255 , (i * 60) % 255 , (i * 40)% 255));
			   SelectObject(hDC , hBrush);	
			   Polygon(hDC,s,3);		
			   Sleep(100);		
		   }		
		   //3.2画拥有一个外圆顶点
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
		   //3.3画中间的五边形		
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
	wndclass.cbClsExtra = 0;                  //窗口类无扩展
	wndclass.cbWndExtra = 0;               //窗口实例无扩展
	wndclass.hInstance = hInstance;       //当前实例句柄
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);      //窗口采用箭头光标
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //窗口背景为白色
	wndclass.lpszMenuName = NULL; //窗口中无菜单
	wndclass.lpszClassName = _T("SIN");  //窗口类名为"窗口"
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //窗口的最小化图标为缺省图标
	wndclass.lpfnWndProc = WndProc;   //定义窗口处理函数
	wndclass.style = 0;
	if (!RegisterClass(&wndclass))       //如果注册失败则发出警告
	{
		MessageBeep(0);
		return FALSE;
	}

	//---------------- 创建窗口 -------------------

	hwnd = CreateWindow(
		_T("SIN"),        //窗口类名
		_T("沿正弦移动"),                  //窗口实例的标题名
		WS_OVERLAPPEDWINDOW,   //窗口的风格
		CW_USEDEFAULT,
		0,      //窗口左上角坐标为缺省值
		CW_USEDEFAULT,
		0,      //窗口的高和宽为缺省值
		NULL,                          //此窗口无父窗口
		NULL,                          //此窗口无主菜单
		hInstance,              //创建此窗口的应用程序的当前句柄
		NULL                          //不使用该值
		);

	//--------------- 显示窗口 ----------------------
	ShowWindow(hwnd, nCmdShow);
	//-------------- 绘制用户区 ---------------------
	UpdateWindow(hwnd);
	//--------------- 消息循环 ----------------------
	for (int j = 0; j<100; j++)    //生成正弦曲线的点坐标
	{
		lpSin[j].x = (long)(j * 2 * Pi / 100 * 60);
		lpSin[j].y = (long)(dfRange*sin(j * 2 * Pi / 100));
	}

	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;       //消息循环结束即程序终止时将信息返回系统
}

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
	HDC hDC;                   //定义指向设备的句柄
	HBRUSH hBrush;     //定义指向画刷的句柄
	HPEN hPen;                 //定义指向画笔的句柄
	PAINTSTRUCT PtStr;//定义指向包含绘图信息的结构体变量
	switch (iMessage)                                             //处理消息
	{
	case WM_PAINT:                                         //处理绘图消息
		hDC = BeginPaint(hWnd, &PtStr);
		SetWindowOrgEx(hDC, -200, -200, NULL);       //设置映像模式
		hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));         //黑色画笔
		SelectObject(hDC, hPen);       //选择画笔
		Polyline(hDC, lpSin, 100);
		if (i <= 25)                       //第一个1/4周期
		{
			hPen = CreatePen(PS_DASH, 1, RGB(125, 0, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(125, 0, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//计算半径
		}
		else if (i <= 50)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 125, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 125, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//计算半径
		}
		else if (i <= 75)
		{
			hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 125));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 125));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//计算半径
		}
		else
		{
			hPen = CreatePen(PS_DASH, 1, RGB(255, 255, 0));
			hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 255, 0));
			lRadious = (long)(dfRange*0.2 + i % 25 * dfRange*0.4 / 25);//计算半径
		}
		SelectObject(hDC, hBrush);     //选择画刷
		SelectObject(hDC, hPen);
		lCentreX = lpSin[i].x;                  //圆心x坐标
		lCentreY = lpSin[i].y;              //圆心y坐标
		Ellipse(hDC, lCentreX - lRadious, lCentreY - lRadious,
			lCentreX + lRadious, lCentreY + lRadious);   //画圆
		i++;
		DeleteObject(hPen);               //删除画笔
		DeleteObject(hBrush);  //删除画刷
		EndPaint(hWnd, &PtStr);       //删除设备环境指针
		Sleep(100);                    //停0.1秒
		if (i<100) InvalidateRect(hWnd, NULL, 1);         //刷新用户区
		return 0;
	case WM_DESTROY:          //关闭窗口
		PostQuitMessage(0);
		return 0;
	default:
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
}*/