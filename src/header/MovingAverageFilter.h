#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <stdint.h>
#include <chrono>
#include <string>

#define DEFINE_SIZE_DATA 1000000;
#define DEFINE_FILTER_LENGTH 4;

using namespace std;

template <class T>
class MovingAverageFilter {

private:

	T * input_data;
	T * output_data;

	int size_data;
	int filter_length;
	
	bool set_filter_length = false;

public:

	MovingAverageFilter(int length_data);

	MovingAverageFilter();

	~MovingAverageFilter();

	/*set value input_data massive in 0*/
	void clear();

	/* set size of sliding window*/
	void set_size_window(int length_window);

	/*fill the array with random values*/
	void set_random_value();

	void MovingAverageFilterRun();

	void save_input_data(string filename);
	void save_output_data(string filename);

};
