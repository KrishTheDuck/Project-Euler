/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

#include "AbstractSolution.h"

class p5 : public AbstractSolution {
private:
	constexpr static const int _MAX_ = 20;
	void prime_gen(int, std::vector<int>*);
public:
	virtual void solve();
};