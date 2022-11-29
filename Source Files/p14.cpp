#include "../Header Files/p14.h"

int p14::seqlen(long long x) {
	int count = 1;
	while (x != 1) {
		auto itr = cache.find(x);
		if (itr == cache.end()) {
			double f = log2(x);
			if (f - (int)f == 0) return count + (int)f;
			
			x = (x % 2 == 0) ? x >> 1 : 3 * x + 1;
			++count;
		}
		else return count + (*itr).second;
	}
	return count;
}

void p14::solve()
{
	/*
	* Optimizations:
	* - If we calculate the length of n then the second n occurs in another sequence we can just add onto it and cache it.
	* - If we don't find that and we find a power of two we can just add onto the seq length log2(of that value)
	*/
	using namespace std;

	int max_i = 0, max_len = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		int len = seqlen(i);
		cache.insert(make_pair(i, len));
		cout << i << endl;
		if (len > max_len) {
			max_len = len;
			max_i = i;
		}
	}

	cout << max_i << endl;
}
