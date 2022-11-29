/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.*/

#include "AbstractSolution.h"

class p1 : public AbstractSolution {
private:
	static const int _MAX_ = 999;
	int multiples(int multiplier);
public:
	virtual void solve();
};