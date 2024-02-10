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

#endif // DATA_STRUCTURE_HPP

