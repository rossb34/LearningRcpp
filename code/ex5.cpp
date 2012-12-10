// example to compute the cumulative sum
// of a vector of doubles

#include <iostream>
#include <vector>
#include <numeric>

std::vector<double> CumSum(const std::vector<double>& v){
	double sum = 0;
	int sz = v.size();
	std::vector<double> vec(sz);
	for(int i = 0; i < v.size(); i++){
		vec[i] = std::accumulate(v.begin(), v.end() - sz + i + 1, 0.0);
	}
	return vec;
}

int main(){
		// initialize vectors
	std::vector<double> vec1(10);
	std::vector<double> vec2(10);
	
	// loop to assign values 1:10 to the vector
	for(int i = 0; i < vec1.size(); i++){
		vec1.at(i) = i + 1;
	}
	
	vec2 = CumSum(vec1);
	
	// print the elements of the vector
	for(int i = 0; i < vec2.size(); i++){
		std::cout << vec2.at(i) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}