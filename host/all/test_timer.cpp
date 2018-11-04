#include <iostream>

#include "timer.h"

using std::cout;
using std::flush;

int main()
{
        Timer t1;
        Timer t2;
        Timer t3;
        auto v3 = t3.get();
        auto v2 = t2.get();
        auto v1 = t1.get();
        cout << "v1: " << v1 << " v2: " << v2 << "\n";
}
