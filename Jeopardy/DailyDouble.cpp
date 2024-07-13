// DailyDouble.cpp : implementation file
//

#include "stdafx.h"
#include "Jeopardy.h"
#include "DailyDouble.h"
#include "afxdialogex.h"
#include <Mmsystem.h>
//#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

// DailyDouble dialog

IMPLEMENT_DYNAMIC(DailyDouble, CDialog)

DailyDouble::DailyDouble(CWnd* pParent /*=nullptr*/, COLORREF foreground, COLORREF background)
	: CDialog(IDD_DIALOG_DD, pParent)
	, m_csAmount(_T(""))
{
	m_BackgroundColor = background;
	m_ForegroundColor = foreground;
	m_Brush.CreateSolidBrush(m_BackgroundColor);
}

DailyDouble::~DailyDouble()
{
}

BOOL DailyDouble::OnInitDialog()
{
	BOOL bReturn = (CDialog::OnInitDialog());
	PlaySound(L"C:\\dev\\Jeopardy_deploy\\media\\Jeopardy_Daily_Double_Sound_effect.wav", NULL, SND_APPLICATION);
	CBitmap bitmap1;
	bitmap1.LoadBitmapW(IDB_BIT_DD);
	HBITMAP hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
	m_CB1.ModifyStyle(0, BS_BITMAP);
	m_CB1.SetBitmap(hBmp1);
	return bReturn;
}

void DailyDouble::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AMOUNT, m_csAmount);
	DDX_Control(pDX, IDC_BUTTON1, m_CB1);
}

HBRUSH DailyDouble::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(m_ForegroundColor);
		pDC->SetBkColor(m_BackgroundColor);
		break;
	default:
		break;
	}
	return (HBRUSH)m_Brush;
}

BEGIN_MESSAGE_MAP(DailyDouble, CDialog)
	ON_EN_CHANGE(IDC_EDIT_AMOUNT, &DailyDouble::OnEnChangeEditAmount)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// DailyDouble message handlers


void DailyDouble::OnEnChangeEditAmount()
{

}
