#include "solver.hpp"

using namespace std;

BreachProtocolSolver::BreachProtocolSolver(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence >& sequences)
    : bufferSize(bufferSize), matrix(matrix), sequences(sequences) {
    maxScore = 0;
    maxSequnceLength = 0;
    minSequnceLength = 1000;

    for (int i = 0; i < sequences.size(); i++) {
        startOfSequences.insert(sequences[i].data[0]);
        maxScore += sequences[i].value;

        if (sequences[i].data.size() > maxSequnceLength) {
            maxSequnceLength = sequences[i].data.size();
        }

        if (sequences[i].data.size() < minSequnceLength) {
            minSequnceLength = sequences[i].data.size();
        }
    }

    for (int i = 0; i < bufferSize; i++) {
        if (i == 0) {
            sequenceString.push_back(Point(0, 0));
            continue;
        }
        sequenceString.push_back(Point(-1, -1));
    }

    matrixRow = matrix.size();
    matrixCol = matrix[0].size();

    result = {{}, 0, -1, 0};
}

void BreachProtocolSolver::HorizontalMove(int bufferPointer, int maxPointer) {
    // for (int i = 0; i < sequenceString.size(); i++) {
    //     printf("(%d, %d)", sequenceString[i].row, sequenceString[i].col);
    // }
    // printf("\n");

    if (result.score == maxScore || bufferPointer > maxPointer + 1) {
        return;
    }

    int currentRow = 0;
    if (bufferPointer == 0) {
        currentRow = 0;
    } else {
        currentRow = sequenceString[bufferPointer - 1].row;
    }

    if (bufferPointer <= bufferSize) {
        
        int tempPointer;

        if (bufferPointer < bufferSize) {
            tempPointer = bufferPointer;
        } else if (bufferPointer >= bufferSize){
            tempPointer = bufferSize - 1;
        }

        array<int, 2> temp = CheckScore(tempPointer);

        if (temp[0] > result.score || (temp[0] == result.score && (temp[1] < result.last || result.last == -1))){
            result.sequenceResult = sequenceString;
            result.score = temp[0];
            result.last = temp[1];
        }

        
        if (bufferPointer >= bufferSize || (bufferPointer >= maxSequnceLength + 1  && temp[0] == 0) || result.score == maxScore) {
            return;
        }
    } 

    for (int i = 0; i < matrixCol; i++) {
        sequenceString[bufferPointer] = Point(currentRow, i);
        
        if (bufferPointer == 1 && !CheckStartOfSequence(Point(currentRow, i)) && !CheckStartOfSequence(sequenceString[0])) {
            continue;
        }

        if (CheckPoint(Point(currentRow, i), sequenceString, bufferPointer)) {
            continue;
        }

        VerticalMove(bufferPointer + 1, maxPointer);
    }
}

void BreachProtocolSolver::VerticalMove(int bufferPointer, int maxPointer) {
    // for (int i = 0; i < sequenceString.size(); i++) {
    //     printf("(%d, %d)", sequenceString[i].row, sequenceString[i].col);
    // }
    // printf("\n");

    if (result.score == maxScore || bufferPointer > maxPointer + 1) {
        return;
    }

    int currentCol = 0;
    if (bufferPointer == 0) {
        currentCol = 0;
    } else {
        currentCol = sequenceString[bufferPointer - 1].col;
    }

    if (bufferPointer <= bufferSize) {
        int tempPointer;

        if (bufferPointer < bufferSize) {
            tempPointer = bufferPointer;
        } else if (bufferPointer >= bufferSize){
            tempPointer = bufferSize - 1;
        }

        array<int, 2> temp = CheckScore(tempPointer);

        if (temp[0] >= result.score || (temp[0] == result.score && (temp[1] < result.last || result.last == -1))){
            result.sequenceResult = sequenceString;
            result.score = temp[0];
            result.last = temp[1];
        }
        
        if (bufferPointer >= bufferSize || (bufferPointer >= maxSequnceLength + 1  && temp[0] == 0) || result.score == maxScore) {
            return;
        }
    } 

    for (int i = 0; i < matrixRow; i++) {
        sequenceString[bufferPointer] = Point(i, currentCol);

        if (bufferPointer == 1 && !CheckStartOfSequence(Point(i, currentCol)) && !CheckStartOfSequence(sequenceString[0])) { // cek yang 1 iya atau ga
            continue;
        }

        if (CheckPoint(Point(i, currentCol), sequenceString, bufferPointer)) {
            continue;
        }

        HorizontalMove(bufferPointer + 1, maxPointer);
    }
}

void BreachProtocolSolver::Solve() {
    auto startTime = chrono::high_resolution_clock::now();

    for (int i = minSequnceLength - 1; i < bufferSize; i++) {
        if (result.score == maxScore) {
            break;
        }
        sequenceString[0] = Point(0, 0);
        HorizontalMove(0, i);
    }

    auto endTime = chrono::high_resolution_clock::now();
    
    auto processingTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    result.time = processingTime.count();

    showResult();
}

void BreachProtocolSolver::ShowMatrixAndSequence() {
    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%s ", matrix[i][j].c_str());
        }
        printf("\n");
    }

    for (int i = 0; i < sequences.size(); i++) {
        for (int j = 0; j < sequences[i].data.size(); j++) {
            printf("%s ", sequences[i].data[j].c_str());
        }
        printf(" -> %d\n", sequences[i].value);
    }
}

bool BreachProtocolSolver::CheckPoint(Point point, vector<Point> sequenceString, int bufferPointer) {
    for (int i = 0; i < bufferPointer; i++) {
        if (sequenceString[i].row == point.row && sequenceString[i].col == point.col) {
            return true;
        }
    }

    return false;
}

bool BreachProtocolSolver::CheckStartOfSequence(Point point) {
    for (set<string>::iterator it = startOfSequences.begin(); it != startOfSequences.end(); it++) {
        if (matrix[point.row][point.col] == *it) {
            return true;
        }
    }
    return false;
}

array<int, 2> BreachProtocolSolver::CheckScore(int bufferPointer) {
    array<int, 2> scoreAndLastPointer = {0, -1};

    for (int i = 0; i < sequences.size(); i++) {
        if (sequences[i].data.size() > bufferPointer + 1) {
            continue;
        }

        bool isMatch;
        int LastPointer = 0;
        for (int j = 0; j <= bufferPointer + 1 - sequences[i].data.size(); j++) {

            isMatch = true;
            
            int k = 0;
            LastPointer = j;

            while (k < sequences[i].data.size()) {
                if (sequenceString[LastPointer].row == -1) {
                    isMatch = false;
                    break;
                }

                if (sequences[i].data[k] != matrix[sequenceString[LastPointer].row][sequenceString[LastPointer].col]) {
                    isMatch = false;
                    break;
                }

                k++;
                LastPointer++;
            }

            if (isMatch) {
                scoreAndLastPointer[0] += sequences[i].value;
                if (LastPointer > scoreAndLastPointer[1]){
                    scoreAndLastPointer[1] = --LastPointer;
                }
                break;
            }
        }
    }

    return scoreAndLastPointer;
}

void BreachProtocolSolver::writeResultToFile(string fileName) {
    fileName = "../test/output/" + fileName + ".txt";
    FILE *file = fopen(fileName.c_str(), "w");

    printf("Menyimpan hasil ke file %s\n", fileName.c_str());

    if (!file) {
        cerr << "Gagal membuat file.\n" << endl;
        return;
    }

    fprintf(file, "%d\n", result.score);
    for (int i = 0; i <= result.last; i++) {
        fprintf(file, "%s ", matrix[result.sequenceResult[i].row][result.sequenceResult[i].col].c_str());
    }
    fprintf(file, "\n");

    for (int i = 0; i <= result.last; i++) {
        fprintf(file, "%d, %d\n", result.sequenceResult[i].row + 1, result.sequenceResult[i].col + 1);
    }
    fprintf(file, "\n");
    
    fprintf(file, "%d ms\n", result.time);
    fclose(file);
    printf("Berhasil menyimpan hasil ke file %s\n\n", fileName.c_str());
}

void BreachProtocolSolver::showResult() {
    if (result.last == -1) {
        printf("Tidak ada hasil yang ditemukan atau hasil terbaik adalah score 0 dengan tidak bergerak.\n");
        return;
    } else {
        printf("Hasil: \n");
    }

    printf("%d\n", result.score);
    for (int i = 0; i <= result.last; i++) {
        printf("%s ", matrix[result.sequenceResult[i].row][result.sequenceResult[i].col].c_str());
    }
    printf("\n");

    for (int i = 0; i <= result.last; i++) {
        printf("%d, %d\n", result.sequenceResult[i].row + 1, result.sequenceResult[i].col + 1);
    }

    printf("\n");
    printf("%d ms\n\n", result.time);

    char pilihan = 'N';

    do
    {
       printf("Apakah akan menyimpan hasil? (Y/N): \n");
    
        cin >> pilihan;
        if (pilihan == 'Y' || pilihan == 'y') {
            string namaFile;
            printf("Masukkan nama file: ");
            cin >> namaFile;
            writeResultToFile(namaFile);
        } else if (pilihan != 'N' && pilihan != 'n') {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 'Y' && pilihan != 'y' && pilihan != 'N' && pilihan != 'n');
    
}