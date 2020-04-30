
// 0427MFC2View.h : CMy0427MFC2View 类的接口
//

#pragma once


class CMy0427MFC2View : public CView
{
protected: // 仅从序列化创建
	CMy0427MFC2View();
	DECLARE_DYNCREATE(CMy0427MFC2View)

// 特性
public:
	CMy0427MFC2Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CPoint mouse;//记录鼠标按下的位置
	int flag_mouse;//标记鼠标状态，1为按下，0为弹起。
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
	virtual ~CMy0427MFC2View();
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

#ifndef _DEBUG  // 0427MFC2View.cpp 中的调试版本
inline CMy0427MFC2Doc* CMy0427MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0427MFC2Doc*>(m_pDocument); }
#endif

