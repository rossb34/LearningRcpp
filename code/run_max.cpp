#include <vector>
#include <algorithm>
#include <iostream>

std::vector<double> run_max(const std::vector<double> v1, int n){
	/* compute the running maximum of a vector */
	std::vector<double> v(v1.size());
	int sz = v.size();
	for(int i = 0; i < sz; i++){
		v[i+n-1] = *std::max_element(v1.begin() + i, v1.end() - sz + n + i);
	}
	return v;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	
	vec3 = run_max(vec1, 3);
	
	std::cout << "run_max" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}