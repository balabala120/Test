
// 0324MFC3View.h : CMy0324MFC3View ��Ľӿ�
//

#pragma once


class CMy0324MFC3View : public CView
{
protected: // �������л�����
	CMy0324MFC3View();
	DECLARE_DYNCREATE(CMy0324MFC3View)

// ����
public:
	CMy0324MFC3Doc* GetDocument() const;
	CPoint point1, point2;
	CRect cr;
	int flag;
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
	virtual ~CMy0324MFC3View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
};

#ifndef _DEBUG  // 0324MFC3View.cpp �еĵ��԰汾
inline CMy0324MFC3Doc* CMy0324MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0324MFC3Doc*>(m_pDocument); }
#endif

