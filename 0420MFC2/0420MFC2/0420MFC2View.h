
// 0420MFC2View.h : CMy0420MFC2View ��Ľӿ�
//

#pragma once
#include "0420MFC2Doc.h"

class CMy0420MFC2View : public CView
{
protected: // �������л�����
	CMy0420MFC2View();
	DECLARE_DYNCREATE(CMy0420MFC2View)

// ����
public:
	CMy0420MFC2Doc* GetDocument() const;
	CRect cr;
	int flag_mouse;//������״̬��1Ϊ���£�0Ϊ����
	int flag_choose;//��Ǿ���ѡ��״̬��1Ϊѡ�У�-1Ϊδѡ��/ȡ��ѡ�С�
	CPoint mouse;//��¼���λ��
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
	virtual ~CMy0420MFC2View();
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
	afx_msg void OnDrawing();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColoring();
};

#ifndef _DEBUG  // 0420MFC2View.cpp �еĵ��԰汾
inline CMy0420MFC2Doc* CMy0420MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0420MFC2Doc*>(m_pDocument); }
#endif

