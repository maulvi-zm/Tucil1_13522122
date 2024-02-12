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

/**
 * @class BreachProtocolSolver
 * @brief A class that represents a solver for the Breach Protocol game.
 * 
 * The BreachProtocolSolver class is responsible for solving the Breach Protocol game by finding the optimal sequence of actions
 * to maximize the score. It takes a matrix of strings representing the game board and a list of sequences as input.
 * The solver uses various methods to navigate through the matrix and determine the best sequence of actions to achieve the
 * highest score possible.
 */
/**
 * @brief The BreachProtocolSolver class represents a solver for the Breach Protocol game.
 * 
 * This class provides methods to solve the game board and sequences, and display the results.
 */
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
    /**
     * @brief Constructs a BreachProtocolSolver object.
     * 
     * @param bufferSize The size of the buffer.
     * @param matrix The matrix containing the game board.
     * @param sequences The list of sequences to be solved.
     */
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences);

    /**
     * @brief Solves the game board and sequences.
     */
    void Solve();

    /**
     * @brief Displays the matrix and sequence.
     */
    void ShowMatrixAndSequence();

    /**
     * @brief Writes the result to a file.
     * 
     * @param fileName The name of the file to write the result to.
     */
    void writeResultToFile(string fileName);

    /**
     * @brief Displays the result.
     */
    void showResult();
};

#endif // BREACH_PROTOCOL_SOLVER_HPP
