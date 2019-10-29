#pragma once
#ifdef _DEBUG
#include <Windows.h>
#include <memory>

#define TRACE(fmt, ...) printf(fmt, __VA_ARGS__)
#define AST() {\
		CHAR ast_mes[256];\
		wsprintf( ast_mes, "%s %d�s��\0", __FILE__, __LINE__ );\
		MessageBox( 0, ast_mes, "���ĕ\��", MB_OK );\
		}

class _DebugConOut
{
public:
	static _DebugConOut &GetInstance(void)
	{
		return (*s_instance);
	}

private:
	struct _DebugConOutDeleter
	{
		void operator()(_DebugConOut* _debugConOut) const
		{
			// �����Ɍ�n��������������

			delete _debugConOut;	// �޽�׸��̌Ăяo���A�폜
		}
	};

	_DebugConOut();
	~_DebugConOut();

	FILE* _debugFp = nullptr;		// ���ޯ��̧�ق��߲��
	static std::unique_ptr<_DebugConOut, _DebugConOutDeleter> s_instance;
};
#else
#define TRACE(fmt, ...)		// Release�ł͒��g����`����Ȃ�
#define AST()
#endif	// _DEBUG