
// 0330MFC1View.h : CMy0330MFC1View 类的接口
//

#pragma once


class CMy0330MFC1View : public CView
{
protected: // 仅从序列化创建
	CMy0330MFC1View();
	DECLARE_DYNCREATE(CMy0330MFC1View)

// 特性
public:
	CMy0330MFC1Doc* GetDocument() const;

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
	virtual ~CMy0330MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 0330MFC1View.cpp 中的调试版本
inline CMy0330MFC1Doc* CMy0330MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0330MFC1Doc*>(m_pDocument); }
#endif

