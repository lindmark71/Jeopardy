#pragma once


// DailyDouble dialog

class DailyDouble : public CDialog
{
	DECLARE_DYNAMIC(DailyDouble)

public:
	DailyDouble(CWnd* pParent = nullptr, COLORREF foreground = RGB(0, 0, 0), COLORREF background = RGB(255, 255, 255));   // standard constructor
	virtual ~DailyDouble();
	BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditAmount();
	CString m_csAmount;
	CBrush m_Brush;
	COLORREF m_BackgroundColor;
	COLORREF m_ForegroundColor;


	CButton m_CB1;
};
