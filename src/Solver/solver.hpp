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
    int time;
};

class BreachProtocolSolver {
private:
    int bufferSize, matrixRow, matrixCol, maxScore, maxSequnceLength = 0;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    set<string> startOfSequences;
    vector<Point> sequenceString;
    Result result;

    void HorizontalMove(int bufferPointer);

    void VerticalMove(int bufferPointer);

    array<int, 2> CheckScore(int bufferPointer);

    bool CheckPoint(Point point, vector<Point> sequenceString, int bufferPointer);

    bool CheckStartOfSequence(Point point);

public:
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences);

    void Solve();

    void ShowMatrixAndSequence();

    void writeResultToFile(string fileName);

    void showResult();
};

#endif // BREACH_PROTOCOL_SOLVER_HPP
