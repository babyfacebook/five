#if !defined(AFX_CONN_H__58BDAD86_7994_4A12_9951_025B47E6CA7C__INCLUDED_)
#define AFX_CONN_H__58BDAD86_7994_4A12_9951_025B47E6CA7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// conn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// conn dialog

class conn : public CDialog
{
    // Construction
public:
    conn(CWnd *pParent = NULL);   // standard constructor
    // Dialog Data
    //{{AFX_DATA(conn)
    enum { IDD = IDD_DIALOG_CONN };
    CIPAddressCtrl	m_ipAddr;
    //}}AFX_DATA


    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(conn)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
    virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

    // Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(conn)
    afx_msg void OnOk();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONN_H__58BDAD86_7994_4A12_9951_025B47E6CA7C__INCLUDED_)
