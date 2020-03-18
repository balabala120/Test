
// 0317MFC2View.h : CMy0317MFC2View 类的接口
//

#pragma once


class CMy0317MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0317MFC2View();
	DECLARE_DYNCREATE(CMy0317MFC2View)

// 特性
public:
	CMy0317MFC2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0317MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0317MFC2View.cpp 中的调试版本
inline CMy0317MFC2Doc* CMy0317MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0317MFC2Doc*>(m_pDocument); }
#endif

