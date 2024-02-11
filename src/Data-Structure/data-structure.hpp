#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

struct Sequence {
    vector<string> data;
    int value;

    Sequence(const vector<string>& data, int value) : data(data), value(value) {}
};

struct Point {
    int row;
    int col;

    Point(int row, int col) : row(row), col(col) {}
};

#endif // DATA_STRUCTURE_HPP

