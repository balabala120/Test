
// 0407MFC2View.h : CMy0407MFC2View ��Ľӿ�
//

#pragma once
#include "MyDlg1.h"

class CMy0407MFC2View : public CView
{
protected: // �������л�����
	CMy0407MFC2View();
	DECLARE_DYNCREATE(CMy0407MFC2View)
	
// ����
public:
	CMy0407MFC2Doc* GetDocument() const;

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
	virtual ~CMy0407MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onpop();
	
};

#ifndef _DEBUG  // 0407MFC2View.cpp �еĵ��԰汾
inline CMy0407MFC2Doc* CMy0407MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0407MFC2Doc*>(m_pDocument); }
#endif

