#include "p3.h"

void p3::solve()
{
    uint64_t result = 600851475143L;
    long i = 2;

    while (i++ < (int)std::sqrt(result)) {
        while (result % i == 0) {
            result = result / i;
        }
    }

    std::cout << "ans: " << result << std::endl;
}