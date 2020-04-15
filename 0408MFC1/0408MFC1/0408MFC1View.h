
// 0408MFC1View.h : CMy0408MFC1View 类的接口
//

#pragma once


class CMy0408MFC1View : public CView
{
protected: // 仅从序列化创建
	CMy0408MFC1View();
	DECLARE_DYNCREATE(CMy0408MFC1View)

// 特性
public:
	CMy0408MFC1Doc* GetDocument() const;
	CRect cr;
	CPoint mouse;//用于记录鼠标移动距离
	int flag;//用于标记鼠标左键是否按下
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0408MFC1View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0408MFC1View.cpp 中的调试版本
inline CMy0408MFC1Doc* CMy0408MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0408MFC1Doc*>(m_pDocument); }
#endif

