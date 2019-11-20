#include "OPRT_state.h"

OPRT_state::OPRT_state(void)
{
	for (auto inputID : INPUT_ID())
	{
		_pressFlags[static_cast<int>(inputID)] = { false, false, false };
	}
};

void OPRT_state::Update(void)
{
	for (auto inputID : INPUT_ID())
	{
		_pressFlags[static_cast<int>(inputID)][oldTrg] = _pressFlags[static_cast<int>(inputID)][nowTrg];
	}
	for (auto inputID : INPUT_ID())
	{
		_pressFlags[static_cast<int>(inputID)][nowTrg] = _pressFlags[static_cast<int>(inputID)][inputTrg];
	}
}

const InputAry & OPRT_state::GetInputAry(void)
{
	return _pressFlags;
}
