// HistoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HistoryDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg dialog


CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryDlg)
	m_edit_history = _T("");
	//}}AFX_DATA_INIT
}

CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/,CHistory history)
	: CDialog(CHistoryDlg::IDD, pParent)
{ 
	m_edit_history = _T(""); 
	m_History = history;

}

void CHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryDlg)
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_edit_history);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg message handlers

BOOL CHistoryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_edit_history = ((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->GetHistoryString();
	
	/*PIECE_SIDE piece_side;
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_color_type;
	int from_pieceid;
	int from_row_id;
	int from_col_id;
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_color_type;
	int to_pieceid;
	int to_row_id;
	int to_col_id;
	int flag = 0;
	for(int i=0;i<=m_iHistory;i++)
	{	
		 
		m_History[i].GetHistory(piece_side,
			from_piece_type,
			from_color_type,from_pieceid,
			from_row_id,from_col_id, to_piece_type,
			to_color_type,to_pieceid,to_row_id,
			to_col_id);
		 
		CString str;		 
		char from_type=' ';
		switch(from_piece_type)
		{
			case ROOK:
				from_type = 'R';
				break;
			case KNIGHT:
				from_type = 'N';
				break;
			case BISHOP:
				from_type = 'B';
				break;
			case QUEEN:
				from_type = 'Q';
				break;
			case KING:
				from_type = 'K';
				break;
			case PAWN:
				from_type = ' ';
				break;
			default:
				from_type = ' ';
				break;
		}
		char to_type=' ';
		switch(to_piece_type)
		{
			case ROOK:
				to_type = 'R';				break;
			case KNIGHT:
				to_type = 'N';
				break;
			case BISHOP:
				to_type = 'B';
				break;
			case QUEEN:
				to_type = 'Q';
				break;
			case KING:
				to_type = 'K';
				break;
			case PAWN:
				to_type = ' ';
				break;
			default:
				to_type = ' ';
				break;
		}
		if( m_History[i].GetSpecialAction() == CASTLING)
		{
			str.Format("0-0");
		}
		else
		{
			if(piece_side == TOP)
			{
				str.Format("%c%c%d -> %c%c%d",
					from_type,
					7-from_col_id+'a', (from_row_id+1),			 
					to_type,7-to_col_id+'a',
					(to_row_id+1));
			}
			
			else
			{
				str.Format("%c%c%d -> %c%c%d",
					from_type,
					from_col_id+'a', 9- (from_row_id+1),			 
					to_type,to_col_id+'a',
					9-(to_row_id+1));

			}
		}
		if( flag == 0)
		{
			CString str1;
			str1.Format("%d) ",i+1);
			m_edit_history += str1 + str;
			flag = 1;
		}
		else
		{
			m_edit_history += (CString)", " + str + (CString)"\r\n";
			flag = 0;
		}
		UpdateData(FALSE);
	} */
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
