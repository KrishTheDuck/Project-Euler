#include "../Header Files/p2.h"

//1 1 2 3 5 8 13 21 34 55 89 => every third num is even
//fn = fn-1+fn-2
//fn = fn2+fn3+fn3+fn4
//fn = fn3+fn4+fn3+fn3+fn4 = 3fn3+2fn4 
//fn = 3fn3 + fn4 + fn5 + fn6
//fn = 4fn3 + fn6
void p2::solve()
{
    long pair[] = { 0,2 };
    long summed = 0L;

    int i = 0;
    while (pair[i] < _MAX_) {
        summed += pair[i];
        i = (++i) % 2;
        pair[i] = 4 * pair[(i + 1) % 2] + pair[i];
    }

    std::cout << "ans: " << summed;
}