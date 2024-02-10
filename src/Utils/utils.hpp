#ifndef UTILS_HPP
#define UTILS_HPP

#include "../Data-Structure/data-structure.hpp"
#include <sstream>
#include <cstdlib>

using namespace std;

vector<string> split(const string& s, char delimiter);
void displayInput(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence>& sequences);
void makeMatrixFromToken(int row, int col, const vector<string>& token, vector<vector<string> > *matrix);
void makeSequenceFromToken(int jumlahSequence, int maksPanjangSequence, const vector<string>& token, vector<Sequence> *sequences);

#endif // UTILS_HPP