#pragma once
#include <algorithm>
#include <immintrin.h>
#include <limits>
#include <random>
#include <vector>

class asignación {
    private:
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

    random_rand gen;

    public:
    std::vector<int> asignaciónAleatoria(int n) {
        std::vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        std::shuffle(arr.begin(), arr.end(), gen);
        return arr;
    }

    bool verificarAsignación(const std::vector<int>& tab) {
        int n = tab.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < n; ++j) {
                if((i + j < n && tab[i] + j < n && tab[i + j] == tab[i] + j) || 
                (i + j < n && tab[i] - j >= 0 && tab[i + j] == tab[i] - j) || 
                (i - j >= 0 && tab[i] + j < n && tab[i - j] == tab[i] + j) || 
                (i - j >= 0 && tab[i] - j >= 0 && tab[i - j] == tab[i] - j)) {
                    return false;
                }
            }
        }
        return true;
    }
};