; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewScore
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetChess.h"
LastPage=0

ClassCount=20
Class1=CNetChessApp
Class2=CNetChessDoc
Class3=CNetChessView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DIALOG_SCORE
Class5=CAboutDlg
Class6=CServerSocket
Class7=CClientSocket
Resource2=IDR_SHELL_MENU
Class8=COptions
Class9=CServerInfoDlg
Class10=CMessageSend
Class11=CHistoryDlg
Class12=CMyColorDialog
Class13=CPickPieceDlg
Class14=CPropertiesDlg
Class15=CAcceptDlg
Class16=CLostPieceDlg
Class17=CDemo
Resource3=IDD_DISKS
Class18=CDisksDlg
Resource4=IDR_MAINFRAME
Class19=CScoreDlg
Resource5=IDD_ABOUTBOX
Class20=CNewScore
Resource6=IDD_DIALOG_NEW_SCORE

[CLS:CNetChessApp]
Type=0
HeaderFile=NetChess.h
ImplementationFile=NetChess.cpp
Filter=N

[CLS:CNetChessDoc]
Type=0
HeaderFile=NetChessDoc.h
ImplementationFile=NetChessDoc.cpp
Filter=N

[CLS:CNetChessView]
Type=0
HeaderFile=NetChessView.h
ImplementationFile=NetChessView.cpp
Filter=C
LastObject=AFX_ID_PREVIEW_CLOSE
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=AFX_ID_PREVIEW_CLOSE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=NetChess.cpp
ImplementationFile=NetChess.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_EDIT_LEVEL
Command4=ID_EDIT_START
Command5=ID_EDIT_STOP
Command6=ID_EDIT_COLOR_SNAKECOLOR
Command7=ID_EDIT_COLOR_FOODCOLOR
Command8=ID_EDIT_COLOR_BACKGROUNDCOLOR
Command9=ID_EDIT_COLOR_BARCOLOR
Command10=ID_VIEW_HIDE
Command11=ID_VIEW_SCORE
Command12=ID_APP_ABOUT
Command13=ID_HELP_HOWTOPLAY
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_VIEW_HIDE
Command2=ID_FILE_NEW
Command3=ID_EDIT_START
Command4=ID_EDIT_STOP
CommandCount=4

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_VIEW_HIDE
Command3=ID_EDIT_START
Command4=ID_EDIT_STOP
Command5=ID_APP_ABOUT
Command6=AFX_ID_PREVIEW_CLOSE
Command7=AFX_ID_PREVIEW_CLOSE
Command8=AFX_ID_PREVIEW_CLOSE
Command9=ID_FILE_SAVE
Command10=AFX_ID_PREVIEW_CLOSE
Command11=AFX_ID_PREVIEW_CLOSE
Command12=AFX_ID_PREVIEW_CLOSE
Command13=AFX_ID_PREVIEW_CLOSE
Command14=AFX_ID_PREVIEW_CLOSE
Command15=AFX_ID_PREVIEW_CLOSE
Command16=AFX_ID_PREVIEW_CLOSE
Command17=AFX_ID_PREVIEW_CLOSE
Command18=AFX_ID_PREVIEW_CLOSE
Command19=AFX_ID_PREVIEW_CLOSE
CommandCount=19

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=q

[CLS:COptions]
Type=0
HeaderFile=Options.h
ImplementationFile=Options.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATIC_PIECE_TYPE3
VirtualFilter=dWC

[CLS:CServerInfoDlg]
Type=0
HeaderFile=ServerInfoDlg.h
ImplementationFile=ServerInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:CMessageSend]
Type=0
HeaderFile=MessageSend.h
ImplementationFile=MessageSend.cpp
BaseClass=CDialog
Filter=D
LastObject=CMessageSend
VirtualFilter=dWC

[CLS:CHistoryDlg]
Type=0
HeaderFile=HistoryDlg.h
ImplementationFile=HistoryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHistoryDlg

[CLS:CMyColorDialog]
Type=0
HeaderFile=MyColorDialog.h
ImplementationFile=MyColorDialog.cpp
BaseClass=CColorDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyColorDialog

[CLS:CPickPieceDlg]
Type=0
HeaderFile=PickPieceDlg.h
ImplementationFile=PickPieceDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPickPieceDlg
VirtualFilter=dWC

[MNU:IDR_SHELL_MENU]
Type=1
Class=?
Command1=ID_SHELL_CLOSE
Command2=ID_SHELL_VIEW
CommandCount=2

[CLS:CPropertiesDlg]
Type=0
HeaderFile=PropertiesDlg.h
ImplementationFile=PropertiesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CAcceptDlg]
Type=0
HeaderFile=AcceptDlg.h
ImplementationFile=AcceptDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAcceptDlg

[CLS:CLostPieceDlg]
Type=0
HeaderFile=LostPieceDlg.h
ImplementationFile=LostPieceDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[CLS:CDemo]
Type=0
HeaderFile=Demo.h
ImplementationFile=Demo.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[DLG:IDD_DISKS]
Type=1
Class=CDisksDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_1,button,1342177289
Control4=IDC_RADIO_3,button,1342177289
Control5=IDC_RADIO_2,button,1342177289
Control6=IDC_RADIO_4,button,1342177289
Control7=IDC_RADIO_5,button,1342177289
Control8=IDC_RADIO_6,button,1342177289
Control9=IDC_STATIC,button,1342177287
Control10=IDC_RADIO_7,button,1342177289
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_GAME_LEVEL,edit,1350631552

[CLS:CDisksDlg]
Type=0
HeaderFile=DisksDlg.h
ImplementationFile=DisksDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[DLG:IDD_DIALOG_SCORE]
Type=1
Class=CScoreDlg
ControlCount=34
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC_NAME1,static,1342308352
Control5=IDC_STATIC_SCORE1,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC_RANK1,static,1342308352
Control8=IDC_STATIC_NAME2,static,1342308352
Control9=IDC_STATIC_SCORE2,static,1342308352
Control10=IDC_STATIC_RANK2,static,1342308352
Control11=IDC_STATIC_NAME3,static,1342308352
Control12=IDC_STATIC_SCORE3,static,1342308352
Control13=IDC_STATIC_RANK3,static,1342308352
Control14=IDC_STATIC_NAME4,static,1342308352
Control15=IDC_STATIC_SCORE4,static,1342308352
Control16=IDC_STATIC__RANK4,static,1342308352
Control17=IDC_STATIC_NAME5,static,1342308352
Control18=IDC_STATIC_SCORE5,static,1342308352
Control19=IDC_STATIC__RANK5,static,1342308352
Control20=IDC_STATIC__NAME6,static,1342308352
Control21=IDC_STATIC_SCORE6,static,1342308352
Control22=IDC_STATIC__RANK6,static,1342308352
Control23=IDC_STATIC__NAME7,static,1342308352
Control24=IDC_STATIC_SCORE7,static,1342308352
Control25=IDC_STATIC__RANK7,static,1342308352
Control26=IDC_STATIC__NAME8,static,1342308352
Control27=IDC_STATIC_SCORE8,static,1342308352
Control28=IDC_STATIC__RANK8,static,1342308352
Control29=IDC_STATIC__NAME9,static,1342308352
Control30=IDC_STATIC_SCORE9,static,1342308352
Control31=IDC_STATIC__RANK9,static,1342308352
Control32=IDC_STATIC__NAME10,static,1342308352
Control33=IDC_STATIC_SCORE10,static,1342308352
Control34=IDC_STATIC__RANK10,static,1342308352

[CLS:CScoreDlg]
Type=0
HeaderFile=ScoreDlg.h
ImplementationFile=ScoreDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[DLG:IDD_DIALOG_NEW_SCORE]
Type=1
Class=CNewScore
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_NAME,edit,1350631552
Control6=IDC_EDIT_SCORE,edit,1350633600

[CLS:CNewScore]
Type=0
HeaderFile=NewScore.h
ImplementationFile=NewScore.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

