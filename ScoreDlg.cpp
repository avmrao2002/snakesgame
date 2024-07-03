// ScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "ScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog


CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoreDlg)
	//}}AFX_DATA_INIT
	for(int i=0;i<10;i++)
	{
		m_static_name[i] = m_static_score[i] = _T("");
		CString str;
		str.Format("%d",i+1);
		m_static_rank[i] = str;
	}
	m_score = "";
	m_name = "";
}


void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoreDlg)
	
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_STATIC__NAME10, m_static_name[9]);
	DDX_Text(pDX, IDC_STATIC__NAME6, m_static_name[5]);
	DDX_Text(pDX, IDC_STATIC__NAME7, m_static_name[6]);
	DDX_Text(pDX, IDC_STATIC__NAME8, m_static_name[7]);
	DDX_Text(pDX, IDC_STATIC__NAME9, m_static_name[8]);
	DDX_Text(pDX, IDC_STATIC__RANK10, m_static_rank[9]);
	DDX_Text(pDX, IDC_STATIC__RANK4, m_static_rank[3]);
	DDX_Text(pDX, IDC_STATIC__RANK5, m_static_rank[4]);
	DDX_Text(pDX, IDC_STATIC__RANK6, m_static_rank[5]);
	DDX_Text(pDX, IDC_STATIC__RANK7, m_static_rank[6]);
	DDX_Text(pDX, IDC_STATIC__RANK8, m_static_rank[7]);
	DDX_Text(pDX, IDC_STATIC__RANK9, m_static_rank[8]);
	DDX_Text(pDX, IDC_STATIC_NAME1, m_static_name[0]);
	DDX_Text(pDX, IDC_STATIC_NAME2, m_static_name[1]);
	DDX_Text(pDX, IDC_STATIC_NAME3, m_static_name[2]);
	DDX_Text(pDX, IDC_STATIC_NAME4, m_static_name[3]);
	DDX_Text(pDX, IDC_STATIC_NAME5, m_static_name[4]);
	DDX_Text(pDX, IDC_STATIC_RANK1, m_static_rank[0]);
	DDX_Text(pDX, IDC_STATIC_RANK2, m_static_rank[1]);
	DDX_Text(pDX, IDC_STATIC_RANK3, m_static_rank[2]);
	DDX_Text(pDX, IDC_STATIC_SCORE1, m_static_score[0]);
	DDX_Text(pDX, IDC_STATIC_SCORE10, m_static_score[9]);
	DDX_Text(pDX, IDC_STATIC_SCORE2, m_static_score[1]);
	DDX_Text(pDX, IDC_STATIC_SCORE3, m_static_score[2]);
	DDX_Text(pDX, IDC_STATIC_SCORE4, m_static_score[3]);
	DDX_Text(pDX, IDC_STATIC_SCORE5, m_static_score[4]);
	DDX_Text(pDX, IDC_STATIC_SCORE6, m_static_score[5]);
	DDX_Text(pDX, IDC_STATIC_SCORE7, m_static_score[6]);
	DDX_Text(pDX, IDC_STATIC_SCORE8, m_static_score[7]);
	DDX_Text(pDX, IDC_STATIC_SCORE9, m_static_score[8]);
}


BEGIN_MESSAGE_MAP(CScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CScoreDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg message handlers

BOOL CScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	Initialize();
	// TODO: Add extra initialization here
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CScoreDlg::Initialize()
{
	int i=0;
	char defaultBuf[40]="default";
	char CurrentDir[255];
	GetCurrentDirectory(255,CurrentDir);
	strcat(CurrentDir,"\\SnakesScore.ini");
	//FILE *fp = fopen(CurrentDir,"a+");
	//fclose(fp);
	for(i=0;i<10;i++)
	{
		m_static_name[i] = m_static_score[i] = _T("");
		CString str;
		str.Format("%d",i+1);
		m_static_rank[i] = str;
	}
	for(i=0;i<10;i++)
	{
		CString str;
		char data1[100],data2[100];
		str.Format("Player%dName",i+1);
 		if(GetPrivateProfileString("Score",str,defaultBuf,data1,100,CurrentDir)>0)
		{
			//if(strcmp(data,"default")!=0)
			//	m_static_name[i] = data;
			str.Format("Player%dScore",i+1);
			memset(data2,'\0',100);
			if(GetPrivateProfileString("Score",str,defaultBuf,data2,100,CurrentDir)>0)
			{
				if(strcmp(data1,"default")!= 0 && strcmp(data2,"default")!=0)
					InsertInAscendingOrder(data1,data2);
				//else
				//	m_static_score[i] = "-9999999";
			}
		}
		
	}
}
bool CScoreDlg::CheckScore(int scr)
{
	Initialize();
	int score[10];
	int localscore = atoi(m_score);
	bool flag = false;
	for(int i=0;i<10;i++)
	{
		if(!m_static_score[i].IsEmpty())
			score[i] = atoi(m_static_score[i]);
		else
			score[i]=-999999;
		if(score[i] <= scr)
			flag = true;
	}
	return flag;

}
void CScoreDlg::InsertInAscendingOrder(CString name,char stringscore[100])
{
	int score[10];
	int i;
	for(i=0;i<10;i++)
	{
		if(!m_static_score[i].IsEmpty())
			score[i] = atoi(m_static_score[i]);
		else
			score[i] = -999999;
	}
	//AfxMessageBox(stringscore);
	int localscore = atoi(stringscore);
	for(i=0;i<10;i++)
	{
		if(score[i] < localscore)
		{
			for(int j=8;j>=i;j--)
			{
				
				m_static_score[j+1] = m_static_score[j];
				m_static_name[j+1] = m_static_name[j];
			}
			m_static_name[i] = name;
			m_static_score[i] = stringscore;
			break;
		}
	}

	/*for(i=9;i>=0;i--)
	{
		 if(score[i] <= localscore)
		{
			if(i+1<10)
			{
				m_static_score[i+1] = m_static_score[i];
				m_static_name[i+1] = m_static_name[i];
			}			
		}
		else
		{
			m_static_name[i] = name;
			m_static_score[i] = stringscore;		
			break;
		}
	}*/
}

void CScoreDlg::ReInitialize()
{	
	Initialize();
	char CurrentDir[255];
	GetCurrentDirectory(255,CurrentDir);
	strcat(CurrentDir,"\\SnakesScore.ini");
	InsertInAscendingOrder(m_name,m_score.GetBuffer(0));	
	for(int i=0;i<10;i++)
	{		
		CString str;
		str.Format("Player%dName",i+1);
		if(!m_static_name[i].IsEmpty())
		{
			WritePrivateProfileString("Score",str,m_static_name[i].GetBuffer(0),CurrentDir);
			str.Format("Player%dScore",i+1);
			WritePrivateProfileString("Score",str,m_static_score[i].GetBuffer(0),CurrentDir);
		}
	}	
}
