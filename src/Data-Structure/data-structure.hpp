#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * @brief Represents a sequence of strings with an associated value.
 */
struct Sequence {
    vector<string> data; /**< The sequence of strings. */
    int value; /**< The associated value. */

    /**
     * @brief Constructs a Sequence object with the given data and value.
     * @param data The sequence of strings.
     * @param value The associated value.
     */
    Sequence(const vector<string>& data, int value) : data(data), value(value) {}
};

/**
 * @brief Represents a point in a two-dimensional space.
 */
struct Point {
    int row; /**< The row coordinate of the point. */
    int col; /**< The column coordinate of the point. */

    /**
     * @brief Constructs a new Point object.
     * 
     * @param row The row coordinate of the point.
     * @param col The column coordinate of the point.
     */
    Point(int row, int col) : row(row), col(col) {}
};

#endif // DATA_STRUCTURE_HPP

