#pragma once
#include "afxwin.h"


// CQADialog dialog

class CQADialog : public CDialog
{
	DECLARE_DYNAMIC(CQADialog)

public:
	CQADialog(CWnd* pParent = NULL, COLORREF foreground = RGB(0,0,0), COLORREF background = RGB(255,255,255));   // standard constructor
	virtual ~CQADialog();
	BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

// Dialog Data
	enum { IDD = IDD_DIALOG_QA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_csStaticQ;
	CStatic m_csStaticA;
	afx_msg void OnBnClickedButtonA();
	void SetStaticQ(CString csInput);
	void SetStaticA(CString csInput);
	void SetStaticV(CString csInput);
	CString m_csQ;
	CString m_csA;
	CString m_csV;
	CFont m_csFont;
	bool m_bTitleMode;
	CButton m_cbAnswer;
	CBrush m_Brush;
	COLORREF m_BackgroundColor;
	COLORREF m_ForegroundColor;
	int team_1_return_value;
	int team_2_return_value;
	int team_3_return_value;
	afx_msg void OnBnClickedButtonV();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnT1Correct();
	afx_msg void OnBnClickedBtnT1Incorrect();
	afx_msg void OnBnClickedBtnT2Correct();
	afx_msg void OnBnClickedBtnT2Incorrect();
	afx_msg void OnBnClickedBtnT3Correct();
	afx_msg void OnBnClickedBtnT3Incorrect();
};
