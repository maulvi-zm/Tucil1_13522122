#include "solver.hpp"

using namespace std;

BreachProtocolSolver::BreachProtocolSolver(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence >& sequences)
    : bufferSize(bufferSize), matrix(matrix), sequences(sequences) {
    for (int i = 0; i < sequences.size(); i++) {
        startOfSequences.insert(sequences[i].data[0]);
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

    result = {{}, 0, -1};
}

void BreachProtocolSolver::HorizontalMove(int bufferPointer) {
    int currentRow = 0;
    if (bufferPointer == 0) {
        currentRow = 0;
    } else {
        currentRow = sequenceString[bufferPointer - 1].row;
    }

    if (bufferPointer == bufferSize) {
        // sequenceStringContainer.push_back(sequenceString);
        
        // for (int i = 0; i < sequenceString.size(); i++){
        //     printf("(%d %d) ", sequenceString[i].row, sequenceString[i].col);
        // }
        // cout << endl;

        array<int, 2> temp = CheckScore();

        // cout << temp[0] << temp[1] << endl;

        if (temp[0] > result.score || (temp[0] == result.score && temp[1] < result.last)){
            result.sequenceResult = sequenceString;
            result.score = temp[0];
            result.last = temp[1];
        }

        return;
    } 

    for (int i = 0; i < matrixCol; i++) {
        sequenceString[bufferPointer] = Point(currentRow, i);
        
        if (bufferPointer == 1 && !CheckStartOfSequence(Point(currentRow, i)) && !CheckStartOfSequence(sequenceString[0])) {
            continue;
        }

        if (CheckPoint(Point(currentRow, i), sequenceString, bufferPointer)) {
            continue;
        }

        VerticalMove(bufferPointer + 1);
    }
}

void BreachProtocolSolver::VerticalMove(int bufferPointer) {
    int currentCol = 0;
    if (bufferPointer == 0) {
        currentCol = 0;
    } else {
        currentCol = sequenceString[bufferPointer - 1].col;
    }

    if (bufferPointer == bufferSize) {
        // sequenceStringContainer.push_back(sequenceString);

        // for (int i = 0; i < sequenceString.size(); i++){
        //     printf("(%d %d) ", sequenceString[i].row, sequenceString[i].col);
        // }
        // cout << endl;

        array<int, 2> temp = CheckScore();

        // cout << temp[0] << temp[1] << endl;

        if (temp[0] > result.score || (temp[0] == result.score && temp[1] < result.last)){
            result.sequenceResult = sequenceString;
            result.score = temp[0];
            result.last = temp[1];
        }

        return;
    } 

    for (int i = 0; i < matrixRow; i++) {
        sequenceString[bufferPointer] = Point(i, currentCol);

        if (bufferPointer == 1 && !CheckStartOfSequence(Point(i, currentCol)) && !CheckStartOfSequence(sequenceString[0])) { // cek yang 1 iya atau ga
            continue;
        }

        if (CheckPoint(Point(i, currentCol), sequenceString, bufferPointer)) {
            continue;
        }

        HorizontalMove(bufferPointer + 1);
    }
}

void BreachProtocolSolver::Solve() {
    int bufferPointer = 0;

    auto startTime = chrono::high_resolution_clock::now();

    HorizontalMove(bufferPointer);

    auto endTime = chrono::high_resolution_clock::now();
    
    auto processingTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    // for (int i = 0; i < sequenceStringContainer.size(); i++){
    //     for (int j = 0; j < sequenceStringContainer[i].size(); j++){
    //         printf("(%d %d)", sequenceStringContainer[i][j].row, sequenceStringContainer[i][j].col);
    //     }
    //     printf("\n");

    // }

    printf("\nScore: %d\n", result.score);

    for(int i = 0; i <= result.last; i++){
        printf("(%d %d)", result.sequenceResult[i].row, result.sequenceResult[i].col);
    }

    printf("\nProcessing time");
    cout << processingTime.count() << endl;
    
    cout << endl;
    
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

array<int, 2> BreachProtocolSolver::CheckScore() {
    array<int, 2> scoreAndLastPointer = {0, -1};

    for (int i = 0; i < sequences.size(); i++) {
        if (sequences[i].data.size() > bufferSize) {
            continue;
        }

        bool isMatch;
        int LastPointer;
        for (int j = 0; j <= bufferSize - sequences[i].data.size(); j++) {

            isMatch = true;
            
            int k = 0;
            int LastPointer = j;

            while (k < sequences[i].data.size()) {
                // printf("%d %s %s %d \n", i, sequences[i].data[k].c_str(), matrix[sequenceString[LastPointer].row][sequenceString[LastPointer].col].c_str(), LastPointer);
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
