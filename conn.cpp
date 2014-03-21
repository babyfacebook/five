// conn.cpp : implementation file
//

#include "stdafx.h"
#include "five.h"
#include "conn.h"
#include "fiveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// conn dialog


conn::conn(CWnd *pParent /*=NULL*/)
    : CDialog(conn::IDD, pParent)
{
    //{{AFX_DATA_INIT(conn)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}

void conn::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(conn)
    DDX_Control(pDX, IDC_IPADDRESS2, m_ipAddr);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(conn, CDialog)
    //{{AFX_MSG_MAP(conn)
    ON_BN_CLICKED(IDOK, OnOk)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// conn message handlers

void conn::OnOk()
{
    unsigned  char  *pIP;
    CString   strIP;
    DWORD   dwIP;
    m_ipAddr.GetAddress(dwIP);
    if(dwIP == 0)
    {
        AfxMessageBox("IP地址不能为空");
        return;
    }
    pIP   =   (unsigned   char *)&dwIP;
    strIP.Format("%u.%u.%u.%u ", *(pIP + 3),  *(pIP + 2),  *(pIP + 1),  *pIP);
    CFiveDlg::server = strIP;
	//AfxMessageBox("IP地址："+strIP);
    SendMessage(WM_CLOSE);
}

BOOL conn::PreTranslateMessage(MSG* pMsg) 
{
	if(WM_KEYDOWN == pMsg->message)
    {
        if(pMsg->hwnd == m_ipAddr.GetSafeHwnd() && VK_RETURN == pMsg->wParam)
        {
			OnOk();
            return TRUE;
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}
