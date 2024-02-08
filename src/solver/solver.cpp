#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <tuple>

using namespace std;
using Sequence = tuple<vector<string>, int>;

class BreachProtocolSolver {
private:
    int bufferSize;
    vector<vector<string>> matrix;
    vector<Sequence> sequences;
    set<string> startOfSequences;
    vector<int[2]> result;
    int maxScore = 0;

public:
    BreachProtocolSolver(int bufferSize, const vector<vector<string>>& matrix, const vector<Sequence>& sequences)
        : bufferSize(bufferSize), matrix(matrix), sequences(sequences) {
        for (int i = 0; i < sequences.size(); i++) {
            startOfSequences.insert(get<0>(sequences[i])[0]);
        }
    }

    void HorizontalMove(){

    }

    void VerticalMove(){

    }

    void CheckScore(){

    }

    void Solve() {
        int bufferPointer = 0;

        for (int i = 0; i < matrix.size(); i++) {
            // Your solving logic here
        }
    }
};

int main() {
    int bufferSize = 5;
    vector<vector<string>> matrix = {
        {"55", "55", "BD"},
        {"55", "55", "BD"},
        {"55", "55", "BD"},
        {"55", "55", "BD"},
        {"55", "55", "BD"}
    };
    vector<Sequence> sequences = {
        {{"55", "55", "BD"}, 10},
        {{"55", "55", "BD"}, 20},
        {{"55", "55", "BD"}, 30}
    };

    BreachProtocolSolver solver(bufferSize, matrix, sequences);

    return 0;
}