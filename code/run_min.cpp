#include <vector>
#include <algorithm>
#include <iostream>

std::vector<double> run_min(const std::vector<double>& v1, int n){
	/* calculate the running min of a vector */
	std::vector<double> v(v1.size());
	int sz = v.size();
	for(int i = 0; i < sz; i++){
		v[i+n-1] = *std::min_element(v1.begin() + i, v1.end() - sz + n + i);
	}
	return v;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec2(10);
	
	vec2 = run_min(vec1, 3);
	
	std::cout << "run_min" << std::endl;
	for(int i = 0; i < vec2.size(); i++){
		std::cout << vec2[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}