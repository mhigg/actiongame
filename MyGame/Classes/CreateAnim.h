#pragma once
#include <string>

struct CreateAnim
{
	// Create Animation
	// @param spName  Sprite name
	// @param act  Sprite action
	// @param num  Action frames
	void operator()(const std::string& type, const std::string& spName, const std::string& act, const int num);
};

