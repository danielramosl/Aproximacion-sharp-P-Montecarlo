#include <algorithm>
#include <stdio.h>

int n, veces, tab[20];
bool usadas[20];

void f(int i) {
    if(i == n) {
        for(int u = 0; u < n; ++u) {
            for(int v = 0; v < n; ++v) {
                if(tab[u] == v) {
                    printf("X ");
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
        printf("\n");
        veces += 1;
    } else {
        for(int j = 0; j < n; ++j) {
            if(usadas[j] == 0) {
                bool valida = 1;
                for(int k = 1; k <= i; ++k) {
                    if((j - k >= 0 && tab[i - k] == j - k)
                        || (j + k < n && tab[i - k] == j + k)) {
                        valida = 0;
                        break;
                    }
                }
                if(valida) {
                    usadas[j] = 1;
                    tab[i] = j;
                    f(i + 1);
                    usadas[j] = 0;
                    tab[i] = -1;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    std::fill(tab, tab + n, -1);
    f(0);
    printf("%d\n", veces);
}