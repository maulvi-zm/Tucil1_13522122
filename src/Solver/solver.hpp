#ifndef BREACH_PROTOCOL_SOLVER_HPP
#define BREACH_PROTOCOL_SOLVER_HPP

#include <vector>
#include <string>
#include <set>
#include "../Data-Structure/data-structure.hpp"

using namespace std;

class BreachProtocolSolver {
private:
    int bufferSize,matrixRow, matrixCol;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    set<string> startOfSequences;
    vector<Point> sequenceString;
    vector<vector<Point>> sequenceStringContainer;

    void HorizontalMove(int bufferPointer, int row, int col);

    void VerticalMove(int bufferPointer, int row, int col);

    void CheckScore(vector<Point> sequenceString);

    bool CheckPoint(Point point, vector<Point> sequenceString, int bufferPointer);

    bool CheckStartOfSequence(Point point);

public:
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences);

    void Solve();

    void ShowMatrixAndSequence();
};

#endif // BREACH_PROTOCOL_SOLVER_HPP
