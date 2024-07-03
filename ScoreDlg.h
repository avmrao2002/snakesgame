#if !defined(AFX_SCOREDLG_H__C99773B4_3264_4615_B9FB_2E78C597E78D__INCLUDED_)
#define AFX_SCOREDLG_H__C99773B4_3264_4615_B9FB_2E78C597E78D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreDlg dialog

class CScoreDlg : public CDialog
{
// Construction
public:
	int m_add_score_flag;
	CString m_name;
	CString m_score;
	CScoreDlg(CWnd* pParent = NULL);   // standard constructor
	CString m_static_name[10];
	CString m_static_rank[10];
	CString m_static_score[10];
	void Initialize();
	void ReInitialize();
	bool CheckScore(int);
	void InsertInAscendingOrder(CString name,char localscore[100]);
// Dialog Data
	//{{AFX_DATA(CScoreDlg)
	enum { IDD = IDD_DIALOG_SCORE };	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoreDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOREDLG_H__C99773B4_3264_4615_B9FB_2E78C597E78D__INCLUDED_)
