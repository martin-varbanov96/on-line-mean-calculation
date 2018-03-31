#include "median_struct.h"
#include <gtest/gtest.h>
 
#define length(array) sizeof(array)/sizeof(array[0])
#define randRange(x,y) x + ( std::rand() % ( y - x + 1 ) )


template <typename T>
float getMean(T& sorted_input_list){
    T working_list = sorted_input_list;
    int size = working_list.size();
    std::cout << "n is : " << size << std::endl; 
    if( size%2 == 0){
        return (working_list[size/2] + working_list[(size/2) - 1])/2;
    }else{
        return (working_list[size/2]);
    }
}

// Check if struct attribute "median_is_updated" is in its default value: 1
TEST(DefaultUpdateFlag, CheckDefaultUpdateFlag) { 
    median_struct media_struct_instance;
    ASSERT_EQ(1, media_struct_instance.median_is_updated);
}

// Add a random element and check if it is corectly added
TEST(insert, check_for_insert) { 
    median_struct media_struct_instance;
    int number_to_insert = 5;
    media_struct_instance.insert(number_to_insert);

    ASSERT_EQ(number_to_insert, media_struct_instance.min_heap[0]);
}

// check second insert is correctly asserted
TEST(second_insert_assertion, DeathFromOverInserting) { 
    median_struct media_struct_instance;
    int number_to_insert = 5;
    media_struct_instance.insert(number_to_insert);
    EXPECT_DEATH(media_struct_instance.insert(number_to_insert), "adasd");	
}

// Check if algorithm works for a specific array
TEST(algorithmTest, TestAlgorithmSpecificArray) { 
    
    //raw data
    int data[] = {2, 3, 34, 10, 3, 12, 30 };
    
    // vector for our algorithm
    vector<int> data_vector(data, data + sizeof(data) / sizeof(int));
    
    // std array for our test median function
    const int arr_length = length(data); 
    std::array<int,arr_length> data_std_array;
    std::copy(std::begin(data), std::end(data), std::begin(data_std_array));

    //Declare our struct
    median_struct media_struct_instance;

    //Iterate over every value and calculate median for evey new insertion
    for(auto el:data_vector){
        media_struct_instance.insert(el);
        media_struct_instance.median_calc();
        float acceptable_value = 0.0001;
        float result = std::abs(getMean(data_std_array)-media_struct_instance.median);
        EXPECT_EQ(0, result);    
    }
}

// Check if algorithm works for a random array
TEST(algorithmTest, TestAlgorithmRandomArray) { 
    
    float a = randRange(2, 200);

    // std array for our test median function
    const int arr_length = 1000;

    //raw data
    int data[arr_length];
    for(int i = 0; i < arr_length; i++){
        data[i] = randRange(-200, 200); 
    }
    
    // vector for our algorithm
    vector<int> data_vector(data, data + sizeof(data) / sizeof(int));
    
    std::array<int,arr_length> data_std_array;
    std::copy(std::begin(data), std::end(data), std::begin(data_std_array));

    //Declare our struct
    median_struct media_struct_instance;

    //Iterate over every value and calculate median for evey new insertion
    for(auto el:data_vector){
        media_struct_instance.insert(el);
        media_struct_instance.median_calc();
        float acceptable_value = 0.0001;
        float result = std::abs(getMean(data_std_array)-media_struct_instance.median);
        EXPECT_EQ(0, result);    
    }
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
