#include "solver.hpp"

using namespace std;

BreachProtocolSolver::BreachProtocolSolver(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence >& sequences)
    : bufferSize(bufferSize), matrix(matrix), sequences(sequences) {
    for (int i = 0; i < sequences.size(); i++) {
        startOfSequences.insert(sequences[i].data[0]);
    }

    for (int i = 0; i < bufferSize; i++) {
        sequenceString.push_back(Point(-1, -1));
    }
}

void BreachProtocolSolver::HorizontalMove(int bufferPointer, int row, int col) {
    if (bufferPointer < 0) {
        return;
    }

    if (col >= matrix[row].size()) {
        int LastCol = sequenceString[bufferPointer - 1].col;

        sequenceString[bufferPointer] = Point(-1, -1);

        VerticalMove(bufferPointer - 1, row + 1, LastCol);

        return;

    }

    if (CheckPoint(Point(row, col), sequenceString, bufferPointer)) {
        HorizontalMove(bufferPointer, row, col + 1);
    } else if (bufferPointer == bufferSize - 1) {
        sequenceString[bufferPointer] = Point(row, col);
        sequenceStringContainer.push_back(sequenceString);

        for (int i = 0; i < sequenceString.size(); i++) {
            printf("<%d %d> ", sequenceString[i].row, sequenceString[i].col);
        }
        printf("\n");

        HorizontalMove(bufferPointer, row, col + 1);

    } else if (bufferPointer == 1 && !CheckStartOfSequence(Point(row, col))) {

        HorizontalMove(bufferPointer, row, col + 1);

    }  else {
        sequenceString[bufferPointer] = Point(row, col);

        VerticalMove(bufferPointer + 1, 0, col);
    }
}

void BreachProtocolSolver::VerticalMove(int bufferPointer, int row, int col) {
    if (bufferPointer < 0) {
        return;
    }
    if (row >= matrix.size()) {

        int LastRow = sequenceString[bufferPointer - 1].row;

        sequenceString[bufferPointer] = Point(-1, -1);

        HorizontalMove(bufferPointer - 1, LastRow, col + 1);

        return;

    } 

    if (CheckPoint(Point(row, col), sequenceString, bufferPointer)) {
        // printf("masuk: %d %d || buffer %d ||", row, col, bufferPointer);
        // for (int i = 0; i < sequenceString.size(); i++) {
        //     printf("<%d %d> ", sequenceString[i].row, sequenceString[i].col);
        // }
        // printf("\n");

        VerticalMove(bufferPointer, row + 1, col);
        
    } else if (bufferPointer == bufferSize - 1) {
        sequenceString[bufferPointer] = Point(row, col);
        sequenceStringContainer.push_back(sequenceString);

        for (int i = 0; i < sequenceString.size(); i++) {
            printf("<%d %d> ", sequenceString[i].row, sequenceString[i].col);
        }
        printf("\n");

        VerticalMove(bufferPointer, row + 1, col);

    } else if (bufferPointer == 1 && !CheckStartOfSequence(Point(row, col))) {

        VerticalMove(bufferPointer, row + 1, col);

    } else {
        sequenceString[bufferPointer] = Point(row, col);

        HorizontalMove(bufferPointer + 1, row, 0);
    }
}

void BreachProtocolSolver::Solve() {
    int bufferPointer = 0;
    int maxScore = 0;

    HorizontalMove(bufferPointer, 0, 0);
    
    // for (int i = 0; i < sequenceStringContainer.size(); i++) {
    //     for (int j = 0; j < sequenceStringContainer[i].size(); j++) {
    //         printf("%s ", matrix[sequenceStringContainer[i][j].row][sequenceStringContainer[i][j].col].c_str());
    //     }

    //     cout << endl;
    // }
}

void BreachProtocolSolver::ShowMatrixAndSequence() {
    for (int i = 0; i < matrix.size(); i++) {
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
    for (int i = 0; i < sequenceString.size(); i++) {
        if (i == bufferPointer) {
            continue;;
        }

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
