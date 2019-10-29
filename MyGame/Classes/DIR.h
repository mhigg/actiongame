#pragma once
enum class DIR
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	CENTER,
	MAX
};

DIR begin(DIR);
DIR end(DIR);
DIR operator*(DIR id);
DIR operator++(DIR& id);