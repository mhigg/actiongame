#ifdef _DEBUG
#include <Windows.h>
#include "_DebugConOut.h"

std::unique_ptr < _DebugConOut, _DebugConOut::_DebugConOutDeleter > _DebugConOut::s_instance(new _DebugConOut());	// ｽﾏｰﾄﾎﾟｲﾝﾀと一緒にその場で作る

_DebugConOut::_DebugConOut()
{
//	HWND hWnd = GetForegroundWindow();	// 今表示されているｳｨﾝﾄﾞｳﾊﾝﾄﾞﾙ
	AllocConsole();						// ｺﾝｿｰﾙの表示
	freopen_s(&_debugFp, "CONOUT$", "w", stdout);	// 出力
	freopen_s(&_debugFp, "CONIN$",  "r", stdin);	// 入力
//	SetForegroundWindow(hWnd);			// 取得したｳｨﾝﾄﾞｳﾊﾝﾄﾞﾙを前に出す
}


_DebugConOut::~_DebugConOut()
{
	FreeConsole();		// 
}

#endif	// _DEBUG