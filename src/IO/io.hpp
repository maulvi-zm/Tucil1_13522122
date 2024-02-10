#ifndef IO_HPP
#define IO_HPP

#include "../Data-Structure/data-structure.hpp"
#include "../Utils/utils.hpp"
#include <fstream>

using namespace std;

int readFile(const string namaFile, int *bufferSize, vector<vector<string>> *matrix, vector<Sequence> *sequences);

#endif // IO_HPP