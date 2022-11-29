#include "../Header Files/p16.h"

using namespace std;

void _vdouble(vector<uint8_t>& v, int exponent) {
	int carry = 0;
	int i = 0;
	const int max = (int)(0.30102999566 * exponent + 1); //num digits (log10(2^x) + 1 = (x * log10(2) + 1)

	for (; i < max; i++) {
		int sum = carry + v[i] * 2;
		v[i] = sum % 10;
		carry = sum / 10;
	}

	while (carry > 0) {
		v[i] = carry % 10;
		carry /= 10;
	}
}


void p16::solve() {
	//2^1000

	vector<uint8_t> digits(1000);
	digits[0] = 1;


	for (int i = 1; i <= 1000; i++) {
		_vdouble(digits, i);
	}
	
	int sum = 0;
	for_each(digits.begin(), digits.end(), [&](int n) {
		sum += n;
		});

	cout << sum;
}