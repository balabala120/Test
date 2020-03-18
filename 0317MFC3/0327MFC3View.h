
// 0327MFC3View.h : CMy0327MFC3View 类的接口
//

#pragma once


class CMy0327MFC3View : public CView
{
protected: // 仅从序列化创建
	CMy0327MFC3View();
	DECLARE_DYNCREATE(CMy0327MFC3View)

// 特性
public:
	CMy0327MFC3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMy0327MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 0327MFC3View.cpp 中的调试版本
inline CMy0327MFC3Doc* CMy0327MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0327MFC3Doc*>(m_pDocument); }
#endif

