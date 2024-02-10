#include "io.hpp"

using namespace std;

int readFile(const string& namaFile){
    FILE *file = fopen(namaFile.c_str(), "r"); // Ganti "contoh.txt" dengan nama file yang ingin Anda baca

    printf("Membaca file %s\n", namaFile.c_str());

    if (!file) {
        cerr << "Gagal membuka file." << endl;
        return 1;
    }

    char line[1000];

    int bufferSize = stoi(fgets(line, sizeof(line), file));

    printf("Ukuran buffer: %d\n", bufferSize);

    fclose(file);

    return 0;
}