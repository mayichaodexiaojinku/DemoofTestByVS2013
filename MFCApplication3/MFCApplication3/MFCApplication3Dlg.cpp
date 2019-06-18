
// MFCApplication3Dlg.cpp : 实现文件
//
#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication3Dlg::IDD, pParent)
	, m_TimeCheck(0)
	, m_ComboEdit(_T(""))
	, m_English(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_DateCheck);
	DDX_Control(pDX, IDC_EDIT1, m_DateEdit);
	DDX_Check(pDX, IDC_CHECK2, m_TimeCheck);
	DDX_Control(pDX, IDC_EDIT2, m_TimeEdit);
	DDX_Control(pDX, IDC_EDIT3, m_ResultEdit);
	DDX_Control(pDX, IDC_COMBO2, m_Record);
	DDX_Text(pDX, IDC_EDIT4, m_ComboEdit);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_CHECK3, &CMFCApplication3Dlg::OnBnClickedCheck3)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication3Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication3Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication3Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication3Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication3Dlg::OnBnClickedRadio1)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	CheckRadioButton(IDC_RADIO4, IDC_RADIO5,IDC_RADIO4);
	CheckRadioButton(IDC_RADIO6, IDC_RADIO7, IDC_RADIO8);
	UpdateData(FALSE);
	m_English = 0;
	m_Record.AddString(_T("85"));
	m_Record.AddString(_T("90"));
	m_Record.AddString(_T("95"));
	m_Record.SelectString(-1, _T("95"));
	UpdateData(FALSE);
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnLbnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication3Dlg::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_DateCheck == TRUE){
		CTime tNow;
		tNow = CTime::GetCurrentTime();
		CString sNow = tNow.Format("%y.%m.%d");
		m_DateEdit.SetSel(0,-1);
		m_DateEdit.ReplaceSel(sNow);
	}
	else{
		m_DateEdit.SetSel(0, -1);
		m_DateEdit.ReplaceSel(_T(""));
	}
	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnBnClickedCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_TimeCheck == TRUE){
		CTime tNow;
		tNow = CTime::GetCurrentTime();
		CString sNow = tNow.Format("%I.%M.%S");
		m_TimeEdit.SetSel(0, -1);
		m_TimeEdit.ReplaceSel(sNow);
	}
	else{
		m_TimeEdit.SetSel(0, -1);
		m_TimeEdit.ReplaceSel(_T(""));
	}
	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
	m_DateEdit.EnableWindow(TRUE);
	m_TimeEdit.EnableWindow(TRUE);
}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
	m_DateEdit.EnableWindow(FALSE);
	m_TimeEdit.EnableWindow(FALSE);
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CHECK1)->EnableWindow(SW_SHOW);
	GetDlgItem(IDC_CHECK2)->EnableWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT1)->EnableWindow(SW_SHOW);
	m_DateEdit.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->EnableWindow(SW_SHOW);
	m_TimeEdit.ShowWindow(SW_SHOW);
}


void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CHECK1)->EnableWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(SW_HIDE);
	m_DateEdit.ShowWindow(SW_HIDE);
	m_TimeEdit.ShowWindow(SW_HIDE);
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	OnOK();
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR sEdit[50];
	int iSexRADIO;
	int iAgeRADIO;
	iSexRADIO = GetCheckedRadioButton(IDC_RADIO4,IDC_RADIO5);
	if (iSexRADIO == IDC_RADIO4)
		_tcscpy(sEdit,L"The boy`s age is ");
	if (iSexRADIO == IDC_RADIO5)
		_tcscpy(sEdit, L"The girl`s age is ");
	iAgeRADIO = GetCheckedRadioButton(IDC_RADIO6,IDC_RADIO8);
	if (iAgeRADIO == IDC_RADIO6)
		_tcscat(sEdit,L"great than 20");
	if (iAgeRADIO == IDC_RADIO7)
		_tcscat(sEdit, L"between 15 to 20");
	if (iAgeRADIO == IDC_RADIO8)
		_tcscat(sEdit, L"less than 15");
	m_ResultEdit.SetSel(0,-1);
	m_ResultEdit.ReplaceSel(sEdit);
}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	TCHAR sCourseEdit[30];
	TCHAR sRecordEdit[15];
	int iCourseRadio = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO3);
	if (iCourseRadio == IDC_RADIO1)
		_tcscpy(sCourseEdit,L"English record is ");
	if (iCourseRadio == IDC_RADIO2)
		_tcscpy(sCourseEdit, L"Computer record is ");
	if (iCourseRadio == IDC_RADIO3)
		_tcscpy(sCourseEdit, L"Natrue record is ");
	m_Record.GetWindowText(sRecordEdit,15);
	_tcscat(sCourseEdit,L"");
    _tcscat(sCourseEdit,sRecordEdit);
	m_ComboEdit = sCourseEdit;
	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnBnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
}
