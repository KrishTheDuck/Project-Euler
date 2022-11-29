#include "../Header Files/p12.h"


int p12::num_div(int x) {
	int count = 0;
	const int max = (int)sqrt(x);

	for (int i = 2; i <= max; i++) {
		count += (x % i == 0) ? 2 : 0;
	}

	return (max * max == x) ? count - 1 : count;
}

void p12::solve() {
	int i = 1;
	int num = 0;

	while (num_div(num) < 500) {
		num += i;
		i++;
	}

	std::cout << num << std::endl;
}