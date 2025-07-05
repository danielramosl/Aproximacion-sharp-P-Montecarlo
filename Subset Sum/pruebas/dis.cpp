#include <fstream>
#include <string>

int main() {
    std::ifstream ent("sal-malo.txt");
    std::ofstream sal("dis.txt");
    for(int i = 0; i < 40; ++i) {
        std::string s;
        std::getline(ent, s);
        sal << s << "\n";
        std::getline(ent, s);
    }
}