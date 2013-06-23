
// myGraphicView.h : CmyGraphicView 类的接口
//

#pragma once
#include "atltypes.h"


class CmyGraphicView : public CView
{
protected: // 仅从序列化创建
	CmyGraphicView();
	DECLARE_DYNCREATE(CmyGraphicView)

// 特性
public:
	CmyGraphicDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmyGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnEllipse();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
private:
	unsigned int m_nDrawType;
public:
	afx_msg void OnSetting();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
	unsigned int m_nLineWidth;
	int m_nLineStyle;
};

#ifndef _DEBUG  // myGraphicView.cpp 中的调试版本
inline CmyGraphicDoc* CmyGraphicView::GetDocument() const
   { return reinterpret_cast<CmyGraphicDoc*>(m_pDocument); }
#endif

