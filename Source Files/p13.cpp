#include "../Header Files/p13.h"

void p13::solve()
{
	//lets not cheat and actually parse through the problem

	int* sum = new int[50];
	int carry = 0;
	//itr through leftmost digit first, and carry
	
	for (int i = 49; i >= 0; i--) {
		int s1 = carry;
		//itr through each number
		for (int j = 0; j < 100; j++) {
			s1 += (int)((int)lines[j][i] - 48);
		}
		carry = (int)(s1 / 10);
		sum[i] = (s1 % 10);
	}

	//print carry because that needs to exist
	std::cout << carry;
	//print the rest of the number minus how long the carry is for 10 digits
	for (int i = 0; i < 10 - (int)(log10(carry)+1); i++) {
		std::cout << *(sum + i);
	}
	delete[] sum;
}
