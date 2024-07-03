// NetChessView.cpp : implementation of the CNetChessView class
//

#include "stdafx.h"
#include "NetChess.h"
#include "Options.h"
#include "ChessBoard.h"
#include "History.h"
#include "HistoryDlg.h"
#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
#include "DisksDlg.h"
#include "ScoreDlg.h"
#include "NewScore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int scorebase[7][10]={
	{60,70,80,90,100,110,120,130,140,150},
	{50,60,70,80,90,100,110,120,130,140},
	{40,50,60,70,80,90,100,110,120,130},
	{30,40,50,60,70,80,90,100,110,120},
	{20,30,40,50,60,70,80,90,100,110},
	{10,20,30,40,50,60,70,80,90,100},
	{5,10,20,30,40,50,60,70,80,90}
};

int checkExisting(int n, int *arr, int rand)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == rand)
			return 1;
	}
	return 0;
}

int getExisting(int n,int* arr, int* data)
{	 
	int foundFlag = 0; 	 	 
	for(int i=0;i<n;i++)
	{		 
		if(data[i] == 0) continue;
 		for(int j =0;j<n;j++)
		{
 			if(arr[j]==0)
			{
			 			 
				return data[i];
			}
				
			if(arr[j] == data[i])
			{				 
				foundFlag = 1;
				break;
			}
		}
		if(foundFlag == 0)
		{	 			 
			return data[i];
		}
	}
 	return -1;
}
int getRandom(int num)
{
	SYSTEMTIME st;
	::GetSystemTime(&st);
    int value = (st.wMilliseconds % num);
	return value;
}
/////////////////////////////////////////////////////////////////////////////
// CNetChessView
void writeMessage(char *str,...);
IMPLEMENT_DYNCREATE(CNetChessView, CView)

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	//{{AFX_MSG_MAP(CNetChessView)
	ON_COMMAND(ID_EDIT_OPTIONS, OnEditOptions)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LETTER, OnUpdateViewLetter)
	ON_COMMAND(ID_VIEW_NUMBER, OnViewNumber)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NUMBER, OnUpdateViewNumber)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_VIEW_HISTORY, OnViewHistory)
	ON_COMMAND(ID_EDIT_MOVEFIRST, OnEditMovefirst)
	ON_COMMAND(ID_EDIT_MOVELAST, OnEditMovelast)
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_COMMAND(D_EDIT_PROPERTIES, OnEditProperties)
	ON_COMMAND(ID_EDIT_SETBOARD, OnEditSetboard)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_VIEW_LETTER, OnViewLetter)
	ON_COMMAND(ID_EDIT_LEVEL, OnEditLevel)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_EDIT_START, OnEditStart)
	ON_COMMAND(ID_EDIT_STOP, OnEditStop)
	ON_COMMAND(ID_EDIT_COLOR_BACKGROUNDCOLOR, OnEditColorBackgroundcolor)
	ON_COMMAND(ID_EDIT_COLOR_FOODCOLOR, OnEditColorFoodcolor)
	ON_COMMAND(ID_EDIT_COLOR_SNAKECOLOR, OnEditColorSnakecolor)
	ON_COMMAND(ID_EDIT_COLOR_BARCOLOR, OnEditColorBarcolor)
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	ON_COMMAND(ID_VIEW_SCORE, OnViewScore)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(ID_MY_MESSAGE_COLORDATA,OnMessageColorData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetChessView construction/destruction

CNetChessView::CNetChessView()
{
	// TODO: add construction code here
	Initialize();
	m_towers = 16;	 
	m_maxtowers = 16;
	m_score = 0;
	m_game_level = 1;
	m_trials = 1;
	m_bar_color = m_snake_color = RGB(255,255,255);
	m_food_color = RGB(255,255,255);
	m_background_color = RGB(127,127,127);
}

CNetChessView::~CNetChessView()
{
}

BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView drawing

void CNetChessView::OnDraw(CDC* pDC)
{
	CNetChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawBoard(); 
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView printing

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView diagnostics

#ifdef _DEBUG
void CNetChessView::AssertValid() const
{
	CView::AssertValid();
}

void CNetChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNetChessDoc* CNetChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetChessDoc)));
	return (CNetChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessView message handlers

void CNetChessView::OnEditOptions() 
{
	DrawBoard();
}

void CNetChessView::DrawBoard()
{

	CClientDC dc(this);	 
	CBitmap localbmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	//BITMAP bp={0,1000,490,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);
	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	ldc.SelectObject(&localbmp); 	

	CBrush backgroundbrush;
	backgroundbrush.CreateSolidBrush(m_background_color);
	CRect crect;
	GetClientRect(&crect); 
	ldc.FillRect(&crect,&backgroundbrush);

	CBrush* pbrush =  ldc.SelectObject(&backgroundbrush);
	/*for(int i = 0; i < m_squarex; i++)
	{
		for( int j = 0; j < m_squarey; j++)
		{
			CRect rect = cb[i][j].GetRect();
			if(cb[i][j].GetColorType() == BLACK)
			{
				COLORREF cr(RGB(0,0,0));
				CBrush brush(cr);
				ldc.Rectangle(rect);						 
				ldc.FillRect(&rect,&brush);

			}
			else
			{
				COLORREF cr(RGB(255,255,255));
				CBrush brush(cr);
				ldc.Rectangle(rect);						 
				ldc.FillRect(&rect,&brush);
			}
		}
	}*/

	for(int i = 0; i < m_squarex; i++)
	{
		for( int j = 0; j < m_squarey; j++)
		{
			CRect rect = cb[i][j].GetRect();			
			if(cb[i][j].GetPieceType() != BLANK && cb[i][j].GetPieceState() != PIECE_MOVING)
			{
				int piece_id;
				COLOR_TYPE  piece_color;
				PIECE_TYPE  piece_type;
				STATE piece_state;
				cb[i][j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
				if(piece_id <= 0)
				{
					break;
				}											
				switch(piece_type)
				{
					case BAR:
						{							
							CBrush brush(m_bar_color);
							ldc.Rectangle(rect);						 
							ldc.FillRect(&rect,&brush);						
						}
						break;
					case SNAKE1:
						{
							CBrush brush(m_snake_color);
							ldc.Rectangle(rect);						 
							ldc.FillRect(&rect,&brush);
						}
						break;
					case FOOD:
						{
							CBrush brush(m_food_color);
							ldc.Rectangle(rect);						 
							ldc.FillRect(&rect,&brush);							
						}
					break; 
				}
			}			
		}			
	}

	dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);  
}
void CNetChessView::Initialize()
{	
	m_mouseMoveFlag = false;
	m_moveRect = 0;
	m_timerFlag = true;
	m_squareWidth = 10;
	m_squarex = 35;
	m_squarey = 56;
	m_blackTime = m_whiteTime = 0;
	m_startTime = time(0);

	COLORREF cr(RGB(127,127,127));
	m_crefBlackColor=cr;
	COLORREF cr1(RGB(127,127,127));
	m_crefWhiteColor = cr1;
	m_firstTimeFlag = 1;
	m_steps = 0;
	m_tower1=m_tower2=m_tower3 =-1;	

	/*//m_pointstart.x = m_pointend.x = m_point.x = 20;	
	//m_pointstart.y = m_pointend.y = m_point.y = 20;	
	m_list.RemoveAll();
	m_list.AddHead(m_pointstart);
	//m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
	m_randompoint.x = getRandom(m_squarex-1);
	m_randompoint.y = getRandom(m_squarey-1);	*/
	direction = LEFT;


	
}
int CNetChessView::GetBitmapId(int piece_id)
{
	return IDB_BITMAP_KING_WHITE;

}
void CNetChessView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();	 
//	writeMessage("OnINitialupate");
	int xstart = 5;
	int ystart = 5;
	int x,y=ystart;
	for ( int i = 0; i < m_squarex; i++)
	{
		x = xstart;
		for( int j = 0; j < m_squarey; j++)
		{
			CRect rect(x,y, x+ m_squareWidth, y+m_squareWidth);

			cb[i][j].SetRect(rect);
			cb[i][j].SetPieceType(BLANK);			 
			cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);			 
			x += m_squareWidth;
		}
		y += m_squareWidth;
	}

	COLOR_TYPE typex = BLACK;
	 
	for(i = 0; i< m_squarex; i++)
	{
		if(typex == WHITE)
			typex = BLACK;
		else
			typex = WHITE;
		COLOR_TYPE type = typex;
		for(int j=0; j < m_squarey; j++)
		{			
			cb[i][j].SetColorType(type);
			if(type == WHITE)
				type = BLACK;
			else
				type = WHITE;
		}
	}
//	m_game_level = 10;
	SetLevelData();	
	//m_pointstart.x = m_pointend.x = m_point.x = 20;	
	//m_pointstart.y = m_pointend.y = m_point.y = 20;	
	m_list.RemoveAll();	
	
	m_pointstart = GetRandom(m_squarex-1,m_squarey-1);
	m_list.AddHead(m_pointstart);
	Sleep(100);
	m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
	
	cb[m_pointstart.x][m_pointstart.y].SetPieceData(CHECKERS_WHITE,WHITE,SNAKE1,PIECE_NOT_MOVING);
	cb[m_randompoint.x][m_randompoint.y].SetPieceData(CHECKERS_WHITE,WHITE,FOOD,PIECE_NOT_MOVING);

	SetTimer(SHOW_TIMER_EVENT_ID,1000,NULL);	 
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	OnLButtonDownAction(nFlags,point);	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnLButtonUpAction(nFlags,point);	 
	CView::OnLButtonUp(nFlags, point);
}

void CNetChessView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	 
	OnMouseMoveAction(nFlags,point);
	CView::OnMouseMove(nFlags, point);
}

void CNetChessView::SetShellIconData(char* data, int id)
{
	NOTIFYICONDATA nicondata;					
	nicondata.hWnd = AfxGetApp()->m_pMainWnd->GetSafeHwnd();
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(id,&nicondata);
}

void CNetChessView::SetData(char* data,int length)
{
 
}


void CNetChessView::OnFileOpen() 
{

}

void CNetChessView::OnFileSave() 
{

}

void CNetChessView::OnViewLetter() 
{
	// TODO: Add your command handler code here

}
void CNetChessView::OnUpdateViewLetter(CCmdUI* pCmdUI) 
{

}

void CNetChessView::OnViewNumber() 
{

}

void CNetChessView::OnUpdateViewNumber(CCmdUI* pCmdUI) 
{

}

LRESULT CNetChessView::OnMessageColorData(WPARAM wParam,LPARAM lParam)
{	 
return 0;
}

CString CNetChessView::GetHistoryString()
{
	return "";

}

bool CNetChessView::CheckValidMove(int x,int y)
{
	return true;

}
 
void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point) 
{

	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point) 
{

}

void CNetChessView::OnMouseMoveAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	

}

void CNetChessView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	OnEditUndoAction();
 	unsigned char msg = UNDO;


}
void CNetChessView::OnEditUndoAction()
{

}

void CNetChessView::OnEditRedo() 
{
	// TODO: Add your command handler code here	 	 
	OnEditRedoAction();
}

void CNetChessView::OnEditRedoAction()
{

}

void CNetChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	
	CView::OnRButtonDown(nFlags, point);
}

void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	DrawBoard();
	CView::OnPrint(pDC, pInfo);
}

void CNetChessView::OnTimer(UINT nIDEvent)
{
	CString str;
	switch(nIDEvent)
	{
		case PIECE_SIDE_TIMER_EVENT_ID:
		{
			int piece_id;
			COLOR_TYPE  piece_color;
			PIECE_TYPE  piece_type;
			STATE piece_state;
			m_pointstart = m_list.GetHead();
			cb[m_pointstart.x][m_pointstart.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);
			if(piece_id <= 0)
			{
				return;
			}
			int foundflag1= 0;	
			switch(direction)
			{
				case LEFT:			
					if(m_pointstart.y-1 < 0)
					{
						ReduceScore();						
						DrawBoard();
						return;
					}
					if(m_pointstart.x == m_randompoint.x && m_pointstart.y-1 == m_randompoint.y)
					{	
						AddScore();
						m_list.AddHead(m_randompoint);				
						m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
						/*m_randompoint.x = getRandom(m_squarex-1);
						m_randompoint.y = getRandom(m_squarey-1) ;*/
						writeMessage("LEFT %d %d",m_randompoint.x,m_randompoint.y);
						cb[m_randompoint.x][m_randompoint.y].SetPieceData(piece_id,piece_color,FOOD,piece_state);
					}
					else
					{
						
						if(m_list.GetCount() == 1)
						{
							if(cb[m_pointstart.x][m_pointstart.y-1].GetPieceId()!= -1 )
							{
								ReduceScore();
								break;
								
							}
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							m_pointstart.y--;
							m_list.RemoveAll();
							m_list.AddHead(m_pointstart);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
						}
						else
						{
							if(cb[m_pointstart.x][m_pointstart.y-1].GetPieceId()!= -1 )
							{
								if(m_backupdirection == RIGHT)
								{
									direction = m_backupdirection;
									break;
								}
								ReduceScore();								
								break;
								
							}
							m_pointstart.y--;
							m_list.AddHead(m_pointstart);
							CPoint end = m_list.GetTail();
							cb[end.x][end.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
							m_list.RemoveTail();
						}
					}
					foundflag1 = 1;
					break;
				case UP:

					if(m_pointstart.x-1 < 0)
					{			
						ReduceScore();						
						DrawBoard();
						return;
					}
					if(m_pointstart.x-1 == m_randompoint.x && m_pointstart.y == m_randompoint.y)
					{				
						AddScore();						
						m_list.AddHead(m_randompoint);				
						m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
						/*m_randompoint.x = getRandom(m_squarex-1);
						m_randompoint.y = getRandom(m_squarey-1) ;*/
						writeMessage("UP %d %d",m_randompoint.x,m_randompoint.y);
						cb[m_randompoint.x][m_randompoint.y].SetPieceData(piece_id,piece_color,FOOD,piece_state);
					}
					else
					{
						if(m_list.GetCount() == 1)
						{
							if(cb[m_pointstart.x-1][m_pointstart.y].GetPieceId()!= -1)
							{
								ReduceScore();
								break;
							}
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							m_pointstart.x--;
							m_list.RemoveAll();
							m_list.AddHead(m_pointstart);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
						}
						else
						{
							if(cb[m_pointstart.x-1][m_pointstart.y].GetPieceId()!= -1)
							{
								if(m_backupdirection == DOWN)
								{
									direction = m_backupdirection;
									break;
								}
								ReduceScore();
								break;
							}
							m_pointstart.x--;
							m_list.AddHead(m_pointstart);
							CPoint end = m_list.GetTail();
							cb[end.x][end.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
							m_list.RemoveTail();
						}				
					}			
					foundflag1 = 1;
					break;
				case RIGHT:
					if(m_pointstart.y+1  >= m_squarey)
					{	
						ReduceScore();						
						DrawBoard();
						writeMessage("y++ %d",m_pointstart.y+1);
						return;
					}
					if(m_pointstart.x == m_randompoint.x && m_pointstart.y+1 == m_randompoint.y)
					{	
						AddScore();						
						m_list.AddHead(m_randompoint);				
						m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
						/*m_randompoint.x = getRandom(m_squarex-1);
						m_randompoint.y = getRandom(m_squarey-1) ;*/
						writeMessage("RIGHT %d %d",m_randompoint.x,m_randompoint.y);
						cb[m_randompoint.x][m_randompoint.y].SetPieceData(piece_id,piece_color,FOOD,piece_state);
					}
					else
					{
						if(m_list.GetCount() == 1)
						{
							if(cb[m_pointstart.x][m_pointstart.y+1].GetPieceId()!= -1)
							{				
								ReduceScore();								
								break;
							}
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							m_pointstart.y++;
							m_list.RemoveAll();
							m_list.AddHead(m_pointstart);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
						}
						else
						{
							if(cb[m_pointstart.x][m_pointstart.y+1].GetPieceId()!= -1)
							{
								if(m_backupdirection == LEFT)
								{
									direction = m_backupdirection;
									break;
								}
								ReduceScore();
								break;
							}
							m_pointstart.y++;
							m_list.AddHead(m_pointstart);
							CPoint end = m_list.GetTail();
							cb[end.x][end.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
							m_list.RemoveTail();
						}								
					}
					foundflag1 = 1;
					break;
				case DOWN:
					if(m_pointstart.x+1 >= m_squarex)
					{				
						ReduceScore();						
						DrawBoard();
						return;
					}
					if(m_pointstart.x+1 == m_randompoint.x && m_pointstart.y == m_randompoint.y)
					{	
						AddScore();						
						m_list.AddHead(m_randompoint);				
						m_randompoint = GetRandom(m_squarex-1,m_squarey-1);
						/*m_randompoint.x = getRandom(m_squarex-1);
						m_randompoint.y = getRandom(m_squarey-1) ;*/
						writeMessage("DOWN %d %d",m_randompoint.x,m_randompoint.y);
						cb[m_randompoint.x][m_randompoint.y].SetPieceData(piece_id,piece_color,FOOD,piece_state);
					}
					else
					{
						if(m_list.GetCount() == 1)
						{
							if(cb[m_pointstart.x+1][m_pointstart.y].GetPieceId()!= -1)
							{		
								ReduceScore();								
								break;
							}
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							m_pointstart.x++;
							m_list.RemoveAll();
							m_list.AddHead(m_pointstart);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
						}
						else
						{
							if(cb[m_pointstart.x+1][m_pointstart.y].GetPieceId()!= -1)
							{
								if(m_backupdirection == UP)
								{
									direction = m_backupdirection;
									break;
								}
								ReduceScore();								
								break;
							}
							m_pointstart.x++;
							m_list.AddHead(m_pointstart);
							CPoint end = m_list.GetTail();
							cb[end.x][end.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
							cb[m_pointstart.x][m_pointstart.y].SetPieceData(piece_id,piece_color,SNAKE1,piece_state);
							m_list.RemoveTail();
						}						
					}			
					foundflag1 = 1;
					break;
				default:
					CView::OnTimer(nIDEvent);
					return;
			}
			DrawBoard();
		}
		break;
		case SHOW_TIMER_EVENT_ID:
			{
				if(m_timerFlag == true)
				{
					CTime tb(time(0));
					CTime st(m_startTime);
					CTimeSpan ts = tb - st; 				
					CString str;
					str.Format("%d:%d:%d",ts.GetHours(),ts.GetMinutes(),ts.GetSeconds());
					SetPaneText(10,str);
					//((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(8,str);
				}
				else
				{
					m_startTime++;
				}
			}
			break;
	}					
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{
	 
	//KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
}

void CNetChessView::OnFileNew() 
{
	m_startTime = time(0);
	OnFileNewAction();  

}
void CNetChessView::OnFileNewAction()
{	
	m_score = 0;
	m_score = 0;	
	m_trials = 1;
//	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(6,str);
	CString str;
	str.Format("%d",m_score);
	SetPaneText(8,str);	
	Initialize();
	OnInitialUpdate();
	str.Format("%d",m_trials);
	SetPaneText(6,str);

	DrawBoard();
}

void CNetChessView::OnViewHistory() 
{

}
 

void CNetChessView::OnEditMovefirst() 
{
	// TODO: Add your command handler code here

}

void CNetChessView::OnEditMovelast() 
{
	// TODO: Add your command handler code here

		 	
}

void CNetChessView::OnHelpHowtoplay() 
{
	CString helpMsg;
	helpMsg = "Snakes game is provided with 10 levels. To win the game, "
	" complete all 10 levels. Eat as much food as possible to move to the next level. Use keyboard "
	"arrow keys to move the snake";	
	AfxMessageBox(helpMsg);
	// TODO: Add your command handler code here*/ 
	//::WinHelp(this->GetSafeHwnd(),"NetChess.hlp",HELP_CONTENTS,0);	 
	
}

void CNetChessView::OnEditProperties() 
{
	// TODO: Add your command handler code here

}



void CNetChessView::SetPieceSide(COLOR_TYPE pieceside)
{

}

COLOR_TYPE CNetChessView::GetPlayerSide()
{
	return m_pieceSide;
}


void CNetChessView::OnEditSetboard() 
{
	// TODO: Add your command handler code here
}

void CNetChessView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 
	CView::OnRButtonUp(nFlags, point);
}
bool CNetChessView::CheckCheckState(int piecetype, int piececolor,int x,int y)
{

	return false;
}
bool CNetChessView::CheckKingMove(int fromx, int fromy, int tox, int toy)
{
	return true;
}
void CNetChessView::SetMoveHistory()
{

}
void CNetChessView::GetMoveHistory()
{

}

void writeMessage(char *str,...)
{
#ifdef _DEBUG
	char arr[9999];
	va_list va;     
    va_start(va,str);
    vsprintf(arr,str,va);       
	FILE* fp=fopen(".\\data.dat","a+");
	fprintf(fp,"%s\n",arr);
	fclose(fp);
#endif
}

void CNetChessView::OnEditLevel() 
{
	// TODO: Add your command handler code here
	m_disksdlg.m_game_level = m_game_level;
	//m_disksdlg.UpdateData(FALSE);
	if(m_disksdlg.DoModal() == IDOK)
	{	
//		KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
//		SetTimer(PIECE_SIDE_TIMER_EVENT_ID,m_disksdlg.m_level,NULL);	 
		
		CString str;
	    str.Format("%d",m_disksdlg.m_level);
		//((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(2,str);
		SetPaneText(4,str);
		m_game_level = m_disksdlg.m_game_level;
		Initialize();
		OnInitialUpdate();
	}
}

void CNetChessView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	/*CString str;
	str.Format("%d",nChar);
	AfxMessageBox(str);*/
	if(nChar >=37 && nChar <=40)
	{
		m_backupdirection = direction;
		direction = (DIRECTION)nChar;	

	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
CPoint CNetChessView::GetRandom(int x,int y)
{
	CPoint pt;
	do
	{
		SYSTEMTIME st;
		::GetSystemTime(&st);
		pt.x= (st.wMilliseconds % x);
		memset(&st,0,sizeof(st));
		::GetSystemTime(&st);
		pt.y= ((st.wMilliseconds/10) % y);
		if(cb[pt.x][pt.y].GetPieceId() < 0)
		{
			if(pt.x-1 >= 0)
			{
				if(cb[pt.x-1][pt.y].GetPieceId() < 0)
				{
					pt.x--;
				}
			}
			else if(pt.x+1 < m_squarex)
			{
				if(cb[pt.x+1][pt.y].GetPieceId() < 0)
				{
					pt.x++;
				}
			}
			else if(pt.y-1 >=0)
			{
				if(cb[pt.x][pt.y-1].GetPieceId() < 0)
				{
					pt.y--;
				}
			}
			else if(pt.y+1 < m_squarey)
			{
				if(cb[pt.x][pt.y+1].GetPieceId() < 0)
				{
					pt.y++;
				}
			}
		}
		writeMessage("piece id in getrandom %d %d %d",cb[pt.x][pt.y].GetPieceId(),pt.x,pt.y);
	}while(cb[pt.x][pt.y].GetPieceId() > 0);
	return pt;
}

void CNetChessView::OnEditStart() 
{
	// TODO: Add your command handler code here
	KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
	Sleep(500);
	SetTimer(PIECE_SIDE_TIMER_EVENT_ID,m_disksdlg.m_leveltime,NULL);	 	
	m_timerFlag = true;
}

void CNetChessView::OnEditStop() 
{
	// TODO: Add your command handler code here
	KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
	m_timerFlag = false;
}
void CNetChessView::SetLevelData()
{
	int i=0;
	switch(m_game_level)
	{
		case 1:	
			for(i=0;i<m_squarex;i++)
			{
				for(int j=0;j<m_squarey;j++)
				{
					cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);			 
					//cb[i][j].SetPieceData(CHECKERS_WHITE,WHITE,NORMAL,PIECE_NOT_MOVING);
				}
			}
			break;
		case 2:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][28].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;
		case 3:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][15].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][40].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;
		case 4:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][10].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][46].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][28].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;
		case 5:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][45].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
				cb[m_squarex-i-1][30].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			for(i=0;i<m_squarey-35;i++)
			{
				cb[10][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
				cb[25][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;
		case 6:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][10].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][30].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][20].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][45].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}			
			break;
		case 7:
			for(i=0;i< m_squarey - 20;i++)
			{
				cb[5][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[20][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[13][m_squarey-i-1].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[27][m_squarey-i-1].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;
		case 8:
			for(i=0;i< m_squarex - 5;i++)
			{
				cb[i][6].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][27].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][15].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][40].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][50].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			break;

		case 9:
			for(i=0;i< 10;i++)
			{
				cb[i][20].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][35].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][28].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][20].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][28].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][35].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=0;i<=40;i++)
			{
				cb[20][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
				cb[15][m_squarey-i-1].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=10;i<=20;i++)
			{
				cb[10][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[10][m_squarey-i-1].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[25][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[25][m_squarey-i-1].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			break;
		case 10:
			for(i=0;i< 10;i++)
			{
				cb[i][20].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][40].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i+10][15].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][8].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][15].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][22].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][29].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][36].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[m_squarex-i-1][42].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[i][8].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			for(i=0;i<10;i++)
			{
				cb[15][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
				cb[20][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);
			}
			for(i=10;i< 30;i++)
			{
				cb[i][50].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=15;i<= 20;i++)
			{
				cb[10][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=15;i<= 46;i++)
			{
				cb[20][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=40;i<= 50;i++)
			{
				cb[10][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			for(i=30;i<= 50;i++)
			{
				cb[10][i].SetPieceData(CHECKERS_WHITE,WHITE,BAR,PIECE_NOT_MOVING);				
			}
			break;
	}
}
void CNetChessView::SetPaneText(int paneno,CString str)
{
		((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(paneno,str);
}
void CNetChessView::AddScore()
{
	
	CString str;
	m_score = m_score +  scorebase[(m_disksdlg.m_level-1)][m_game_level-1];
	str.Format("%d",m_score);
	SetPaneText(8,str);
	int targetcount = 50;
	switch(m_game_level)
	{
		case 1:
			targetcount = 50;
			break;
		case 2:
			targetcount = 50;
			break;
		case 3:
			targetcount = 50;
			break;
		case 4:
			targetcount = 50;
			break;
		case 5:
			targetcount = 50;
			break;
		case 6:
			targetcount = 50;
			break;
		case 7:
		case 8:
		case 9:
		case 10:
		default:
			targetcount = 50;
			break;
	}
	if(m_list.GetCount() > targetcount-1)
	{
		m_game_level+=1;
		if(m_game_level == 11)
		{
			CString str;
			str.Format("Congratulations!!! you won the game. Your score is %d",m_score);
			m_score = 0;
			AfxMessageBox(str);
			m_game_level = 1;
			OnEditStop();
		}
		m_trials = 1;
		str.Format("%d",m_trials);
		SetPaneText(6,str);
		str.Format("%d",m_game_level);
		SetPaneText(4,str);
		Initialize();
		OnInitialUpdate();
	}
}
void CNetChessView::ReduceScore()
{
	CString str;
	m_score = m_score - scorebase[(m_disksdlg.m_level-1)][m_game_level-1] * 2;
	str.Format("%d",m_score);
	SetPaneText(8,str);	
	m_trials++;
	if(m_trials > 10)
	{
		CNewScore dlg;
		CScoreDlg scoredlg;
		CString str;
		str.Format("%d",m_score);
		scoredlg.m_score = str;
		KillTimer(PIECE_SIDE_TIMER_EVENT_ID);
		m_timerFlag = false;
		if(scoredlg.CheckScore(m_score) == true)
		{			
			dlg.m_edig_score = m_score;
			if( dlg.DoModal() == IDOK)
			{
				scoredlg.m_score.Format("%d",m_score);				
				scoredlg.m_name = dlg.m_edit_name;
				scoredlg.ReInitialize();
				scoredlg.DoModal();
				m_trials = 1;		
				m_score = 0;				
				Initialize();
				OnInitialUpdate();
			}
		}
		else
		{
			scoredlg.DoModal();
			m_trials = 1;		
			m_score = 0;
			Initialize();
			OnInitialUpdate();
		}
	}
	/*if(direction == LEFT)
		direction = RIGHT;
	else if(direction == RIGHT)
		direction = LEFT;
	else if(direction == UP)
		direction = DOWN;
	else if(direction = DOWN)
		direction = UP;*/
	str.Format("%d",m_trials);
	SetPaneText(6,str);
	Initialize();
	OnInitialUpdate();
}

void CNetChessView::OnEditColorBackgroundcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.GetColor() != m_snake_color && dlg.GetColor() != m_food_color && dlg.GetColor() != m_bar_color)
		{
			m_background_color = dlg.GetColor();
		}
		else
		{
			AfxMessageBox("Selected color matched to Snakes/food/bar color, please select different color!");
		}
	}
	DrawBoard();
}

void CNetChessView::OnEditColorFoodcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.GetColor() != m_snake_color && dlg.GetColor() != m_background_color && dlg.GetColor() != m_bar_color)
		{
			m_food_color = dlg.GetColor();
		}
		else
		{
			AfxMessageBox("Selected color matched to Snakes/background/bar color, please select different color!");
		}
	}
	DrawBoard();
}

void CNetChessView::OnEditColorSnakecolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.GetColor() != m_food_color && dlg.GetColor() != m_background_color && dlg.GetColor() != m_bar_color)
		{
			m_snake_color = dlg.GetColor();
		}
		else
		{
			AfxMessageBox("Selected color matches to Background/food/bar color, please select different color!");
		}
	}	
	DrawBoard();
}

void CNetChessView::OnEditColorBarcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		if(dlg.GetColor() != m_food_color && dlg.GetColor() != m_background_color && dlg.GetColor() != m_snake_color)
		{
			m_bar_color = dlg.GetColor();
		}
		else
		{
			AfxMessageBox("Selected color matches to Snake/Background/food/Bar color, please select different color!");
		}
	}	
	DrawBoard();	
}

void CNetChessView::OnViewScore() 
{
	CScoreDlg dlg;
	dlg.DoModal();
}
