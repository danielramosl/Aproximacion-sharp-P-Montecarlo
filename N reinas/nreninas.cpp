#include <stdio.h>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    int reinas[n];
    std::vector<std::vector<char>> tab(n, std::vector<char>(n, '-'));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &reinas[i]);
        tab[i][reinas[i]] = 'X';
    }
    bool bandera = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            if((i + j < n && reinas[i] + j < n && tab[i + j][reinas[i] + j] == 'X') || 
                (i + j < n && reinas[i] - j >= 0 && tab[i + j][reinas[i] - j] == 'X') || 
                (i - j >= 0 && reinas[i] + j < n && tab[i - j][reinas[i] + j] == 'X') || 
                (i - j >= 0 && reinas[i] - j >= 0 && tab[i - j][reinas[i] - j] == 'X')) {
                    bandera = false;
                    break;
            }
        }
        if(!bandera) {
            break;
        }
    }

    printf("\n%d\n", bandera);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}