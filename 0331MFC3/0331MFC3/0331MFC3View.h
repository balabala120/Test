
// 0331MFC3View.h : CMy0331MFC3View ��Ľӿ�
//

#pragma once


class CMy0331MFC3View : public CView
{
protected: // �������л�����
	CMy0331MFC3View();
	DECLARE_DYNCREATE(CMy0331MFC3View)
	CRect cr;
	CString s;

// ����
public:
	CMy0331MFC3Doc* GetDocument() const;

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
	virtual ~CMy0331MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 0331MFC3View.cpp �еĵ��԰汾
inline CMy0331MFC3Doc* CMy0331MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0331MFC3Doc*>(m_pDocument); }
#endif

