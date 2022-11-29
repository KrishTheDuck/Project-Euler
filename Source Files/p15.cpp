
#include "../Header Files/p15.h"

void p15::solve() {
	//combinatorics:
	//once place 1 is chosen, the next places are limited:
	/*
	* 
	* for a 3x3:  _ _ _ _ _ _ 
	* 
	* RDRDRD
	* RRDDRD
	* RRRDDD
	* 
	* We must pick R such that the number of Rs in the path is N. 
	* Once we do that, the rest are filled in with Ds.
	* 
	* So, given places P, how many places can we put R.
	* Beacause there are 2N Ps and N Rs, What is 2n choose n
	*/

	const int N = 20;
	
	
	/*
	* 
	*  2N!				(2N)(2N-1)(2N-2)(2N-3)...					2^N * N! * (2N-1)(2N-3)(2N-5)....			2^N * (2N-1)(2N-3)(2N-5)....
	* ------  = ----------------------------------------- = -------------------------------------------- =	------------------------------------
	* N! * N!   (N)(N-1)(N-2)(N-3)(N-4)...(N)(N-1)(N-2)...					N! * N!											N!
	*
	* 
	* N! = N N-1 N-2 N-3 N-4 N-5
	* IF N EVEN:
	*	2^(N/2) * (N/2)!
	* IF N ODD:
	*	2^(N-1 /2) * (N-1 / 2)!
	* 
	* 
	* FOR N = 5
	* 2^5 9 7 5 3 1
	*	  5 4 3 2 1	-> 2^2 (2,1) 5 3 1
	* 
	* FOR N = 6
	* 2^6 11 9 7 5 3 1
	*	   6 5 4 3 2 1 -> 2^3 (3,2,1) 5 3 1
	* 
	* FOR N = 7
	* 2^7 13 11 9 7 5 3 1
	*		7 6 5 4 3 2 1 -> 2^3 (3,2,1) 7 5 3 1
	* 
	* FOR N = 8
	* 2^8 15 13 11 9 7 5 3 1
	*		 8 7 6 5 4 3 2 1 -> 2^4 (4,3,2,1) 7 5 3 1
	* 
	* FOR N = 20
	* 2^20 39 37 35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 
	*		   20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1	-> 2^10 * (10,9,8,7,6,5,4,3,2,1)
	* SO NUMERATOR GOES FROM 2N-1 TO N (-1 IF EVEN)
	*/

	const int min = (N % 2 == 0) ? N - 1 : N;

	long long ans = 1;
	std::vector<long> divide;

	for (int i = 2 * N - 1, k = 0; i > min; i -= 2, k++) {
		ans *= i;
	}

	ans *= 1 << (N - (int)(N / 2));
	
	for (int i = 0; i < (int)N/2; i++) {
		ans = ans/(i + 1);
	}
	
	std::cout << ans;
}