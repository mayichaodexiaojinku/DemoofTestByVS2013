#define _CRT_SECURE_NO_WARNINGS

// MFCApplication3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <string.h>

// CMFCApplication3Dlg �Ի���
class CMFCApplication3Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

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
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck1();
	int m_DateCheck;
	afx_msg void OnBnClickedCheck2();
	CEdit m_DateEdit;
	int m_TimeCheck;
	CEdit m_TimeEdit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	CEdit m_ResultEdit;
	afx_msg void OnBnClickedButton7();
	CComboBox m_Record;
	CString m_ComboEdit;
	afx_msg void OnBnClickedRadio1();
	int m_English;
};
