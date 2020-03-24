
// 0324MFC3View.h : CMy0324MFC3View 类的接口
//

#pragma once


class CMy0324MFC3View : public CView
{
protected: // 仅从序列化创建
	CMy0324MFC3View();
	DECLARE_DYNCREATE(CMy0324MFC3View)

// 特性
public:
	CMy0324MFC3Doc* GetDocument() const;
	CPoint point1, point2;
	CRect cr;
	int flag;
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
	virtual ~CMy0324MFC3View();
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
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // 0324MFC3View.cpp 中的调试版本
inline CMy0324MFC3Doc* CMy0324MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0324MFC3Doc*>(m_pDocument); }
#endif

