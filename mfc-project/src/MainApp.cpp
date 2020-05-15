#include <MainApp.hpp>

MyApp app;

BOOL MyApp::InitInstance()
{
    MyFrame *frame = new MyFrame;
    frame->ShowWindow(SW_SHOWNORMAL);
    frame->UpdateWindow();
    m_pMainWnd = frame; //保存指向应用程序的主窗口的指针
    return TRUE;
}

//注册消息处理函数
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)

ON_WM_LBUTTONDOWN()
ON_WM_CHAR()
ON_WM_PAINT()

END_MESSAGE_MAP()

MyFrame::MyFrame()
{
    Create(NULL, TEXT("windows"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
    CString str;
    str.Format(TEXT("x = % d, y = % d"), point.x, point.y);
    MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT)
{
    CString str;
    str.Format(TEXT("输入 %c"), key);
    MessageBox(str);
}

void MyFrame::OnPaint()
{
    CPaintDC dc(this);
    dc.TextOut(100, 100, TEXT("Hello World"));
    dc.Ellipse(10, 10, 100, 100);
}
