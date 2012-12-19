#include <vector>
#include <numeric>
#include <iostream>

double sum1(const std::vector<double>& v1){
	/* compute the sum of a vector */
	double acc = 0;
	for(int i = 0; i < v1.size(); i++){
		acc += v1[i];
	}
	return acc;
}

double sum2(const std::vector<double>& v1){
	/* compute the sum of a vector */
	return std::accumulate(v1.begin(), v1.end(), 0.0);
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	double num1, num2;
	
	num1 = sum1(vec1);
	num2 = sum2(vec1);
	
	std::cout << "sum1(vec1) = " << num1 << std::endl;
	std::cout << "sum2(vec2) = " << num2 << std::endl;
	
	return 0;
}