#include <iostream>
#include <fstream>
#include "montecarlo.h"
#include "ops128.h"

int main() {
    for(int u = 0; u < 50; ++u) {
        std::ofstream media("media.txt", std::ios::app), inter("intervalo.txt", std::ios::app), tiempo("tiempo.txt", std::ios::app);
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        std::float128_t e = 0.01, z = 2.575;
        monteCarlo mc(z, e, arr);
        clock_t t0 = clock();
        monteCarlo::resultado res = mc.intervalo();
        clock_t t1 = clock();
        media << f128to_string(res.media) << "\n";
            inter << f128to_string(res.intervalo.first) << " "
                << f128to_string(res.intervalo.second) << "\n";
            tiempo << double(t1 - t0) / CLOCKS_PER_SEC << "\n";
            std::cout << u << " :)\n";
    }
    return 0;
}