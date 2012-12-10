#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

double add3(const double& x){
	return x + 3;
}
std::vector<double> vec_myfun(const std::vector<double>& v1){
	std::vector<double> v(v1.size());
	std::transform(v1.begin(), v1.end(), v.begin(), add3);
	return v;
}


int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec2(vec1.size());
	vec2 = vec_myfun(vec1);
	
	std::cout << "Result of vec_myfun(vec1)" << std::endl;
	for(int i = 0; i < vec2.size(); i++){
		std::cout << vec2[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}