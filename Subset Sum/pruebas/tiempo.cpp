#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream ent("sal-malo.txt");
    std::ofstream sal("tiempo-malo.txt");
    for(int i = 0; i < 40; ++i) {
        std::string s;
        std::getline(ent, s);
        std::getline(ent, s);
        std::stringstream ss(s);
        std::string r;
        ss >> r;
        ss >> r;
        sal << r << "\n";
    }
}