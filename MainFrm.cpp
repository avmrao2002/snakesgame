// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "NetChess.h"

#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_HIDE, OnViewHide)
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_QUERYENDSESSION()
	ON_WM_ENDSESSION()
	ON_COMMAND(ID_SHELL_CLOSE, OnShellClose)
	ON_COMMAND(ID_SHELL_VIEW, OnShellView)
	//}}AFX_MSG_MAP
	ON_MESSAGE(MY_MESSAGE_SHELLNOTIFY, OnShellNotify)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR

};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,0,240);
	m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(1,"SKILL");
	m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,10);
	m_wndStatusBar.SetPaneText(2,"7");
	m_wndStatusBar.SetPaneInfo(3,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(3,"LEVEL");
	m_wndStatusBar.SetPaneInfo(4,ID_SEPARATOR,0,10);
	m_wndStatusBar.SetPaneText(4,"1");
	m_wndStatusBar.SetPaneInfo(5,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(5,"TRIAL");
	m_wndStatusBar.SetPaneInfo(6,ID_SEPARATOR,0,15);
	m_wndStatusBar.SetPaneText(6,"1");
	m_wndStatusBar.SetPaneInfo(7,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(7,"SCORE");
	m_wndStatusBar.SetPaneInfo(8,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(8,"0");
	m_wndStatusBar.SetPaneInfo(9,ID_SEPARATOR,0,30);
	m_wndStatusBar.SetPaneText(9,"TIME");
	m_wndStatusBar.SetPaneInfo(10,ID_SEPARATOR,0,40);
	m_wndStatusBar.SetPaneText(10,"0:0:0");

	
	
//	m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,30);
//	m_wndStatusBar.SetPaneText(1,"TIME");
//	m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,40);
//	m_wndStatusBar.SetPaneText(2,"0:0:0");
	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER|WS_MINIMIZE;
	cs.cx =580;
	cs.cy = 450;
	cs.x = 40;
	cs.y = 10;
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewHide() 
{
	CNetChessView* pView = (CNetChessView*)GetActiveView();
	//if(pView->m_timerFlag == false)
	{
		NOTIFYICONDATA nicondata;
		char data[64] = "Snakes by A.V.M.Rao";
		 
		nicondata.hWnd = this->GetSafeHwnd();;
		nicondata.uID = 10;
		nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
		nicondata.cbSize = sizeof(nicondata);
		nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
		nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		strcpy(nicondata.szTip,data);
		Shell_NotifyIcon(NIM_ADD,&nicondata);
	}
	this->ShowWindow(SW_HIDE);
	 
}
LRESULT CMainFrame::OnShellNotify(WPARAM wParam,LPARAM lParam)
{
 
	switch(lParam)
	{
		case WM_LBUTTONDOWN:			 
			{
				this->ShowWindow(SW_SHOW);			
			}
			break;
		case WM_LBUTTONUP:
			{	
				CNetChessView* pView = (CNetChessView*)GetActiveView();
		 
				if(pView->m_timerFlag == true)
				{
					pView->KillTimerEvent();					 
				}
				NOTIFYICONDATA nicondata;
				char data[64] = "Snakes  by A.V.M.Rao";
				nicondata.hWnd = this->GetSafeHwnd();;
				nicondata.uID = 10;
				nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
				nicondata.cbSize = sizeof(nicondata);
				nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
				nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
				strcpy(nicondata.szTip,data);
				Shell_NotifyIcon(NIM_DELETE,&nicondata);
				 
			}
			break;
		case WM_RBUTTONDOWN:
			{
				CRect rect;
				GetWindowRect(rect);
				CMenu menu;
				menu.LoadMenu(IDR_SHELL_MENU);
				CMenu *pMenu = menu.GetSubMenu(0);
				pMenu->TrackPopupMenu(TPM_LEFTALIGN |
				TPM_LEFTBUTTON | TPM_RIGHTBUTTON,rect.bottom,rect.right ,this);
				//this->ShowWindow(SW_HIDE);
			}
			break;
	}
	return 0;
} 

void CMainFrame::OnViewStatusBar() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnViewToolbar() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	NOTIFYICONDATA nicondata;
 	char data[64] = "Snakes by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	CFrameWnd::OnClose();
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	NOTIFYICONDATA nicondata;
	char data[64] = "Snakes by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	// TODO: Add your message handler code here
	
}

BOOL CMainFrame::OnQueryEndSession() 
{
	if (!CFrameWnd::OnQueryEndSession())
		return FALSE;
	NOTIFYICONDATA nicondata;
	char data[64] = "Snakes by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	// TODO: Add your specialized query end session code here
	
	return TRUE;
}

void CMainFrame::OnEndSession(BOOL bEnding) 
{
	CFrameWnd::OnEndSession(bEnding);
	NOTIFYICONDATA nicondata;
	char data[64] = "Snakes  by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnShellClose() 
{
	// TODO: Add your command handler code here
	NOTIFYICONDATA nicondata;
	char data[64] = "Snakes by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	SendMessage(WM_CLOSE);
}

void CMainFrame::OnShellView() 
{
	// TODO: Add your command handler code here
	NOTIFYICONDATA nicondata;
	char data[64] = "Snakes by A.V.M.Rao";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(NIM_DELETE,&nicondata);
	
	this->ShowWindow(SW_SHOW);	
}

 
 
