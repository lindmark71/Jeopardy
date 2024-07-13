
// JeopardyDlg.h : header file
//

#pragma once
#include "afxwin.h"

// CJeopardyDlg dialog
class CJeopardyDlg : public CDialog
{
// Construction
public:
	CJeopardyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_JEOPARDY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CBrush m_Brush;
	COLORREF m_ForegroundMainColor;
	COLORREF m_BackgroundMainColor;
	COLORREF m_ForegroundDialogColor;
	COLORREF m_BackgroundDialogColor;

	CString csDisplayMode;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()

	void ReadColors();
	COLORREF ColorPick(CString csColor);
	void ReadData();
	void ReadData2();
	void LaunchQADialog(CString csSection, CString csQuestion, CString csAnswer, CString csVideoPath, int score);
	void ShowOutput(int nStatic, CString strTitle, long long int nInput);
	void ResetScore();
	void ResetButtons();
	int CheckDoubleJeopardy(int nScore);
	void SetButtonsRound1();
	void SetButtonsRound2();
	void SetButtonsRound1Christmas();
	int AdjustScore(int nButton);
public:
	LPCWSTR SECTION1;
	LPCWSTR SECTION2;
	LPCWSTR SECTION3;
	LPCWSTR SECTION4;
	LPCWSTR SECTION5;
	LPCWSTR SECTION6;
	LPCWSTR SECTION7;
	LPCWSTR SECTION8;
	LPCWSTR SECTION9;
	LPCWSTR SECTION10;
	LPCWSTR SECTION11;
	LPCWSTR SECTION12;
	LPCWSTR Q1;
	LPCWSTR A1;
	LPCWSTR V1;
	LPCWSTR Q2;
	LPCWSTR A2;
	LPCWSTR V2;
	LPCWSTR Q3;
	LPCWSTR A3;
	LPCWSTR V3;
	LPCWSTR Q4;
	LPCWSTR A4;
	LPCWSTR V4;
	LPCWSTR Q5;
	LPCWSTR A5;
	LPCWSTR V5;
	LPCWSTR TITLE;
	LPCWSTR BLANK_TITLE;
	LPCWSTR JEOPARDY_INI;

	CFont m_csFont;
	CFont m_csTitleFont;
	CFont m_csScoreFont;

	//ROYGBIV
	COLORREF m_color_white;
	COLORREF m_color_black;
	COLORREF m_color_red;
	COLORREF m_color_orange;
	COLORREF m_color_yellow;
	COLORREF m_color_green;
	COLORREF m_color_blue;
	COLORREF m_color_indigo;
	COLORREF m_color_violet;

	CStatic m_csStatic1;
	CStatic m_csStatic2;
	CStatic m_csStatic3;
	CStatic m_csStatic4;
	CStatic m_csStatic5;
	CStatic m_csStatic6;
	CString m_csTitle1;
	CString m_csTitle2;
	CString m_csTitle3;
	CString m_csTitle4;
	CString m_csTitle5;
	CString m_csTitle6;
	int m_nRoundNumber;
	int m_nCurrentScore_1;
	int m_nCurrentScore_2;
	int m_nCurrentScore_3;
	int m_num_buttons_available;
	int m_num_daily_doubles;
	CButton m_CB1;
	CButton m_CB2;
	CButton m_CB3;
	CButton m_CB4;
	CButton m_CB5;
	CButton m_CB6;
	CButton m_CB7;
	CButton m_CB8;
	CButton m_CB9;
	CButton m_CB10;
	CButton m_CB11;
	CButton m_CB12;
	CButton m_CB13;
	CButton m_CB14;
	CButton m_CB15;
	CButton m_CB16;
	CButton m_CB17;
	CButton m_CB18;
	CButton m_CB19;
	CButton m_CB20;
	CButton m_CB21;
	CButton m_CB22;
	CButton m_CB23;
	CButton m_CB24;
	CButton m_CB25;
	CButton m_CB26;
	CButton m_CB27;
	CButton m_CB28;
	CButton m_CB29;
	CButton m_CB30;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonRound2();
	afx_msg void OnBnClickedButtonRound1();
	afx_msg void OnBnClickedButtonTitles();
	afx_msg void OnBnClickedButtonTheme();
	afx_msg void OnBnClickedButtonMusicTest();
};
