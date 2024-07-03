// NewScore.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "NewScore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewScore dialog


CNewScore::CNewScore(CWnd* pParent /*=NULL*/)
	: CDialog(CNewScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewScore)
	m_edit_name = _T("");
	m_edig_score = 0;
	//}}AFX_DATA_INIT
}


void CNewScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewScore)
	DDX_Text(pDX, IDC_EDIT_NAME, m_edit_name);
	DDV_MaxChars(pDX, m_edit_name, 10);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_edig_score);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewScore, CDialog)
	//{{AFX_MSG_MAP(CNewScore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewScore message handlers

void CNewScore::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_edit_name.IsEmpty())
	{
		AfxMessageBox("Enter name");
		return;
	}
	CDialog::OnOK();
}
