#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

std::vector<double> run_sum(const std::vector<double>& v, double x){
	/* compute the running sum */
	std::vector<double> vec(v.size());
	int sz = v.size();
	for(int i = 0; i < sz; i++){
		vec[i+x-1] = std::accumulate(v.begin() + i, v.end() - sz + x + i, 0.0);
	}
	return vec;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	
	vec3 = run_sum(vec1, 3);
	
	std::cout << "run_sum" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}