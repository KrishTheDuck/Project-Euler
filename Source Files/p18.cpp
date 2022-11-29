#include "../Header Files/p18.h"


void p18::solve() {
	int N1 = N;
	for (int i = N1 - 2; i > 0; i--) {
		//unravel my a + max(a-1, a+1);
		for (int j = 0; j < N1-1; j++) {
			arr[i][j] += __max(arr[i + 1][j], arr[i + 1][j + 1]);
			arr[i + 1][j] = 0;
		}
		N1--;
	}

	std::cout << arr[0][0] + __max(arr[1][0], arr[1][1]);
}