#include "utils.hpp"
#include <iostream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void displayInput(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences) {
    cout << "Buffer Size: " << bufferSize << endl;
    cout << "Matrix: " << endl;
    for (const auto& row : matrix) {
        for (const auto& col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "Sequences: " << endl;
    for (const auto& sequence : sequences) {
        for (const auto& data : sequence.data) {
            cout << data << " ";
        }
        cout << "Value: " << sequence.value << endl;
    }
}

void makeMatrixFromToken(int row, int col, const vector<string>& token, vector<vector<string>>* matrix) {
    for (int i = 0; i < row; i++) {
        vector<string> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(token[rand() % token.size()]);
        }
        matrix->push_back(temp);
    }
}

void makeSequenceFromToken(int jumlahSequence, int maksPanjangSequence, const vector<string>& token, vector<Sequence> *sequences){
    for (int i = 0; i < jumlahSequence; i++) {

        int panjang = rand() % maksPanjangSequence + 1;

        vector<string> temp;
        for (int j = 0; j < panjang; j++) {
            temp.push_back(token[rand() % token.size()]);
        }
        sequences->push_back(Sequence(temp, (rand() % 10 + 1) * 10));
    }
}
