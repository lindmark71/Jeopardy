// QADialog.cpp : implementation file
//

#include "stdafx.h"
#include "Jeopardy.h"
#include "QADialog.h"
#include <string>
//#include <unistd.h>

// CQADialog dialog

IMPLEMENT_DYNAMIC(CQADialog, CDialog)

CQADialog::CQADialog(CWnd* pParent /*=NULL*/, COLORREF foreground, COLORREF background)
	: CDialog(CQADialog::IDD, pParent)
	, m_csQ(_T(""))
	, m_csA(_T(""))
{

	const CString sFont = L"Arial";

	m_csFont.CreateFontW(
		/* int nHeight,          */64, 
		/* int nWidth,           */0, 
		/* int nEscapement,      */0, 
		/* int nOrientation,     */0, 
		/* int nWeight,          */FW_NORMAL, 
		/* BYTE bItalic,         */FALSE, 
		/* BYTE bUnderline,      */FALSE, 
		/* BYTE cStrikeOut,      */FALSE, 
		/* BYTE nCharSet,        */ANSI_CHARSET, 
		/* BYTE nOutPrecision,   */OUT_DEFAULT_PRECIS, 
		/* BYTE nClipPrecision,  */CLIP_DEFAULT_PRECIS, 
		/* BYTE nQuality,        */DEFAULT_QUALITY, 
		/* BYTE nPitchAndFamily, */DEFAULT_PITCH, 
		/* LPCTSTR lpszFacename);*/sFont
		);

    m_bTitleMode = false;
	m_BackgroundColor = background;
	m_ForegroundColor = foreground;
	m_Brush.CreateSolidBrush(m_BackgroundColor);
}

CQADialog::~CQADialog()
{
}

BOOL CQADialog::OnInitDialog()
{
	BOOL bReturn = (CDialog::OnInitDialog());
	m_csStaticQ.SetFont(&m_csFont,true);
	if (true == m_bTitleMode)
	{
		GetDlgItem(IDOK)->SetWindowTextW(_T("Close"));
		m_cbAnswer.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_V)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T1_CORRECT)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T1_INCORRECT)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T2_CORRECT)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T2_INCORRECT)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T3_CORRECT)->ShowWindow(false);
		GetDlgItem(IDC_BTN_T3_INCORRECT)->ShowWindow(false);

	}
	else
	if ((m_csV == "none") || (m_csV == ""))
	{
		GetDlgItem(IDC_BUTTON_V)->ShowWindow(false);
	}
	else
	{
		OnBnClickedButtonV();
	}
	team_1_return_value = 0;
	team_2_return_value = 0;
	team_3_return_value = 0;

	return bReturn;
}

void CQADialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Q, m_csStaticQ);
	DDX_Control(pDX, IDC_STATIC_A, m_csStaticA);
	DDX_Text(pDX, IDC_STATIC_Q, m_csQ);
	DDX_Text(pDX, IDC_STATIC_A, m_csA);
	DDX_Control(pDX, IDC_BUTTON_A, m_cbAnswer);
}


BEGIN_MESSAGE_MAP(CQADialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_A, &CQADialog::OnBnClickedButtonA)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_V, &CQADialog::OnBnClickedButtonV)
	ON_BN_CLICKED(IDOK, &CQADialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_T1_CORRECT, &CQADialog::OnBnClickedBtnT1Correct)
	ON_BN_CLICKED(IDC_BTN_T1_INCORRECT, &CQADialog::OnBnClickedBtnT1Incorrect)
	ON_BN_CLICKED(IDC_BTN_T2_CORRECT, &CQADialog::OnBnClickedBtnT2Correct)
	ON_BN_CLICKED(IDC_BTN_T2_INCORRECT, &CQADialog::OnBnClickedBtnT2Incorrect)
	ON_BN_CLICKED(IDC_BTN_T3_CORRECT, &CQADialog::OnBnClickedBtnT3Correct)
	ON_BN_CLICKED(IDC_BTN_T3_INCORRECT, &CQADialog::OnBnClickedBtnT3Incorrect)
END_MESSAGE_MAP()


// CQADialog message handlers

void CQADialog::OnBnClickedButtonA()
{
	m_csStaticA.SetFont(&m_csFont,true);
	m_csStaticA.ShowWindow(SW_SHOW);
}
void CQADialog::SetStaticQ(CString csInput)
{
	m_csQ = csInput;
}
void CQADialog::SetStaticA(CString csInput)
{
	m_csA = csInput;
}
void CQADialog::SetStaticV(CString csInput)
{
	m_csV = csInput;
}
HBRUSH CQADialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CQADialog::OnBnClickedButtonV()
{
	CString csLaunchCommand;
	CString csParameter;
	csLaunchCommand += "C:\\dev\\Jeopardy_deploy\\wmplayer\\wmplayer.exe";
	csParameter = " ";
	csParameter += m_csV;

	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	if (CreateProcess(csLaunchCommand.GetBuffer(), csParameter.GetBuffer(), NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
	else
	{
		DWORD dWord = GetLastError();
		int i = 0;
	}
}


void CQADialog::OnBnClickedOk()
{
	CDialog::OnOK();
}

void CQADialog::OnBnClickedBtnT1Correct()
{
	team_1_return_value = 1;
	GetDlgItem(IDC_BTN_T1_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T1_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_INCORRECT)->EnableWindow(false);
}


void CQADialog::OnBnClickedBtnT1Incorrect()
{
	team_1_return_value = -1;
	GetDlgItem(IDC_BTN_T1_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T1_INCORRECT)->EnableWindow(false);
}


void CQADialog::OnBnClickedBtnT2Correct()
{
	team_2_return_value = 1;
	GetDlgItem(IDC_BTN_T1_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T1_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_INCORRECT)->EnableWindow(false);
}


void CQADialog::OnBnClickedBtnT2Incorrect()
{
	team_2_return_value = -1;
	GetDlgItem(IDC_BTN_T2_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_INCORRECT)->EnableWindow(false);
}


void CQADialog::OnBnClickedBtnT3Correct()
{
	team_3_return_value = 1;
	GetDlgItem(IDC_BTN_T1_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T1_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T2_INCORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_INCORRECT)->EnableWindow(false);
}


void CQADialog::OnBnClickedBtnT3Incorrect()
{
	team_3_return_value = -1;
	GetDlgItem(IDC_BTN_T3_CORRECT)->EnableWindow(false);
	GetDlgItem(IDC_BTN_T3_INCORRECT)->EnableWindow(false);
}
