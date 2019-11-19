#include "OPRT_state.h"

OPRT_state::OPRT_state(void)
{
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)] = { false, false, false };
	}
};

void OPRT_state::Update(void)
{
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)][oldTrg] = pressFlags[static_cast<int>(dir)][nowTrg];
	}
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)][nowTrg] = pressFlags[static_cast<int>(dir)][inputTrg];
	}
}

const InputAry & OPRT_state::GetInputAry(void)
{
	return pressFlags;
}
