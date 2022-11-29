//2520 -> 2*3*2*5*7*2*3 = 2^3 * 3^2 * 5^1 * 7^1.
//by euler product formula:
//N = p0^a0 + p1^a1 + p2^a2 ...
//a is an exponent such that pi ^ ai <= k, where k is the maximum number of divisors 
//if a exceeds this value it means there is an extra
//thus a must be floor(log(k)/log(pi))
//we first generate primes

#include "../Header Files/p5.h"

void p5::prime_gen(int max, std::vector<int>* primes) {
    primes->clear();
    primes->push_back(2);
    for (int i = 3; i < max; i += 2) {
        bool isPrime = true;
        for (int k = 2; k <= (int)std::sqrt(i); k++) {
            if (i % k == 0) isPrime = false;
        }
        if (isPrime) {
            primes->push_back(i);
        }
    }
}
void p5::solve()
{
    std::vector<int> primes;
    prime_gen(p5::_MAX_, &primes);

    long long result = 1;
    for (auto i = primes.begin(); i != primes.end(); i++) {
        int a = (int)(std::log(p5::_MAX_) / std::log(*i));
        result = result * (int)std::pow(*i, a);
    }
    std::cout << "ans: " << result << std::endl;
}
