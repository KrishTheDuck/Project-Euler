//(a1+a2+a3...+an)^2 - (a1^2+a2^2+a3^2...+an^2) = 2(a1*a2+a1*a3+a1*a4+...an-1*an)
//OR
//((n*(n+1))/2)^2 - n*(n+1)*(2n+1)/6

#include "../Header Files/p6.h"

int p6::sol1(std::vector<int>* nums) {
	int result = 0;
	for (int i = 0; i < nums->size(); i++) {
		for (int k = i + 1; k < nums->size(); k++) {
			result = result + nums->at(i) * nums->at(k);
		}
	}
	return result;
}

int p6::sol2() {
	long sum = p6::_MAX_ * (p6::_MAX_ + 1) >> 1;
	long squared = ((p6::_MAX_ * (p6::_MAX_ + 1) * (2 * p6::_MAX_ + 1)) >> 1) / 3;
	return sum * sum - squared;
}

void p6::solve() {
	std::vector<int> nums;

	for (int i = 1; i <= p6::_MAX_; i++) {
		nums.push_back(i);
	}

	unsigned long result1 = sol1(&nums); 
	unsigned long result2 = sol2();

	std::cout << "ans (through repeated addition): " << result1 << ", ans (through equations): " << result2 << std::endl;
}
