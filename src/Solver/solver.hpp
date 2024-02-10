#ifndef BREACH_PROTOCOL_SOLVER_HPP
#define BREACH_PROTOCOL_SOLVER_HPP

#include <vector>
#include <string>
#include <set>
#include "../Data-Structure/data-structure.hpp"

using namespace std;

class BreachProtocolSolver {
private:
    int bufferSize;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    set<string> startOfSequences;

    void HorizontalMove();
    void VerticalMove();
    void CheckScore();

public:
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences);

    void Solve();
    void ShowMatrixAndSequence();
};

#endif // BREACH_PROTOCOL_SOLVER_HPP
