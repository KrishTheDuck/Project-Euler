#include "../Header Files/p17.h"

void p17::solve() {
	size_t sum = 0;
	
	int arr[4] = { 0,0,0,0 };
	
	for (int i = 1; i <= 1000; i++) {
		std::cout << i << " ";

		//convert to char array
		int p = i;
		for (int j = 3; j >= 0; j--) {
			arr[j] = p % 10;
			p /= 10;
		}

		for (int k = 0; k < 4; k++) {
			std::cout << arr[k];
		}
		std::cout << " ";
		//start parsing
		if (arr[0] != 0) { //thousands
			sum += ones[arr[0]];
			sum += 9; //"thousand" length
		}

		if (arr[1] != 0) { //hundreds
			sum += ones[arr[1]];
			sum += 7; //"hundred" length
			sum += 3; //and
		}
		
		switch (arr[2]) {

		case 0: {
			sum += ones[arr[3]];
			break;
		}
		case 1: {
			sum += teens[arr[3]];
			break;
		}
		default: {
			sum += tens[arr[3]];
			if (arr[3] != 0) sum += ones[arr[3]];
		}
		}
		std::cout << sum << std::endl;

	}
}