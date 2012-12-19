#include <vector>
#include <numeric>
#include <iostream>

double mean(const std::vector<double>& v1){
	/* compute the mean of a vector */
	return std::accumulate(v1.begin(), v1.end(), 0.0) / (double)v1.size();
}


int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	double num1 = mean(vec1);
	
	std::cout << "mean(vec1) = " << num1 << std::endl;
		
	return 0;
}