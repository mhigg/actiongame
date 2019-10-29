#pragma once
#ifdef _DEBUG
#include <Windows.h>
#include <memory>

#define TRACE(fmt, ...) printf(fmt, __VA_ARGS__)
#define AST() {\
		CHAR ast_mes[256];\
		wsprintf( ast_mes, "%s %d行目\0", __FILE__, __LINE__ );\
		MessageBox( 0, ast_mes, "ｱｻｰﾄ表示", MB_OK );\
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
			// ここに後始末処理を書ける

			delete _debugConOut;	// ﾃﾞｽﾄﾗｸﾀの呼び出し、削除
		}
	};

	_DebugConOut();
	~_DebugConOut();

	FILE* _debugFp = nullptr;		// ﾃﾞﾊﾞｯｸﾞﾌｧｲﾙのﾎﾟｲﾝﾀ
	static std::unique_ptr<_DebugConOut, _DebugConOutDeleter> s_instance;
};
#else
#define TRACE(fmt, ...)		// Releaseでは中身が定義されない
#define AST()
#endif	// _DEBUG