#include "../Header Files/p4.h"

int p4::palindromify(int i)
{
    int reverse = 0;
    int x = i;
    while (x > 0) {
        reverse = 10 * reverse + x % 10;
        x /= 10;
        i *= 10;
    }
    return reverse + i;
}

void p4::solve() {
    int start = 999;

    struct {
        int f1, f2;
    } ans = { 0, 0 };

    while (start-- > 100) {
        int i = palindromify(start);
        for (int k = 999; k >= (int)std::sqrt(i); k--) {
            if (i % k == 0) {
                int f1 = i / k;
                if (ans.f1 + ans.f2 < k + f1) {
                    ans.f1 = f1;
                    ans.f2 = k;
                    break;
                }
            }
        }
    }
    std::cout << "ans: " << ans.f1 << " " << ans.f2 << std::endl;
}