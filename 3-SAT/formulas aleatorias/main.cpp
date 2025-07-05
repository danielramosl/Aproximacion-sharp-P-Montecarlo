#include <algorithm>
#include <immintrin.h>
#include <fstream>
#include <random>

struct random_rand {
    using result_type = uint64_t;
    uint64_t operator()() {
        uint64_t res;
        while (_rdrand64_step(reinterpret_cast<unsigned long long*>(&res)) == 0) {
            continue;
        }
        return res;
    }
    static constexpr result_type min() {
        return std::numeric_limits<result_type>::min( );
    }
    static constexpr result_type max() {
        return std::numeric_limits<result_type>::max( );
    }
};

int main() {
    std::ofstream sal("ent.txt");
    random_rand rand;
    for(int u = 0; u < 35; ++u) {
        int n = u + 1, v = n * 3;
        int var[n * 3], signo[n * 3];
        for(int i = 0; i < n * 3; ++i) {
            signo[i] = rand() % 2;
            var[i] = rand() % v;
        }
        int ocurrencia[n * 3];
        std::fill(ocurrencia, ocurrencia + n * 3, -1);
        int cont = 0;
        for(int i = 0; i < n * 3; ++i) {
            if(ocurrencia[var[i]] == -1) {
                ocurrencia[var[i]] = cont++;
            }
        }
        sal << cont << " ";
        for(int i = 0; i < n * 3; ++i) {
            sal << (signo == 0 ? '+' : '!') << ocurrencia[var[i]] << " ";
        }
        sal << "\n";
    }
}