#include "Data-Structure/data-structure.hpp"
#include "IO/io.hpp"
#include "Utils/utils.hpp"
#include "Solver/solver.hpp"

using namespace std;

int main(){
    cout << "Selamat datang di Cyberpunk 2077 Breach Protocol Solver!\n" << endl;
    
    int pilihan;
    int bufferSize;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    BreachProtocolSolver solver(0, {{}}, {});
    string namaFile;

    int jumlahToken, row, col, jumlahSequence, maksPanjangSequence;
    string token_string;
    vector<string> token;

    do {
        matrix.clear();
        sequences.clear();
        token.clear();
        solver = BreachProtocolSolver(0, {{}}, {});

        cout << "Masukkan tipe input:" << endl;
        cout << "1. Input dari file" << endl;
        cout << "2. Input dari keyboard" << endl;
        cout << "0. Keluar\n" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        printf("\n");

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama file: ";
            // cin >> namaFile;
            namaFile = "../test/test-1.txt";
            
            while (readFile(namaFile, &bufferSize, &matrix, &sequences) == 1) {
                cout << "Masukkan nama file: ";
                cin >> namaFile;
            } 
            solver = BreachProtocolSolver(bufferSize, matrix, sequences);

            displayInput(bufferSize, matrix, sequences);

            solver.Solve();
        
            break;

        case 2:
            cin >> jumlahToken;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getline(cin, token_string, '\n');

            token = split(token_string, ' ');

            if (token.size() != jumlahToken) {
                cerr << "Jumlah token tidak sesuai" << endl;
                continue;
            }

            for (const string& s : token) {
                if (s.size() != 2) {
                    cerr << "Token harus memiliki panjang 2" << endl;
                    continue;
                }
            }

            cin >> bufferSize;
            cin >> row >> col;

            makeMatrixFromToken(row, col, token, &matrix);

            cin >> jumlahSequence;
            cin >> maksPanjangSequence;

            makeSequenceFromToken(jumlahSequence, maksPanjangSequence, token, &sequences);

            solver = BreachProtocolSolver(bufferSize, matrix, sequences);

            displayInput(bufferSize, matrix, sequences);
        
        case 0:
            break;
        default:
            cout << "Pilihan tidak valid\n" << endl;
            break;
    }
    } while ( pilihan != 0);

    return 0;
}