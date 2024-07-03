// NetChessView.h : interface of the CNetChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
#define AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChessBoard.h"
#include "Options.h"
#include "History.h"
#include "DisksDlg.h"

class CNetChessView : public CView
{
	int i;
	CRect m_movedFromRect,m_movedToRect;
	COLORREF m_crefBlackColor,m_crefWhiteColor;
	long m_blackTime, m_whiteTime,m_startTime;
	int m_squarex,m_squarey;
	COLOR_TYPE  m_pieceSide;
	bool m_mouseMoveFlag;
	CRect m_moveRect;
	CPoint m_pointstart,m_pointend,m_point,m_randompoint;
	int m_SpecialAction;	
	bool m_LetterFlag;
	bool m_NumberFlag;		
	int m_topHistory;
	int m_squareWidth;	
	int m_firstTimeFlag;
	CList<CPoint,CPoint> m_list;
	CDisksDlg m_disksdlg;
	void SetLevelData();
	int m_game_level;
	int m_score;
	int m_trials;
	COLORREF m_snake_color;
	COLORREF m_food_color;
	COLORREF m_background_color;
	COLORREF m_bar_color;
protected: // create from serialization only
	CNetChessView();
	DECLARE_DYNCREATE(CNetChessView)
	 

// Attributes
public:
	bool m_timerFlag;	 
	
	void DrawBoard();
	CNetChessDoc* GetDocument();	
	void SetData(char* data, int length);	
	bool CheckValidMove(int,int);
	void KillTimerEvent();
	void OnEditRedoAction();
	void OnEditUndoAction();	
	void Initialize();
	int GetBitmapId(int piece_id);
	void SetPieceSide(COLOR_TYPE piecetype);
	COLOR_TYPE GetPlayerSide();
	CChessBoard cb[110][110];
	CChessBoard tower1[20],tower2[20],tower3[20];
	int m_towers,m_tower1,m_tower2,m_tower3;
	int m_maxtowers;
	int m_fromtower;
	CHistory  m_History;
	int m_steps;
	DIRECTION direction,m_backupdirection;
	
	int m_checkmove;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessView)
	afx_msg void OnEditOptions();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnUpdateViewLetter(CCmdUI* pCmdUI);
	afx_msg void OnViewNumber();
	afx_msg void OnUpdateViewNumber(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFileNew();
	afx_msg void OnViewHistory();
	afx_msg void OnEditMovefirst();
	afx_msg void OnEditMovelast();
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnEditProperties();
	afx_msg void OnEditSetboard();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnViewLetter();
	afx_msg void OnEditLevel();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnEditStart();
	afx_msg void OnEditStop();
	afx_msg void OnEditColorBackgroundcolor();
	afx_msg void OnEditColorFoodcolor();
	afx_msg void OnEditColorSnakecolor();
	afx_msg void OnEditColorBarcolor();
	afx_msg void OnViewScore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnMessageColorData(WPARAM wParam,LPARAM lParam);
	void OnLButtonDownAction(UINT nFlags, CPoint point);
	void OnLButtonUpAction(UINT nFlags, CPoint point);
	void OnMouseMoveAction(UINT nFlags, CPoint point);
	void OnFileNewAction();
	CString GetHistoryString();
	void SetShellIconData(char* data, int id);
	bool CheckCheckState(int piecetype, int piececolor,int x,int y);
	bool CheckKingMove(int fromx, int fromy, int tox, int toy);
	void SetMoveHistory();
	void GetMoveHistory();
	CPoint GetRandom(int x,int y);
	void SetPaneText(int paneno,CString str);
	void AddScore();
	void ReduceScore();

};

#ifndef _DEBUG  // debug version in NetChessView.cpp
inline CNetChessDoc* CNetChessView::GetDocument()
   { return (CNetChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
