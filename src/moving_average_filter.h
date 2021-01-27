//#include "header/MovingAverageFilter.h"                      

template <typename T>
void moving_average_filter(T * input_data, T * output_data, int size_data, int filter_length){

  	if(size_data <= 0) 
  		throw 1;

  	if(filter_length <= 0)
  		throw 2;


	T current_sum = 0;

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