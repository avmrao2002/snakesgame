#if !defined(AFX_NEWSCORE_H__06B7C134_B6A3_4B28_A6AF_07E334F9C8F2__INCLUDED_)
#define AFX_NEWSCORE_H__06B7C134_B6A3_4B28_A6AF_07E334F9C8F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewScore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewScore dialog

class CNewScore : public CDialog
{
// Construction
public:
	CNewScore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewScore)
	enum { IDD = IDD_DIALOG_NEW_SCORE };
	CString	m_edit_name;
	int		m_edig_score;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewScore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewScore)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSCORE_H__06B7C134_B6A3_4B28_A6AF_07E334F9C8F2__INCLUDED_)
