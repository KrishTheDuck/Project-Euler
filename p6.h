/*The sum of the squares of the first ten natural numbers is 385.
The square of the sum of the first ten natural numbers is 3025.
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/

#include "AbstractSolution.h"

class p6 : public AbstractSolution {
private:
	constexpr static const int _MAX_ = 100;
	int sol1(std::vector<int>*);
	int sol2();
public:
	virtual void solve();
};