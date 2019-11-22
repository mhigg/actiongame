#pragma once
#include <string>

struct CreateAnim
{
	// Create Animation
	// @param spName  Sprite name
	// @param act  Sprite action
	// @param num  Animation frames
	void operator()(AnimData& animData);
};

