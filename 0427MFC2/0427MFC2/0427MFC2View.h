
// 0427MFC2View.h : CMy0427MFC2View ��Ľӿ�
//

#pragma once


class CMy0427MFC2View : public CView
{
protected: // �������л�����
	CMy0427MFC2View();
	DECLARE_DYNCREATE(CMy0427MFC2View)

// ����
public:
	CMy0427MFC2Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CPoint mouse;//��¼��갴�µ�λ��
	int flag_mouse;//������״̬��1Ϊ���£�0Ϊ����
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
	virtual ~CMy0427MFC2View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0427MFC2View.cpp �еĵ��԰汾
inline CMy0427MFC2Doc* CMy0427MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0427MFC2Doc*>(m_pDocument); }
#endif

