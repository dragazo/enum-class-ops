#include <iostream>

#include "enumclassops.h"

enum class flags
{
	neutral = 0,
	good = 1,
	evil = 2,
	lawful = 4,
	chaotic = 8,
};

ENUM_CLASS_DECL_BITWISE(flags)

int main()
{
	constexpr flags flags_union = flags::neutral | flags::good | flags::evil | flags::lawful | flags::chaotic;

	constexpr flags f0 = ~flags::lawful & flags_union;

	constexpr flags f1 = flags::good & flags::evil;
	constexpr flags f2 = flags::evil | flags::neutral;
	constexpr flags f3 = flags::lawful ^ flags::chaotic;

	flags f4 = flags::chaotic;
	flags f5 = flags::neutral;
	flags f6 = flags::evil;

	f4 &= flags::neutral;
	f5 |= flags::good | flags::evil;
	f6 ^= flags::evil | flags::chaotic;

	bool t1 = f4 == flags::neutral;
	bool t2 = f3 != flags::chaotic;
	bool t3 = f5 < flags::lawful;
	bool t4 = f5 >= flags::good;

	return 0;
}