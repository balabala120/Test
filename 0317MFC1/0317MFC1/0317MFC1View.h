
// 0317MFC1View.h : CMy0317MFC1View ��Ľӿ�
//

#pragma once


class CMy0317MFC1View : public CView
{
protected: // �������л�����
	CMy0317MFC1View();
	DECLARE_DYNCREATE(CMy0317MFC1View)

// ����
public:
	CMy0317MFC1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy0317MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0317MFC1View.cpp �еĵ��԰汾
inline CMy0317MFC1Doc* CMy0317MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0317MFC1Doc*>(m_pDocument); }
#endif

