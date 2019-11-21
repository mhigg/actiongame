#ifdef _DEBUG
#include <Windows.h>
#include "_DebugConOut.h"

std::unique_ptr < _DebugConOut, _DebugConOut::_DebugConOutDeleter > _DebugConOut::s_instance(new _DebugConOut());	// �ϰ��߲���ƈꏏ�ɂ��̏�ō��

_DebugConOut::_DebugConOut()
{
//	HWND hWnd = GetForegroundWindow();	// ���\������Ă��鳨��޳�����
	AllocConsole();						// �ݿ�ق̕\��
	freopen_s(&_debugFp, "CONOUT$", "w", stdout);	// �o��
	freopen_s(&_debugFp, "CONIN$",  "r", stdin);	// ����
//	SetForegroundWindow(hWnd);			// �擾��������޳����ق�O�ɏo��
}


_DebugConOut::~_DebugConOut()
{
	FreeConsole();		// 
}

#endif	// _DEBUG