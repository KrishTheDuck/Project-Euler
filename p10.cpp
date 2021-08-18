#include "p10.h"

void p10::sieve()
{
    /*We only need to calculate up to the square root of the upper bound.
    * If we go to the next prime over sqrt(max) then we would go over the bound
    * crossing out numbers for the sieve.*/
    const int sqrtn = (int)std::sqrt(p10::n) >> 1; /*divide by two as we already eliminate evens*/
    p10::prime[0] = 1; /*1 is not a prime*/
    for (int i = 1; i <= sqrtn; i++) { /*iterate until the sqrt*/
        if (!p10::prime->test(i)) { /*Test whether the current num has been crossed out*/
            /*If we take some prime p we can assume that p*(q), where q is the next lowest 
            * was already crossed out in the qth step. Therefore, the first num we need to cross
            * out is p*p. As 'i' indexes odd values we know the actual value of the prime is 2*i+1.
            * We need to find the square in the array. If index 'i' indexes some odd o at 2*i+1,
            * then (o-1)/2 is the location of that odd. As the o in question is the square of prime p,
            * we can see that (p*p-1)/2 is the location of o. ((2*i+1)^2 - 1)/2 = 2*i*i + 2*i or 2*i*(i+1).
            * 
            * To find the next value to jump to we add on that prime's value.
            */
            for (int j = 2*i*(i+1); j < p10::n_2; j += 2*i+1) {  
                p10::prime->set(j, true); /*indicate composite*/
            }
        }
    }
}

void p10::solve()
{
    p10::sieve();
    long long sum = 2;
    for (long long i = 1; i < p10:: n_2; i++) {
        if (!p10::prime->test(i)) {
            sum += 2*i + 1; /*the bitset indexes odd values*/
        }
    }
    std::cout << "ans: " << sum << std::endl;
}

p10::~p10()
{
    delete p10::prime;
}
