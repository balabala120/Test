
// 0323MFC1_1View.h : CMy0323MFC1_1View ��Ľӿ�
//

#pragma once


class CMy0323MFC1_1View : public CView
{
protected: // �������л�����
	CMy0323MFC1_1View();
	DECLARE_DYNCREATE(CMy0323MFC1_1View)

// ����
public:
	CMy0323MFC1_1Doc* GetDocument() const;
	CArray<CRect, CRect& > cs;//����
	CPoint center;
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
	virtual ~CMy0323MFC1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircles();
};

#ifndef _DEBUG  // 0323MFC1_1View.cpp �еĵ��԰汾
inline CMy0323MFC1_1Doc* CMy0323MFC1_1View::GetDocument() const
   { return reinterpret_cast<CMy0323MFC1_1Doc*>(m_pDocument); }
#endif

