#include "../src/header/MovingAverageFilter.h"


int main() {

  const static int size_data = 1000000;

  MovingAverageFilter<double> movingAverage_1(size_data);

  movingAverage_1.clear();

  movingAverage_1.set_size_window(4);

  movingAverage_1.set_random_value();

  movingAverage_1.save_input_data("4_input.txt");


  movingAverage_1.MovingAverageFilterRun();

  movingAverage_1.save_output_data("4_output.txt");

  return 0;
}