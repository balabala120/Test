
// 0324MFC2View.h : CMy0324MFC2View ��Ľӿ�
//

#pragma once


class CMy0324MFC2View : public CView
{
protected: // �������л�����
	CMy0324MFC2View();
	DECLARE_DYNCREATE(CMy0324MFC2View)

// ����
public:
	CMy0324MFC2Doc* GetDocument() const;
	CBitmap bitmap1_car;//λͼ����
	int bitmap1_width;//�洢λͼ������ݳ�Ա
	int bitmap1_height;
	

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
	virtual ~CMy0324MFC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0324MFC2View.cpp �еĵ��԰汾
inline CMy0324MFC2Doc* CMy0324MFC2View::GetDocument() const
   { return reinterpret_cast<CMy0324MFC2Doc*>(m_pDocument); }
#endif

