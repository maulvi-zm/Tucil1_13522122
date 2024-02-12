#ifndef IO_HPP
#define IO_HPP

#include "../Data-Structure/data-structure.hpp"
#include "../Utils/utils.hpp"
#include <fstream>

using namespace std;

/**
 * Reads a file and populates the provided variables with the data.
 * 
 * @param namaFile The name of the file to be read.
 * @param bufferSize A pointer to an integer variable to store the size of the buffer.
 * @param matrix A pointer to a vector of vectors of strings to store the matrix data.
 * @param sequences A pointer to a vector of Sequence objects to store the sequence data.
 * @return An integer representing the status of the file reading operation.
 */
int readFile(const string namaFile, int *bufferSize, vector<vector<string>> *matrix, vector<Sequence> *sequences);

#endif // IO_HPP