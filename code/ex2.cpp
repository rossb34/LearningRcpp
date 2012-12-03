// example to compute the sum and mean of a vector
// the example will consider a vector of ints

#include <iostream>
#include <vector>
#include <numeric>

// function to compute the sum of an int vector
int sum1(std::vector<int> v){
	int acc = 0;
	for(int i = 0; i < v.size(); i++){
		acc += v[i];
	}
	return acc;
}

// function to compute the sum of an int vector
// this function makes use of accumulate from
// the numeric header
int sum2(std::vector<int> v){
	return std::accumulate(v.begin(), v.end(), 0);
}

double mean(std::vector<int> v){
	double result = sum2(v) / (double)v.size();
	return result;
}

int main(){
	
	// initialize a vector
	std::vector<int> vec(10);
	
	// loop to assign values 1:10 to the vector
	for(int i = 0; i < vec.size(); i++){
		// vec[i] = i + 1;
		vec.at(i) = i + 1;
	}
	
	// print the vector elements to cout
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	// compute the mean and sum of the vector
	int vec_sum1 = sum1(vec);
	int vec_sum2 = sum2(vec);
	double vec_mean = mean(vec);
	
	std::cout << "sum1 function using loop" << std::endl;
	std::cout << "The sum of the vector is " << vec_sum1 << std::endl;
	
	std::cout << "sum2 function using accumulate" << std::endl;
	std::cout << "The sum of the vector is " << vec_sum2 << std::endl;
	
	std::cout << "the mean of the vector is " << vec_mean << std::endl;
		
	return 0;
}