
// myGraphicView.cpp : CmyGraphicView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "myGraphic.h"
#endif

#include "myGraphicDoc.h"
#include "myGraphicView.h"

#include"SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyGraphicView

IMPLEMENT_DYNCREATE(CmyGraphicView, CView)

BEGIN_MESSAGE_MAP(CmyGraphicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmyGraphicView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_DOT, &CmyGraphicView::OnDot)
	ON_COMMAND(ID_ELLIPSE, &CmyGraphicView::OnEllipse)
	ON_COMMAND(IDM_LINE, &CmyGraphicView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CmyGraphicView::OnRectangle)
	ON_COMMAND(IDM_SETTING, &CmyGraphicView::OnSetting)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CmyGraphicView 构造/析构

CmyGraphicView::CmyGraphicView()
	: m_nDrawType(0)
	, m_ptOrigin(0)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	// TODO: 在此处添加构造代码
	m_nDrawType=0;
	m_ptOrigin=0;
	m_nLineWidth=0;
	m_nLineStyle=0;

}

CmyGraphicView::~CmyGraphicView()
{
}

BOOL CmyGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmyGraphicView 绘制

void CmyGraphicView::OnDraw(CDC* /*pDC*/)
{
	CmyGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CmyGraphicView 打印


void CmyGraphicView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmyGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmyGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmyGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CmyGraphicView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmyGraphicView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmyGraphicView 诊断

#ifdef _DEBUG
void CmyGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CmyGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmyGraphicDoc* CmyGraphicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyGraphicDoc)));
	return (CmyGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyGraphicView 消息处理程序


void CmyGraphicView::OnDot()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=1;
}

void CmyGraphicView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=2;
}

void CmyGraphicView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=3;
}

void CmyGraphicView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nDrawType=4;
}

void CmyGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_ptOrigin=point;
	CView::OnLButtonDown(nFlags, point);
}


void CmyGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(m_nLineStyle,m_nLineWidth,RGB(255,0,0));
	dc.SelectObject(&pen);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	switch(m_nDrawType)
	{
	case 1:
		dc.SetPixel(point,RGB(255,0,0));
		break;
	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		dc.Rectangle(CRect(m_ptOrigin,point));
		break;
	case 4:
		dc.Ellipse(CRect(m_ptOrigin,point));
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}





void CmyGraphicView::OnSetting()
{
	// TODO: 在此添加命令处理程序代码
	static CSettingDlg dlg;
//	dlg.m_nLineWidth=m_nLineWidth;
	if(IDOK==dlg.DoModal())
	{
		m_nLineWidth=dlg.m_nLineWidth;
		m_nLineStyle=dlg.m_nLineStyle;
	}
}



