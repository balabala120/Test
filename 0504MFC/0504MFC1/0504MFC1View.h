
// 0504MFC1View.h : CMy0504MFC1View ��Ľӿ�
//

#pragma once


class CMy0504MFC1View : public CView
{
protected: // �������л�����
	CMy0504MFC1View();
	DECLARE_DYNCREATE(CMy0504MFC1View)

// ����
public:
	CMy0504MFC1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy0504MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0504MFC1View.cpp �еĵ��԰汾
inline CMy0504MFC1Doc* CMy0504MFC1View::GetDocument() const
   { return reinterpret_cast<CMy0504MFC1Doc*>(m_pDocument); }
#endif

