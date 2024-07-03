// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
#define AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#define MY_MESSAGE_SHELLNOTIFY WM_USER + 1
#include <afxsock.h>		// MFC socket extensions
#include <afxtempl.h>

	/*#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CNetChessModule : public CComModule
{
public:
	LONG Unlock();
	LONG Lock();
	LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2);
	DWORD dwThreadID;
};
extern CNetChessModule _Module;
#include <atlcom.h>*/

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
enum COLOR_TYPE {NONE,BLACK,WHITE};
enum PIECE_SIDE {TOP,BOTTOM};
enum PIECE_TYPE {BLANK,FOOD,SNAKE1,SNAKE2,SNAKE3,SNAKE4,WALL,BAR,NORMAL}; 
enum ACTION {MOVE,TEXT,FILEDATA,MOVING,UNDO,REDO,NEWGAME,SYNC,NOTACCEPTED,ACCEPTED,RESIGN_REQUEST, RESIGN_ACCEPT, RESIGN_REJECT, DRAW_REQUEST,DRAW_REJECT,DRAW_ACCEPT,CLEAR_REQUEST,CLEAR_ACCEPT,CLEAR_REJECT,CHECKMOVE};
enum STATE {PIECE_MOVING,PIECE_NOT_MOVING};
enum DIRECTION {LEFT=37,UP,RIGHT,DOWN,NILL};
#define TOWER1 1
#define TOWER2 2
#define TOWER3 3
#define CLIENT 1
#define SERVER 2
#define OTHER	3
#define MAXHISTORY 400
#define ID_MY_MESSAGE_COLORDATA WM_USER + 1
#define SHELL_ICON_TIMER_EVENT_ID	1000
#define PIECE_SIDE_TIMER_EVENT_ID	1001
#define SHOW_TIMER_EVENT_ID	1002

#define ROOK_WHITE           1
#define BISHOP_WHITE         2
#define KING_BLACK           3
#define KING_WHITE           4
#define KNIGHT_BLACK         5
#define KNIGHT_WHITE         6
#define PAWN_BLACK           7
#define PAWN_WHITE           8
#define QUEEN_BLACK          9
#define QUEEN_WHITE          10
#define ROOK_BLACK           11
#define BISHOP_BLACK         12

#define CASTLING			1
#define ENPASSENT			2
#define CHECK				3
#define ENPASSENT_CHECK		4
#define CASTLING_CHECK		5
#define BLACK_KING_MOVED	6
#define WHITE_KING_MOVED	7
#define NOTHING				8
#define CHECKERS_WHITE			1


#endif // !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
