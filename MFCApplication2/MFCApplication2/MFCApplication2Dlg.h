
// MFCApplication2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCApplication2Dlg �Ի���
class CMFCApplication2Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	CButton m_btn1;
	afx_msg void OnBnClickedButton5();
	CButton m_btn2;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio1();
	CButton m_chk1;
	int m_rad1;
	int m_rad2;
};
