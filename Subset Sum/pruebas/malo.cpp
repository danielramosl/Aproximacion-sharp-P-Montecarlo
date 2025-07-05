#include <iostream>
#include <time.h>

long long arr[100], n, cont;

void f(long long i, long long suma, long long asignado) {
    if(i == n && suma == 0 && asignado > 0) {
        cont += 1;
    } else {
        f(i + 1, suma + arr[i], asignado + 1);
        f(i + 1, suma, asignado);
    }
}

int main() {
    for(long long u = 0; u < 40; ++u) {
        cont = 0;
        std::cin >> n;
        for(long long i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        clock_t t0 = clock();
        f(0, 0, 0);
        clock_t t1 = clock();
        std::cout << cont << "\nTiempo: " << double(t1 - t0) / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}