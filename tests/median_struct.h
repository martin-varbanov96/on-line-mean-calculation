#ifndef  MED_H
#define MED_H
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

// Stucture which has a list of integer numbers and a median
struct median_struct{
    float median = nanf("");
    bool median_is_updated = 1;
    vector<int> min_heap;
    vector<int> max_heap;
    void set_update_status(bool);
    void insert(int);
    void median_calc();

};

#endif
