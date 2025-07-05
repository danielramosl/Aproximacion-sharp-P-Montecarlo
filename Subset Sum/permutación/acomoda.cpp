#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream ent("sal.txt");
    std::ofstream exacto("exacto.txt"), tiempo("tiempo.txt");

    // Configurar salida en formato fijo si quieres evitar notación científica
    tiempo << std::fixed << std::setprecision(6);

    for (int i = 0; i < 50; ++i) {
        std::string lineaValor;
        std::getline(ent, lineaValor);

        long long valor = std::stoll(lineaValor); // Convertir la primera línea a long long

        std::string lineaTiempo;
        std::getline(ent, lineaTiempo);

        double t = std::stod(lineaTiempo.substr(lineaTiempo.find(":") + 1));

        exacto << valor << "\n";
        tiempo << t << "\n";
    }
}