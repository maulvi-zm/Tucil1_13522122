#ifndef UTILS_HPP
#define UTILS_HPP

#include "../Data-Structure/data-structure.hpp"
#include <sstream>
#include <cstdlib>

using namespace std;

/**
 * Splits a string into a vector of substrings based on a delimiter.
 * 
 * @param s The string to be split.
 * @param delimiter The character used as a delimiter.
 * @return A vector of substrings.
 */
vector<string> split(const string& s, char delimiter);

/**
 * Displays the input data.
 *
 * @param bufferSize The size of the buffer.
 * @param matrix The matrix containing strings.
 * @param sequences The vector of sequences.
 */
void displayInput(int bufferSize, const vector<vector<string> >& matrix, const vector<Sequence>& sequences);

/**
 * @brief Creates a matrix from a vector of tokens.
 * 
 * This function takes the number of rows and columns, along with a vector of tokens,
 * and creates a matrix by populating it with the tokens. The resulting matrix is stored
 * in the provided matrix pointer.
 * 
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @param token The vector of tokens.
 * @param matrix A pointer to the matrix where the result will be stored.
 */
void makeMatrixFromToken(int row, int col, const vector<string>& token, vector<vector<string> > *matrix);

/**
 * @brief Creates a sequence of a specified length from a given token list.
 * 
 * This function takes a specified number of sequences and a maximum length for each sequence,
 * along with a vector of tokens. It creates sequences of the specified length by combining
 * consecutive tokens from the token list. The resulting sequences are stored in the provided
 * vector of Sequence objects.
 * 
 * @param jumlahSequence The number of sequences to create.
 * @param maksPanjangSequence The maximum length of each sequence.
 * @param token The vector of tokens to create sequences from.
 * @param sequences A pointer to the vector where the resulting sequences will be stored.
 */
void makeSequenceFromToken(int jumlahSequence, int maksPanjangSequence, const vector<string>& token, vector<Sequence> *sequences);

/**
 * @brief Checks if a string is alphanumeric.
 * 
 * This function takes a string as input and checks if it contains only alphanumeric characters.
 * Alphanumeric characters include uppercase and lowercase letters (A-Z, a-z) and digits (0-9).
 * 
 * @param s The string to be checked.
 * @return True if the string is alphanumeric, false otherwise.
 */
bool CheckAlfaNumeric(const string& s);

#endif // UTILS_HPP