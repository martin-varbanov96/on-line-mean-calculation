#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include "median_struct.h"

#define length(array) array + sizeof(array) / sizeof(int)

using namespace std;

int main()
{
    int data[] = {2, 3, 34, 10, 3, 12, 30 };
    vector<int> data_vector(data, data + sizeof(data) / sizeof(int));
    median_struct media_struct_instance; 
    media_struct_instance.median_calc();
    for(auto el:data_vector){
        media_struct_instance.insert(el);
        media_struct_instance.median_calc();
    }
    cout << "min_heap" << endl;
    for(auto const& el:media_struct_instance.min_heap){
        cout << el << " ";
    }
    cout << "" << endl;

    return 0;
}
