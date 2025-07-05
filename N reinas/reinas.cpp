#include <stdio.h>

bool reina(int tab[], int n) {
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

int main() {
    int n;
    scanf("%d", &n);
    int tab[n];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &tab[i]);
    }
    printf("%d", reina(tab, n));
}