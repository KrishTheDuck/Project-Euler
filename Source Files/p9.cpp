#include "../Header Files/p9.h"
/*a2 + b2 = c2
a+b+c=1000
(a+b)2-2ab=c2
(1000-c)2-2ab=c2
1000^2-2000c-2ab=0
2000c+2ab=1000^2
1000c+ab=500*1000
c=1000-a-b
1000^2-1000a-1000b+ab=500*1000
(1000-a)(1000-b)=500*1000*/

void p9::solve(){
    const int _max_ = 500000;
    for (int a = 2; a < 500; a++) {
        if (_max_ % a != 0) continue;
        long b = 1000 - _max_ / (1000 - a);
        long c = 1000 - a - b;
        if (a * a + b * b == c * c) {            
            std::cout << "ans: " << a << ", " << b << ", " << c << std::endl;
            return;
        }
    }
}