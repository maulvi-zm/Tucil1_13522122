#include "io.hpp"

using namespace std;

int readFile(const string namaFile, int *bufferSize, vector<vector<string>> *matrix, vector<Sequence> *sequences) {
    FILE *file = fopen(namaFile.c_str(), "r");

    printf("Membaca file %s\n\n", namaFile.c_str());

    if (!file) {
        cerr << "Gagal membuka file." << endl;
        printf("Jika working directory saat ini adalah /bin, gunakan input \"../test/namaFile.txt\"\n\n");
        return 1;
    }

    char line[1000];

    *bufferSize = stoi(fgets(line, sizeof(line), file));

    int row, col;
    fscanf(file, "%d %d\n", &row, &col);

    for (int i = 0; i < row; i++) {
        fgets(line, sizeof(line), file);
        vector<string> temp = split(line, ' ');

        if (temp.size() != col) {
            
            cerr << "Ukuran kolom tidak konsisten." << endl;
            return 1;
        }

        for (int j = 0; j < col; j++) {
            if (temp[j].size() != 2) {
                int len = strlen(temp[j].c_str());

                if (temp[j][len - 1] == '\n' && len == 3) {
                    temp[j].erase(len - 1);
                    continue;
                }

                cerr << "Token dalam matriks harus memiliki panjang 2" << endl;
                return 1;
            }
        }

        matrix->push_back(temp);
    }

    int banyakSequence = stoi(fgets(line, sizeof(line), file));

    for (int i = 0; i < banyakSequence; i++) {

        vector<string> temp = split(fgets(line, sizeof(line), file), ' ');

        for (int j = 0; j < temp.size(); j++) {
            if (temp[j].size() != 2) {
                
                int len = strlen(temp[j].c_str());

                if (temp[j][len - 1] == '\n' && len == 3) {
                    temp[j].erase(len - 1);
                    continue;
                }

                cerr << "Token dalam sequence harus memiliki panjang 2" << endl;
                return 1;
            }
        }
        
        int value = stoi(fgets(line, sizeof(line), file));

        sequences->push_back(Sequence(temp, value));
    }

    fclose(file);

    return 0;
}
