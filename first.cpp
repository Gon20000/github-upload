#include "timer.h"
#include "random.h"
#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    std::array<int, 10000> x{};
    for(std::size_t i{ 0 }; i < 10000; ++i) {
        x[i] = Random::get(1, 1000);
    }
    
    Timer timer{};
    std::sort(x.begin(), x.end());
    std::cout << timer.elapsed() << '\n';
    timer.reset();

    return 0;
}