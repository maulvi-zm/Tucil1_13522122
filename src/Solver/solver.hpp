#ifndef BREACH_PROTOCOL_SOLVER_HPP
#define BREACH_PROTOCOL_SOLVER_HPP

#include <vector>
#include <string>
#include <array>
#include <set>
#include <chrono>
#include "../Data-Structure/data-structure.hpp"

using namespace std;

struct Result {
    vector<Point> sequenceResult;
    int score;
    int last;
};

class BreachProtocolSolver {
private:
    int bufferSize,matrixRow, matrixCol;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    set<string> startOfSequences;
    vector<Point> sequenceString;
    vector<vector<Point>> sequenceStringContainer;
    Result result;

    int score[2] = {0, 0};

    void HorizontalMove(int bufferPointer);

    void VerticalMove(int bufferPointer);

    array<int, 2> CheckScore();

    bool CheckPoint(Point point, vector<Point> sequenceString, int bufferPointer);

    bool CheckStartOfSequence(Point point);

public:
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences);

    void Solve();

    void ShowMatrixAndSequence();
};

#endif // BREACH_PROTOCOL_SOLVER_HPP
