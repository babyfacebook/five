; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFiveDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "five.h"

ClassCount=4
Class1=CFiveApp
Class2=CFiveDlg

ResourceCount=5
Resource2=IDD_DIALOG_ABOUT
Resource3=IDD_DIALOG_CONN
Resource1=IDR_MAINFRAME
Class3=About
Resource4=IDD_FIVE_DIALOG
Class4=conn
Resource5=IDR_MENU

[CLS:CFiveApp]
Type=0
HeaderFile=five.h
ImplementationFile=five.cpp
Filter=N
LastObject=CFiveApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CFiveDlg]
Type=0
HeaderFile=fiveDlg.h
ImplementationFile=fiveDlg.cpp
Filter=D
LastObject=CFiveDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_FIVE_DIALOG]
Type=1
Class=CFiveDlg
ControlCount=5
Control1=IDC_LIST,SysListView32,1350631427
Control2=IDC_EDIT,edit,1352730692
Control3=IDC_EDIT_SEND,edit,1352728644
Control4=IDC_BUTTON,button,1342242816
Control5=IDC_STATIC,button,1476395015

[MNU:IDR_MENU]
Type=1
Class=CFiveDlg
Command1=IDI_START
Command2=IDI_CONN
Command3=IDI_ABOUT
Command4=IDI_EXIT
CommandCount=4

[DLG:IDD_DIALOG_ABOUT]
Type=1
Class=About
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352

[CLS:About]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_DIALOG_CONN]
Type=1
Class=conn
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_IPADDRESS2,SysIPAddress32,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:conn]
Type=0
HeaderFile=conn.h
ImplementationFile=conn.cpp
BaseClass=CDialog
Filter=D
LastObject=conn
VirtualFilter=dWC

