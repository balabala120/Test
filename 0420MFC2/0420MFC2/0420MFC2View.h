
// 0420MFC2View.h : CMy0420MFC2View 类的接口
//

#pragma once
#include "0420MFC2Doc.h"

class CMy0420MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0420MFC2View();
	DECLARE_DYNCREATE(CMy0420MFC2View)

// 特性
public:
	CMy0420MFC2Doc* GetDocument() const;
	CRect cr;
	int flag_mouse;//标记鼠标状态，1为按下，0为弹起。
	int flag_choose;//标记矩形选中状态，1为选中，-1为未选中/取消选中。
	CPoint mouse;//记录鼠标位置
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
	virtual ~CMy0420MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawing();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColoring();
};

#ifndef _DEBUG  // 0420MFC2View.cpp 中的调试版本
inline CMy0420MFC2Doc* CMy0420MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0420MFC2Doc*>(m_pDocument); }
#endif

