#include "solver.hpp"

using namespace std;

BreachProtocolSolver::BreachProtocolSolver(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence >& sequences)
    : bufferSize(bufferSize), matrix(matrix), sequences(sequences) {
    for (int i = 0; i < sequences.size(); i++) {
        startOfSequences.insert(sequences[i].data[0]);
    }
}

void BreachProtocolSolver::Solve() {
    int bufferPointer = 0;
    int maxScore = 0;

    for (int i = 0; i < matrix.size(); i++) {
        // Your solving logic here
    }
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
