/*If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include "AbstractSolution.h"

class p17 : AbstractSolution {
private:
	size_t ones[10] = { 0, 3 , 3, 5, 4, 4, 3, 5, 5, 4};
	size_t teens[10] = { 3, 7, 7, 9, 9, 7, 7, 10, 9, 9};
	size_t tens[10] = { 0, 3, 7, 7, 7, 6, 6, 8, 7, 7 }; //0 - ninety
public:
	virtual void solve();
};

