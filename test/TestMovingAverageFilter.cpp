#include "../src/header/MovingAverageFilter.h"
#include<iostream>
#include<algorithm>
#include<iterator>
#include <vector>


uint64_t rdtsc(){
unsigned int lo,hi;
__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
return ((uint64_t)hi << 32) | lo;
}


int main() {

  const static int size_data = 1000000;

  ofstream output_file("result_file/time");

  int length_filter[6] = {4, 8 ,16, 32, 64, 128};

  output_file<<"double"<<"\n";

  for(int i =0 ; i < 6; i++){


    try{

        MovingAverageFilter<double> movingAverage_1(size_data);

        movingAverage_1.clear();

        movingAverage_1.set_size_window(length_filter[i]);

        movingAverage_1.set_random_value();

        movingAverage_1.save_input_data("result_file/" + to_string(i) + "_input.txt");

        auto cl = clock( );

        movingAverage_1.MovingAverageFilterRun();


        auto cl2 = clock( );

        auto clockTicksTaken  = cl2 - cl;

        auto timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

        output_file<<timeInSeconds<<" ";

        movingAverage_1.save_output_data("result_file/" + to_string(i) + "_output.txt");

        output_file<<"\n"<<"float"<<"\n";

    }

    catch(int thr){

      if(thr == 1) cout << "Error " << thr<< " - size_data <= 0"  << endl;

      if(thr == 2) cout << "Error " << thr<< " - length_filter <= 0"  << endl;
      
    }

  }


  for(int i =0 ; i < 6; i++){

    
    try{

        MovingAverageFilter<float> movingAverage_2(size_data);

        movingAverage_2.clear();

        movingAverage_2.set_size_window(length_filter[i]);

        movingAverage_2.set_random_value();

        movingAverage_2.save_input_data("result_file/" + to_string(i) + "_input.txt");

        auto cl = clock( );

        movingAverage_2.MovingAverageFilterRun();

        auto cl2 = clock( );

        auto clockTicksTaken  = cl2 - cl;

        auto timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

        output_file<<timeInSeconds<<" ";

        movingAverage_2.save_output_data("result_file/" + to_string(i) + "_output.txt");

    }

    catch(int thr){

      if(thr == 1) cout << "Error " << thr<< " - size_data <= 0"  << endl;

      if(thr == 2) cout << "Error " << thr<< " - length_filter <= 0"  << endl;
      
    }

  }

  output_file.close();

  return 0;
}