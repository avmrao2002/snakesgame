#if !defined(AFX_DISKSDLG_H__50A55C7D_EF56_4632_91DC_6412B6222923__INCLUDED_)
#define AFX_DISKSDLG_H__50A55C7D_EF56_4632_91DC_6412B6222923__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisksDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisksDlg dialog

class CDisksDlg : public CDialog
{
// Construction
public:
	CDisksDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDisksDlg)
	enum { IDD = IDD_DISKS };
	int		m_game_level;
	//}}AFX_DATA

	int m_level;
	int m_levelbutton;
	int m_leveltime;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisksDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisksDlg)
	virtual void OnOK();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKSDLG_H__50A55C7D_EF56_4632_91DC_6412B6222923__INCLUDED_)
