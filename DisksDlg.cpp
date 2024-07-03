// DisksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "DisksDlg.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisksDlg dialog


CDisksDlg::CDisksDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDisksDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDisksDlg)
	m_game_level = 0;
	//}}AFX_DATA_INIT
	m_leveltime = 400;
	m_level = 7;
	m_levelbutton = IDC_RADIO_7;
}


void CDisksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisksDlg)
	DDX_Text(pDX, IDC_EDIT_GAME_LEVEL, m_game_level);
	DDV_MinMaxInt(pDX, m_game_level, 1, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisksDlg, CDialog)
	//{{AFX_MSG_MAP(CDisksDlg)
	ON_BN_CLICKED(IDC_RADIO_1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO_2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO_3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO_4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO_5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO_6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO_7, OnRadio7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisksDlg message handlers

void CDisksDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	
	CDialog::OnOK();
}

void CDisksDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_level = 1;
	m_leveltime = 50;
	m_levelbutton = IDC_RADIO_1;
}

void CDisksDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_level = 2;
	m_leveltime = 75;
	m_levelbutton = IDC_RADIO_2;
}

void CDisksDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_leveltime = 100;
	m_level = 3;
	m_levelbutton = IDC_RADIO_3;
}

void CDisksDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_leveltime = 150;
	m_level = 4;
	m_levelbutton = IDC_RADIO_4;
}

void CDisksDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	m_leveltime = 200;
	m_level = 5;
	m_levelbutton = IDC_RADIO_5;
}

void CDisksDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_leveltime = 300;
	m_level = 6;
	m_levelbutton = IDC_RADIO_6;
}

void CDisksDlg::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	m_leveltime = 400;
	m_level = 7;	
	m_levelbutton = IDC_RADIO_7;
}

BOOL CDisksDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CButton *wnd = (CButton*)GetDlgItem(m_levelbutton);
	wnd->SetCheck(1);
	// TODO: Add extra initialization here	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
