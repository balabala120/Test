// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� WIN32DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// WIN32DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef WIN32DLL_EXPORTS
#define WIN32DLL_API __declspec(dllexport)
#else
#define WIN32DLL_API __declspec(dllimport)
#endif

// �����Ǵ� Win32Dll.dll ������
class WIN32DLL_API CWin32Dll {
public:
	CWin32Dll(void);
	// TODO:  �ڴ�������ķ�����
};

class WIN32DLL_API FAC {
public:
	float convert(float deg);
};


extern WIN32DLL_API int nWin32Dll;

WIN32DLL_API int fnWin32Dll(void);

WIN32DLL_API int fac(int n);
