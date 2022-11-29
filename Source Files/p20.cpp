#include "../Header Files/p20.h"
using namespace std;

typedef vector<uint8_t> bnum;

void mult(bnum& d, int m) {
	vector<bnum> s((int)(log10(m) + 1));

	int j = 0;
	while (m > 0) {
		const int lsd = m % 10;
		int carry = 0;
		for (int i = 0; i < d.size(); i++) {
			int mult = d[i] * lsd + carry;
			s[j][i + j] = mult % 10;
			carry = mult / 10;
		}

		j++;
		m /= 10;
	}

	
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s[i].size(); j++) {
			sum += s[j][i];
		}
		d[i] = sum % 10;
		sum /= 10;
	}
}

void p20::s() {
	bnum digits = {1,2,3,4};
	mult(digits, 1234);

	for (int i : digits) {
		std::cout << i;
	}

}