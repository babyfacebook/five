// five.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "five.h"
#include "fiveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFiveApp

BEGIN_MESSAGE_MAP(CFiveApp, CWinApp)
    //{{AFX_MSG_MAP(CFiveApp)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveApp construction

CFiveApp::CFiveApp()
{
    // TODO: add construction code here,
    AfxGetApp()->m_pszAppName = "������";
    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFiveApp object

CFiveApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFiveApp initialization

BOOL CFiveApp::InitInstance()
{

	VERIFY( 1 == InitSkinMagicLib(AfxGetInstanceHandle(), NULL, NULL, NULL));

	if(0==LoadSkinFile("x-plus.smf"))
	{
		AfxMessageBox("����Ƥ��ʧ��");
	}

    AfxEnableControlContainer();
	
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#ifdef _AFXDLL
    Enable3dControls();			// Call this when using MFC in a shared DLL
#else
    Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    CFiveDlg dlg;
    m_pMainWnd = &dlg;
    int nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}

int CFiveApp::ExitInstance() 
{
	ExitSkinMagicLib();
	return CWinApp::ExitInstance();
}
