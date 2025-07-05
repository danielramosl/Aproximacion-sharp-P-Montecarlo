#include <algorithm>
#include <iostream>
#include <map>
#include <set>

std::string i128to_string(__uint128_t n) {
    if (n == 0) return "0";
    std::string res;
    while (n > 0) {
        res.push_back('0' + (n % 10));
        n /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int n;
int arr[100];
std::map<std::pair<int, int>, __int128_t> memoria;

__int128_t f(int i, int s) {
   if(memoria.find({i, s}) == memoria.end()) {
      if(i == n) {
         memoria[{i, s}] = (s == 0);
      } else {
         memoria[{i, s}] = f(i + 1, s) + f(i + 1, s + arr[i]);
      }
   }
   return memoria[{i, s}];
}

int main() {
   for(int u = 0; u < 50; ++u) {
      memoria.clear();
      std::cin >> n;
      for(int i = 0; i < n; ++i) {
         std::cin >> arr[i];
      }
      clock_t t0 = clock();
      __int128_t res = f(0, 0) - 1;
      clock_t t1 = clock();
      std::cout << i128to_string(res) << "\nTiempo: " << double(t1 - t0) / CLOCKS_PER_SEC << "\n";
   }
   return 0;
}