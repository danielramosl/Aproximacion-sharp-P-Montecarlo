#include "montecarlo.h"
#include "ops128.h"
#include <iostream>
#include <stdfloat>

int main() {
    int n;
    scanf("%d", &n);
    std::float128_t e = 0.001, z = 2.575;
    monteCarlo mc(z, e, n);
    monteCarlo::resultado res = mc.intervalo();
    std::cout << f128to_string(res.media) << "\n"
        << "[" << f128to_string(res.intervalo.first) << ", " 
        << f128to_string(res.intervalo.second) << "]\n";
    return 0;
}