#include "../Header Files/p1.h"

/*3*(1+2+...+333)
	3*(n*(n+1)/2), where n = (int)(_MAX_/multiplier)*/

int p1::multiples(int multiplier)
{
	return multiplier * (((int)(p1::_MAX_ / multiplier)) * (((int)(p1::_MAX_ / multiplier)) + 1)) / 2;
}

void p1::solve()
{
	std::cout << "ans: " << multiples(5) << std::endl;
}