
// 0316MFCView.h : CMy0316MFCView ��Ľӿ�
//

#pragma once


class CMy0316MFCView : public CView
{
protected: // �������л�����
	CMy0316MFCView();
	DECLARE_DYNCREATE(CMy0316MFCView)

// ����
public:
	CMy0316MFCDoc* GetDocument() const;

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
	virtual ~CMy0316MFCView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0316MFCView.cpp �еĵ��԰汾
inline CMy0316MFCDoc* CMy0316MFCView::GetDocument() const
   { return reinterpret_cast<CMy0316MFCDoc*>(m_pDocument); }
#endif

