#include "../Header Files/p30.h"

#define __pow5(a) a*a*a*a*a;

void p30::solve() {
	//10000
	//99999
	int i = 10000;
	int csums = 0;
	while (i <= 99999) {
		int p = i;
		int sum = 0;
		std::cout << i << " ";

		while (p > 0) {
			int c = p % 10;
			p /= 10;
			if (c == 1) continue;
			sum += __pow5(c);
		}

		std::cout << sum << std::endl;

		csums += (sum == i) ? i : 0;
		i++;
	}
	
	std::cout << csums;
}