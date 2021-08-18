#pragma once
#include "AbstractSolution.h"
class p11 : public AbstractSolution{
public:
    constexpr static const int N = 20;
    virtual void solve();
    p11() {

    };
    ~p11();
private:
    void read(std::string* file);
    int** matrix = new int* [p11::N];
};

