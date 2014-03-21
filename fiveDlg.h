// fiveDlg.h : header file
//

#if !defined(AFX_FIVEDLG_H__5017201A_8D12_4134_BB87_CA6946AE96C7__INCLUDED_)
#define AFX_FIVEDLG_H__5017201A_8D12_4134_BB87_CA6946AE96C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000
#include "Match.h"

/////////////////////////////////////////////////////////////////////////////
// CFiveDlg dialog

class CFiveDlg : public CDialog
{
    // Construction
public:
    CFiveDlg(CWnd *pParent = NULL);	// standard constructor
	
	BOOL            m_Start;
    Match			m_match;
    int				m_who;
    int				m_turn;//轮谁走棋
    int				m_POS[2];//落子的位置
    int				m_winpos[5][2];
    BOOL			m_bWin;	//赢了吗
    BOOL			m_bOver;//结束了
    BOOL			m_Bind;
    SOCKET			client;
    static CString server;
    // Dialog Data
    //{{AFX_DATA(CFiveDlg)
	enum { IDD = IDD_FIVE_DIALOG };
	CEdit	m_EditSend;
	CEdit	m_Edit;
	CListCtrl	m_List;
	//}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CFiveDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
    virtual void DoDataExchange(CDataExchange *pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

    // Implementation
protected:
    HICON m_hIcon;
    afx_msg long OnSocket(WPARAM wParam, LPARAM lParam);
    // Generated message map functions
    //{{AFX_MSG(CFiveDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnStart();
    afx_msg void OnConn();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnDestroy();
    afx_msg void OnExit();
    afx_msg void OnAbout();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVEDLG_H__5017201A_8D12_4134_BB87_CA6946AE96C7__INCLUDED_)
