#include "header/MovingAverageFilter.h"


template <typename T>
MovingAverageFilter<T>::MovingAverageFilter(int length_data) {

	size_data = length_data;

	input_data = new T[size_data];
	output_data = new T[size_data];

}

template <typename T>
MovingAverageFilter<T>::MovingAverageFilter() {

	size_data = DEFINE_LENGTH;

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

	T current_sum = 0;

	if(!set_filter_length){
		filter_length = default_filter_length;
	}

	/*counting the first time the value of the sum of the window elements*/
	for(int i=0; i < filter_length; i++){
		current_sum += input_data[i];
	}

	/*calculating the average for all remaining values*/
	for(int i = 0; i < size_data - filter_length; i++){

		output_data[i + filter_length] = current_sum / filter_length;

		current_sum = current_sum - input_data[i] + input_data[i + filter_length];
	}
}


template <typename T>
void MovingAverageFilter<T>::save_input_data(char* filename) {

	ofstream input_file(filename);

    for(int i=0;i<size_data;i++)
    {
        input_file<<input_data[i]<<" ";
    }

    input_file.close();
}


template <typename T>
void MovingAverageFilter<T>::save_output_data(char* filename) {

	ofstream output_file(filename);
	
    for(int i=0;i<size_data;i++)
    {
        output_file<<input_data[i]<<" ";
    }

    output_file.close();
}


template class MovingAverageFilter<int>;
template class MovingAverageFilter<double>;