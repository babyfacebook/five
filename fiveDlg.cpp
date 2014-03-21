// fiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "five.h"
#include "fiveDlg.h"
#include "Match.h"
#include "About.h"
#include "conn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// ���������¼�֪ͨ��Ϣ
#define WM_SOCKET WM_USER + 1
#define TOPDIS 20
#define LEFTDIS 100
/////////////////////////////////////////////////////////////////////////////
// CFiveDlg dialog

CFiveDlg::CFiveDlg(CWnd *pParent /*=NULL*/)
    : CDialog(CFiveDlg::IDD, pParent)
{

    //{{AFX_DATA_INIT(CFiveDlg)
	//}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

CString CFiveDlg::server = "127.0.0.1";

void CFiveDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CFiveDlg)
    DDX_Control(pDX, IDC_EDIT_SEND, m_EditSend);
    DDX_Control(pDX, IDC_EDIT, m_Edit);
    DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiveDlg, CDialog)
    //{{AFX_MSG_MAP(CFiveDlg)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_COMMAND(IDI_START, OnStart)
    ON_COMMAND(IDI_CONN, OnConn)
    ON_WM_LBUTTONDOWN()
    ON_WM_DESTROY()
    ON_COMMAND(IDI_EXIT, OnExit)
    ON_COMMAND(IDI_ABOUT, OnAbout)
    ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
    ON_MESSAGE(WM_SOCKET, OnSocket)
    ON_BN_CLICKED(IDC_BUTTON, OnButton)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveDlg message handlers

BOOL CFiveDlg::OnInitDialog()
{
    SetWindowSkin(m_hWnd, "Dialog");
    SetDialogSkin("Dialog");
    CDialog::OnInitDialog();

    // ��ʼ��Winsock��
    WSADATA wsaData;
    WSAStartup(0x0202, &wsaData);
    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon
    m_Start = FALSE;
    m_Bind = FALSE;
    m_bOver = FALSE;
    m_bWin = FALSE;
    m_turn = 1; //����������,����
    //��ʼ�����촰��
    LV_ITEM lvItem;
    lvItem.mask = LVIF_TEXT;
    lvItem.iItem = 1;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "�ܲ��ܿ�㰡���ҵȵĻ���л��";
    //�����һ�в����¼ֵ.
    m_List.InsertItem(&lvItem);
    lvItem.iItem = 2;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "�����̿϶�Ӯ��";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 3;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "�Ҹղ��в��ߴ��ˣ���Ȼ��Ӯ��";
    m_List.InsertItem(&lvItem);


    lvItem.iItem = 4;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "��Ҫ�ߣ��Ȼ�����һ�̰�";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 5;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "��ô�ö����£��㲻��ȥ���˰�";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 6;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "���ѽ������к���";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 7;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "���ѽ������GG����MM��";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 8;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "��ô��������´��������";
    m_List.InsertItem(&lvItem);

    lvItem.iItem = 9;     //����
    lvItem.iSubItem = 0;
    lvItem.pszText = "������˼����Ҫ�뿪�ˣ�Bye";
    m_List.InsertItem(&lvItem);

    m_List.EnableWindow(FALSE);
	m_Edit.EnableWindow(FALSE);
    GetDlgItem(IDC_BUTTON)->EnableWindow(FALSE);
    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFiveDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {

        CDialog::OnPaint();

        CDC *pDC = this->GetDC();
        CBrush back(RGB(203, 160, 135));
        pDC->SelectObject((CBrush *)&back);

        CRect rect;
        rect.left = LEFTDIS;
        rect.right = LEFTDIS + (LW - 1) * 30;
        rect.top = TOPDIS;
        rect.bottom = TOPDIS + (LW - 1) * 30;
        pDC->FillRect(&rect, &back);

        CPen pen(PS_SOLID, 1, RGB(100, 100, 100));
        pDC->SelectObject((CPen *)&pen);
        int i, j;
        CPoint pos;
        for(i = 0; i < LW; i++) //��ֱ����
        {
            pos.x = LEFTDIS + 30 * i;
            pos.y = TOPDIS;
            pDC->MoveTo(pos);
            pos.y = TOPDIS + (LW - 1) * 30;
            pDC->LineTo(pos);
        }
        for(i = 0; i < LW; i++) //ˮƽ����
        {
            pos.x = LEFTDIS;
            pos.y = TOPDIS + 30 * i;
            pDC->MoveTo(pos);
            pos.x = LEFTDIS + (LW - 1) * 30;
            pDC->LineTo(pos);
        }
        //��������
        CBrush whitebrush(RGB(255, 255, 255));
        CBrush blackbrush(RGB(0, 0, 0));
        for(i = 0; i < LW; i++)
            for(j = 0; j < LW; j++)
            {
                if(m_match.chessboard[i][j] == 1)
                {
                    pDC->SelectObject((CBrush *)&blackbrush);
                    pDC->Ellipse(j * 30 + LEFTDIS - 15, i * 30 + TOPDIS - 15, j * 30 + LEFTDIS + 15, i * 30 + TOPDIS + 15);
                }
                else if(m_match.chessboard[i][j] == 2)
                {
                    pDC->SelectObject((CBrush *)&whitebrush);
                    pDC->Ellipse(j * 30 + LEFTDIS - 15, i * 30 + TOPDIS - 15, j * 30 + LEFTDIS + 15, i * 30 + TOPDIS + 15);
                }
            }

        if(m_bOver == TRUE)
        {
            CBrush redbrush(RGB(255, 0, 0));
            pDC->SelectObject((CBrush *)&redbrush);
            for(int k = 0; k < 5; k++)
            {
                i = m_winpos[k][0];
                j = m_winpos[k][1];
                pDC->Ellipse(j * 30 + LEFTDIS - 15, i * 30 + TOPDIS - 15, j * 30 + LEFTDIS + 15, i * 30 + TOPDIS + 15);
            }
        }
    }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFiveDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CFiveDlg::OnStart()
{
    if(!m_Bind)
    {
        SOCKET s;
        // �����׽���
        s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(s == INVALID_SOCKET)
            ::closesocket(s);

        sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(6666);
        sin.sin_addr.s_addr = INADDR_ANY;

        // �󶨶˿�
        if(::bind(s, (sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
        {
            AfxMessageBox("��ʧ��");
            return;
        }
        m_Bind = TRUE;
        //AfxMessageBox("�����ɹ�");
        SetWindowText("��Ϊ�����������������ڵȴ�.....");
        ::WSAAsyncSelect(s, m_hWnd, WM_SOCKET, FD_ACCEPT | FD_CLOSE);
        // �������ģʽ
        ::listen(s, 2);

        // �رռ����׽���
        //::closesocket(s);
        // �ͷ�WS2_32��
        //::WSACleanup();
    }
    else
    {
        AfxMessageBox("�Ѿ��󶨾Ͳ����ٰ���");
    }

}

void CFiveDlg::OnConn()
{

    if(m_Bind)
    {
        AfxMessageBox("�Ѿ������˷������Ͳ���������");
        return;
    }

    conn c;
    c.DoModal();

    // �����׽���
    client = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(client == INVALID_SOCKET)
        ::closesocket(client);

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(6666);
    sin.sin_addr.s_addr = inet_addr(server);
    ::WSAAsyncSelect(client, m_hWnd,
                     WM_SOCKET, FD_CONNECT);
    // ���ӵ�Զ�̻�
    int i=connect(client, (sockaddr *)&sin, sizeof(sockaddr));
	//CString con;
	//con.Format("%d",i);
	//AfxMessageBox("������Ϣ:"+con);
	// ����socketΪ����֪ͨ��Ϣ����
    
	//AfxMessageBox(WSAGetLastError);
    //::closesocket(s);
    // �ͷ�WS2_32��
    //::WSACleanup();
}

void CFiveDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    CDialog::OnLButtonDown(nFlags, point);

    if(!m_Start)
    {
        AfxMessageBox("��û��ʼ��");
        return;
    }
    if(m_bOver == TRUE)
    {
        return;
    }
    if(m_turn == m_who)
    {
        m_POS[0] = (point.y - TOPDIS) / 30;	//x	,��ͼ�����е�y
        //���û����ȫ����ڵ��ϸ�������ж��Ƿ��һ
        if((point.y - TOPDIS) % 30 > 15)
            m_POS[0]++;
        m_POS[1] = (point.x - LEFTDIS) / 30;	//y ,��ͼ�����е�x
        if((point.x - LEFTDIS) % 30 > 15)
            m_POS[1]++;


        if(m_POS[0] < 0 || m_POS[0] >= LW || m_POS[1] < 0 || m_POS[1] >= LW)
        {
            return;
        }
        if(m_match.CanDown(m_POS[0], m_POS[1], m_who) == TRUE)
        {
            PlaySound((LPCTSTR)IDR_WAVE_DWON, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
            //�ػ�
            Invalidate(FALSE);
            m_turn = m_who % 2 + 1;
            char msg[16] = "";
            char *p;

            CString turn;
            CString x;
            CString y;

            turn.Format("%d", m_turn);
            x.Format("%d", m_POS[0]);
            y.Format("%d", m_POS[1]);
            CString cs(turn + "," + x + "," + y);

            p = (LPSTR)(LPCTSTR)cs;
            strcat(msg, p);

            //AfxMessageBox(msg);

            ::send(client, msg, strlen(msg), 0);

            if(m_match.IsWin(m_who, m_winpos))
            {
                PlaySound((LPCTSTR)IDR_WAVE_WIN, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
                m_bWin = TRUE;
                m_bOver = TRUE;
                Invalidate(FALSE);
                if(AfxMessageBox("��Ӯ��,���¿�ʼ��Ϸ��?", MB_YESNO) == IDYES)
                {
                    //���¿�ʼ��Ϸ
                    PlaySound((LPCTSTR)IDR_WAVE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
                    m_turn = 1;
                    m_match.Clear();
                    m_bWin = FALSE;
                    m_bOver = FALSE;
                    Invalidate(FALSE);

                }
                else
                {
                    SendMessage(WM_CLOSE);
                }
            }
        }
    }
    else
    {

        AfxMessageBox("���ڲ���������");
    }

}

void CFiveDlg::OnDestroy()
{

    CDialog::OnDestroy();


}

long CFiveDlg::OnSocket(WPARAM wParam, LPARAM lParam)
{


    // ȡ�����¼��������׽��־��
    SOCKET s = wParam;
    // �鿴�Ƿ����
    if(WSAGETSELECTERROR(lParam))
    {
        //AfxMessageBox("�����쳣�����������ֹ");
        //SendMessage(WM_CLOSE);

    }

    // ���������¼�
    switch(WSAGETSELECTEVENT(lParam))
    {
    case FD_ACCEPT:	// �����е��׽��ּ�⵽�����ӽ���
    {
		if(m_Start){
		return -1;
		}
        m_Start = TRUE;
        m_who = 1;
        //AfxMessageBox("��Ϊ������");
        m_List.EnableWindow(TRUE);
        GetDlgItem(IDC_BUTTON)->EnableWindow(TRUE);
		m_Edit.EnableWindow(TRUE);
        SetWindowText("��Ϊ��������������");
        PlaySound((LPCTSTR)IDR_WAVE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
        // ������������
        client = ::accept(s, NULL, NULL);
        // �����µ��׽���Ϊ����֪ͨ��Ϣ����
        int i = ::WSAAsyncSelect(client,
                                 m_hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_CLOSE);

    }
    break;
    case FD_CONNECT:	
		// �׽�����ȷ�����ӵ�������
    {
		
        // �����û�����
        m_Start = TRUE;
        m_List.EnableWindow(TRUE);
		m_Edit.EnableWindow(TRUE);
        GetDlgItem(IDC_BUTTON)->EnableWindow(TRUE);
		WSAAsyncSelect(client, m_hWnd, WM_SOCKET, FD_READ | FD_WRITE | FD_CLOSE);
        m_who = 2;
        PlaySound((LPCTSTR)IDR_WAVE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
        SetWindowText("�Ѿ����ӵ���������������");

    }
    break;

    case FD_READ:		// �׽��ֽ��ܵ��Է����͹��������ݰ�
    {
        //�ӷ�������������
        char buf[256] = "\0";
        ::recv(s, buf, 256, 0);
        // ��ʾ���û�
        //AfxMessageBox(buf);
        if(buf > 0)
        {

            CString cs(buf);
            int chat = cs.Find(':');

            if(chat != -1)
            {
				CString temp;
				m_Edit.GetWindowText(temp);
				m_Edit.SetWindowText(cs+"\r\n"+temp);
                break;
            }
            int n = cs.Find(',');
            CString turn = cs.Left(n);

            int n1 = cs.Find(',', n + 1);

            CString x = cs.Mid(n + 1, n1 - 2);

            CString y = cs.Mid(n1 + 1, cs.GetLength());


            int i_turn = _ttoi(turn);
            int i = _ttoi(x);
            int j = _ttoi(y);

            if(this->m_match.CanDown(i, j, this->m_who % 2 + 1))
            {


                this->m_turn = i_turn;
                this->Invalidate(FALSE);
                if(this->m_match.IsWin(this->m_who % 2 + 1, this->m_winpos))
                {
                    PlaySound((LPCTSTR)IDR_WAVE_LOSE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
                    this->m_bWin = TRUE;
                    this->m_bOver = TRUE;
                    this->Invalidate(FALSE);
                    if(AfxMessageBox("������,���¿�ʼ��Ϸ��?", MB_YESNO) == IDYES)
                    {
                        PlaySound((LPCTSTR)IDR_WAVE, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
                        //���¿�ʼ��Ϸ
                        m_turn = 1;
                        m_match.Clear();
                        m_bWin = FALSE;
                        m_bOver = FALSE;
                        Invalidate(FALSE);

                    }
                    else
                    {
                        SendMessage(WM_CLOSE);
                    }
                }
            }


        }
    }
    break;

    case FD_CLOSE:
        AfxMessageBox("�Է��Ѿ��뿪,���򽫹ر�");
        ::closesocket(client);
        ::WSACleanup();
        SendMessage(WM_CLOSE);
        break;

    }
    return 0;
}

void CFiveDlg::OnExit()
{
    SendMessage(WM_CLOSE);
}

void CFiveDlg::OnAbout()
{
    About about;
    about.DoModal();
}

void CFiveDlg::OnClickList(NMHDR *pNMHDR, LRESULT *pResult)
{

    HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
    DWORD dwPos = GetMessagePos();
    CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
    m_List.ScreenToClient(&point);

    LVHITTESTINFO lvinfo;
    lvinfo.pt = point;
    lvinfo.flags = LVHT_ABOVE;
    int nItem = m_List.SubItemHitTest(&lvinfo);
    if(nItem != -1)
    {
        char str[128] = "\0";
        LVITEM lvi;
        lvi.iItem = lvinfo.iItem;
        lvi.iSubItem = lvinfo.iSubItem;
        lvi.mask = LVIF_TEXT;
        lvi.pszText = str;
        lvi.cchTextMax = 256;
        m_List.GetItem(&lvi);
        //AfxMessageBox(str);

        char msg[200] = "";
        gethostname(msg, sizeof(msg));
		
        strcat(msg, "˵:");
        strcat(msg, str);
        ::send(client, msg, strlen(msg), 0);
		CString temp;
		m_Edit.GetWindowText(temp);
		CString cs(str);
		cs="��˵:"+cs;
		m_Edit.SetWindowText(cs+"\r\n"+temp);
    }

    *pResult = 0;
}

BOOL CFiveDlg::PreTranslateMessage(MSG *pMsg)
{
    if(WM_KEYDOWN == pMsg->message)
    {
        if(pMsg->hwnd == m_EditSend.GetSafeHwnd() && VK_RETURN == pMsg->wParam)
        {
            OnButton();
            return TRUE;
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}

void CFiveDlg::OnButton()
{
    char *p;
    CString cs;
	CString temp;
    m_EditSend.GetWindowText(cs);
	m_Edit.GetWindowText(temp);
	m_Edit.SetWindowText("��˵:"+cs+"\r\n"+temp);

    char msg[200] = "";
    gethostname(msg, sizeof(msg));
    strcat(msg, "˵:");
    p = (LPSTR)(LPCTSTR)cs;
    strcat(msg, p);
    ::send(client, msg, strlen(msg), 0);
}
