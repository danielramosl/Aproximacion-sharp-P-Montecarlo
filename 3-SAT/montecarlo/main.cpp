#include "asignación.h"
#include "estadística.h"
#include <fstream>
#include <iostream>
#include "montecarlo.h"
#include <time.h>

int main() {
    for(int u = 0; u < 25; ++u) {
        std::ofstream media("media.txt", std::ios::app), inter("intervalo.txt", std::ios::app), tiempo("tiempo.txt", std::ios::app);
        int n = u + 1, v;
        std::cin >> v;
        std::vector<std::vector<asignación::dato>> función(n, std::vector<asignación::dato>(3));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 3; ++j) {
                char sim; int var;
                std::cin >> sim >> var;
                función[i][j] = asignación::dato{sim == '+', var};
            }
        }
        std::float128_t e = 0.01, z = 2.575;
        monteCarlo mc(z, e, v, función);
        clock_t t0 = clock();
        monteCarlo::resultado res = mc.intervalo();
        clock_t t1 = clock();
        media << f128to_string(res.media) << "\n";
        inter << f128to_string(res.intervalo.first) << " "
            << f128to_string(res.intervalo.second) << "\n";
        tiempo << double(t1 - t0) / CLOCKS_PER_SEC << "\n";
        std::cout << u << " :)\n";
    }
}