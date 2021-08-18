#pragma once
#include "AbstractSolution.h"
class p10 : public AbstractSolution{
public:
    constexpr static const int n = 2000000;
    constexpr static const int n_2 = n >> 1;
    virtual void solve();
    ~p10();
    p10() {
    };
private:
    void sieve();
    std::bitset<n_2>* prime = new std::bitset<n_2>();
};
