
// 0414MFC3View.h : CMy0414MFC3View ��Ľӿ�
//

#pragma once

#include "MyDlg2.h"
class CMy0414MFC3View : public CView
{
protected: // �������л�����
	CMy0414MFC3View();
	DECLARE_DYNCREATE(CMy0414MFC3View)

// ����
public:
	CMy0414MFC3Doc* GetDocument() const;
	CString fname;
	MyDlg2 *dlg;
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
	virtual ~CMy0414MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowfilename();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0414MFC3View.cpp �еĵ��԰汾
inline CMy0414MFC3Doc* CMy0414MFC3View::GetDocument() const
   { return reinterpret_cast<CMy0414MFC3Doc*>(m_pDocument); }
#endif

