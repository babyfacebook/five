// About.cpp : implementation file
//

#include "stdafx.h"
#include "five.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// About dialog


About::About(CWnd *pParent /*=NULL*/)
    : CDialog(About::IDD, pParent)
{
    //{{AFX_DATA_INIT(About)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void About::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(About)
    // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(About, CDialog)
    //{{AFX_MSG_MAP(About)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// About message handlers

void About::OnOK()
{

    SendMessage(WM_CLOSE);
    CDialog::OnOK();
}
