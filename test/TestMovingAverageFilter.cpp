#include "../src/header/MovingAverageFilter.h"

uint64_t rdtsc(){
unsigned int lo,hi;
__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
return ((uint64_t)hi << 32) | lo;
}


int main() {

  const static int size_data = 1000000;

  ofstream output_file("result_file/time");

  int length_filter[6] = {4, 8 ,16, 32, 64, 128};

  output_file<<"\n"<<"double"<<"\n";
  /*measurements for double*/
  for(int i =0 ; i < 6; i++){

    MovingAverageFilter<double> movingAverage_1(size_data);

    movingAverage_1.clear();

    movingAverage_1.set_size_window(length_filter[i]);

    movingAverage_1.set_random_value();

    movingAverage_1.save_input_data("result_file/" + to_string(i) + "_input.txt");

    clock_t cl = clock( );

    movingAverage_1.MovingAverageFilterRun();

    clock_t cl2 = clock( );

    clock_t clockTicksTaken  = cl2 - cl;

    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

    output_file<<timeInSeconds<<" ";

    movingAverage_1.save_output_data("result_file/" + to_string(i) + "_output.txt");

  }

  output_file<<"\n"<<"int"<<"\n";
  /*measurements for int*/
  for(int i =0 ; i < 6; i++){

    MovingAverageFilter<int> movingAverage_2(size_data);

    movingAverage_2.clear();

    movingAverage_2.set_size_window(length_filter[i]);

    movingAverage_2.set_random_value();

    movingAverage_2.save_input_data("result_file/" + to_string(i) + "_input.txt");

    clock_t cl = clock( );

    movingAverage_2.MovingAverageFilterRun();

    clock_t cl2 = clock( );

    clock_t clockTicksTaken  = cl2 - cl;

    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

    output_file<<timeInSeconds<<" ";

    movingAverage_2.save_output_data("result_file/" + to_string(i) + "_output.txt");

  }

  output_file.close();

  return 0;
}