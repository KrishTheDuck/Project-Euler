#include "../Header Files/p10.h"

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
            * out is p*p. 
            *
            * After crossing out p*p, we have to cross out the next multiple. This is accomplished by crossing out p*(p+1)
            * or p*p + p.
            * 
            * First we find p*p. index 'i' indexes odd numbers, such that 2*i + 1, is the value of that odd number.
            *       Let p*p = o.
            * If 2*i+1 is the value of the number at index i, then 
            *       2*i+1 = o.
            * Then,
            *       (o-1)/2 = i
            * We know that o = p*p, so
            *       (p*p-1)/2 = i
            * 
            * We also know that prime p is given by another index, say 'k'. So, 
            *        p = 2*k + 1
            * Plugging in,
            *        ((2*k+1)^2-1)/2 = i    
            *   <=>  (4k^2+4k+1-1)/2 = i
            *   <=>  2k^2+2k = i        
            *   <=>  2k(k+1) = i
            * 
            * So given the location of prime p at index k, the location of p*p is 2k(k+1).
            * 
            * Now what about p*p + p? Or the other multiples of p?
            * 
            * Well, if p*p is at 2k(k+1), and p is at 2k+1, then p*p+p has to be at 2k(k+1) + (2k+1)
            * And because the next multiple is found by adding p again, we can add another (2k+1) to find the 
            * next multiple.
            *
            * How far do we count to?
            * Well, if we have n number of values in our array, we need to cross off every number before that index.
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
