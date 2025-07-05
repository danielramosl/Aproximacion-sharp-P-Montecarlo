#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100], n, cont;

int f(int i, int suma) {
    if(i == n) {
        return suma == 0;
    } else {
        return f(i + 1, suma + arr[i]) + f(i + 1, suma);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    clock_t t0 = clock();
    int res = f(0, 0);
    clock_t t1 = clock();
    printf("%d\nTiempo: %lf", cont, double(t1 - t0) / CLOCKS_PER_SEC);
    return 0;
}