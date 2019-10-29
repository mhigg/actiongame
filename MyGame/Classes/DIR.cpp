#include <type_traits>
#include "DIR.h"

DIR begin(DIR)
{
	return DIR::LEFT;
}

DIR end(DIR)
{
	return DIR::MAX;
}

DIR operator*(DIR id)
{
	return id;
}

DIR operator++(DIR & id)
{
	return id = static_cast<DIR>(std::underlying_type<DIR>::type(id) + 1);
}
