
// 0414MFC2View.h : CMy0414MFC2View ��Ľӿ�
//

#pragma once


class CMy0414MFC2View : public CView
{
protected: // �������л�����
	CMy0414MFC2View();
	DECLARE_DYNCREATE(CMy0414MFC2View)

// ����
public:
	CMy0414MFC2Doc* GetDocument() const;
	CString filename;
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
	virtual ~CMy0414MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnShowfname();
};

#ifndef _DEBUG  // 0414MFC2View.cpp �еĵ��԰汾
inline CMy0414MFC2Doc* CMy0414MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0414MFC2Doc*>(m_pDocument); }
#endif

