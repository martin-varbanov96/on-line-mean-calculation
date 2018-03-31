#include "median_struct.h"
#include <iostream>
#include <assert.h> 

bool compare_less(const int &a, const int &b)
{
    return b < a;
}

bool compare_greater(const int &a, const int &b)
{
    return a < b;
}

void median_struct::set_update_status(bool input_status){
    this->median_is_updated = input_status;
}

// insert a single element to one of the heaps
void median_struct::insert(int input_data)
{
    // TODO:: Convert to exception
    // Terminate if median hasn't been updated since last insert
    assert(this->median_is_updated == 1);

    int working_data = input_data;
    // int n = input_data.size();
    this->min_heap.reserve(min_heap.size()+1);
    this->max_heap.reserve(max_heap.size()+1);

    //If input value is smaller than median, put it in the min heap
    if (isnan(this->median) || (float)working_data <= this->median)
    {
        this->min_heap.push_back(working_data);
        push_heap(this->min_heap.begin(), this->min_heap.end(), compare_greater);
    }
    else
    {
        this->max_heap.push_back(working_data);
        push_heap(this->max_heap.begin(), this->max_heap.end(), compare_less);
    }
    this->set_update_status(0);   
}

// TODO:: Add template
// calculate the median of the data + the given input
void median_struct::median_calc()
{
    //TODO:: Convert to exception
    assert(!this->max_heap.empty() && 
           !this->min_heap.empty()
           );
    int x;
    while (this->max_heap.size() > this->min_heap.size() + 1)
    {
        x = this->max_heap[0];
        pop_heap(this->max_heap.begin(), this->max_heap.end(), compare_less);
        this->max_heap.pop_back();
        this->min_heap.push_back(x);
        push_heap(this->min_heap.begin(), this->min_heap.end(), compare_greater);
    }
    while (this->min_heap.size() > this->max_heap.size() + 1)
    {
        x = this->min_heap[0];
        pop_heap(this->min_heap.begin(), this->min_heap.end(), compare_greater);
        this->min_heap.pop_back();
        this->max_heap.push_back(x);
        push_heap(this->max_heap.begin(), this->max_heap.end(), compare_less);
    }
    
    //Update median
    if (this->min_heap.size() > this->max_heap.size()) 
        this->median = this->min_heap[0];
    else if (this->max_heap.size() > this->min_heap.size()) 
        this->median = this->max_heap[0];
    else 
        this->median = (this->min_heap[0] + this->max_heap[0]) / 2.0f;
    
    this->set_update_status(1);
}


