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

    std::vector<bool> asignaciónAleatoria(int v) {
        std::vector<bool> arr(v);
        std::uniform_int_distribution<int> distribución(0, 1);
        for(int i = 0; i < v; ++i) {
            arr[i] = distribución(gen);
        }
        return arr;
    }

    bool verificarAsignación(const std::vector<std::vector<dato>> &función, const std::vector<bool> &asignación) {
        int n = función.size();
        for(int i = 0; i < n; ++i) {
            bool var[3];
            for(int j = 0; j < 3; ++j) {
                var[j] = asignación[función[i][j].var];
                if(función[i][j].sim == false) {
                    var[j] = !var[j];
                }
            }
            if(!(var[0] || var[1] || var[2])) {
                return false;
            }
        }
        return true;
    }
};