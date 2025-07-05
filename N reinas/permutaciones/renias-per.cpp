#include <algorithm>
#include <stdio.h>
#include <vector>

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

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    int contador = 0;
    do {
        contador += verificarAsignación(arr);
    } while(std::next_permutation(arr.begin(), arr.end()));
    printf("%d\n", contador);
    return 0;
}