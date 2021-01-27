#include "header/MovingAverageFilter.h"
#include "moving_average_filter.h"

template <typename T>
MovingAverageFilter<T>::MovingAverageFilter(int length_data) {

	if(length_data <= 0) 
  		throw 1;

	size_data = length_data;

	input_data = new T[size_data];
	output_data = new T[size_data];

}

template <typename T>
MovingAverageFilter<T>::MovingAverageFilter() {

	size_data = DEFINE_SIZE_DATA;

	input_data = new T[size_data];
	output_data = new T[size_data];
}

template <typename T>
MovingAverageFilter<T>::~MovingAverageFilter() {

	delete[] input_data;
	delete[] output_data;
}


template <typename T>
void MovingAverageFilter<T>::clear() {
	for (int i = 0; i < size_data; i++) {
		input_data[i] = 0;
		output_data[i] = 0;
	}
}


template <typename T>
void MovingAverageFilter<T>::set_size_window(int length_window){

	if(length_window <= 0)
  		throw 2;
  	
	set_filter_length = true;
	filter_length = length_window;
}

template <typename T>
void MovingAverageFilter<T>::set_random_value(){

	srand(time(0));

	for(int i = 0; i < size_data; i++){

		input_data[i] = 1.0 + 1000.0 * rand() / (float)RAND_MAX;

	}
}

template <typename T>
void MovingAverageFilter<T>::MovingAverageFilterRun(){

	if(!set_filter_length){
		filter_length = DEFINE_FILTER_LENGTH;
	}

	moving_average_filter(input_data, output_data, size_data, filter_length);

}


template <typename T>
void MovingAverageFilter<T>::save_input_data(string filename) {

	ofstream input_file(filename);

    for(int i=0;i<size_data;i++)
    {
        input_file<<input_data[i]<<" ";
    }

    input_file.close();
}


template <typename T>
void MovingAverageFilter<T>::save_output_data(string filename) {

	ofstream output_file(filename);
	
    for(int i=0;i<size_data;i++)
    {
        output_file<<input_data[i]<<" ";
    }

    output_file.close();
}


template class MovingAverageFilter<float>;
template class MovingAverageFilter<double>;