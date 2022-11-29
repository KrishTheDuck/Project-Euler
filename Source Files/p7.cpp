#include "../Header Files/p7.h"

bool p7::isPrime(int i) {
    if (i % 2 == 0) return false;

    int j = 3;
    while (j * j <= i) {
        if (i % j == 0) return false;
        j += 2;
    }
    return true;
}

void p7::solve()
{
    int n_primes = 1;
    int n = 1;

    while (n_primes < 10001) {
        n += 2;
        if (isPrime(n))
            ++n_primes;
    }
    
    std::cout << "ans: " << n << std::endl;
}