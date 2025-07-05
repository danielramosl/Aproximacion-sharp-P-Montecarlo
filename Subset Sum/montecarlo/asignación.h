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

    struct dato {
        bool sim;
        int var;
    };

    std::vector<bool> asignaciónAleatoria(int n) {
        std::vector<bool> arr(n);
        std::uniform_int_distribution<int> distribución(0, 1);
        for(int i = 0; i < n; ++i) {
            arr[i] = distribución(gen);
        }
        if(std::count(arr.begin(), arr.end(), 0) == n) {
            arr = asignaciónAleatoria(n);
        }
        return arr;
    }

    bool verificarAsignación(const std::vector<int> &arr, const std::vector<bool> &asignación) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i] * asignación[i];
        }
        return sum == 0;
    }
};