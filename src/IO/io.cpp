#include <iostream>

using namespace std;

int readFile(string namaFile){
    FILE *file = fopen("contoh.txt", "r"); // Ganti "contoh.txt" dengan nama file yang ingin Anda baca

    if (!file) {
        std::cerr << "Gagal membuka file." << std::endl;
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        std::cout << line;
    }

    fclose(file);

    return 0;
}