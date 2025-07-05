#include <fstream>
#include <random>

int main() {
    std::ofstream sal("ent.txt");
    std::mt19937 mt(time(nullptr));
    for(int n = 1; n <= 50; ++n) {
        sal << n << "\n";
        for(int i = 0; i < n; ++i) {
            int p = mt() % (n * n); bool signo = mt() % 2;
            sal << p * ((signo == 1) ? 1 : -1) << " ";
        }
        sal << "\n";
    }
}