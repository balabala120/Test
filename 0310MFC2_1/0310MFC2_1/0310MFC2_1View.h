
// 0310MFC2_1View.h : CMy0310MFC2_1View 类的接口
//

#pragma once


class CMy0310MFC2_1View : public CView
{
protected: // 仅从序列化创建
	CMy0310MFC2_1View();
	DECLARE_DYNCREATE(CMy0310MFC2_1View)

// 特性
public:
	CMy0310MFC2_1Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect &> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0310MFC2_1View();
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
};

#ifndef _DEBUG  // 0310MFC2_1View.cpp 中的调试版本
inline CMy0310MFC2_1Doc* CMy0310MFC2_1View::GetDocument() const
   { return reinterpret_cast<CMy0310MFC2_1Doc*>(m_pDocument); }
#endif

