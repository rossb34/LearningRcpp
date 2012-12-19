#include <vector>
#include <cmath>
#include <iostream>


std::vector<double> vec_pow(const std::vector<double>& v1, const double& n){
	/* nth power of each element of a vector */
    std::vector<double> v(v1.size());
    for(int i = 0; i < v.size(); i++){
        v[i] = pow(v1[i], n);
    };
    return v;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	vec3 = vec_pow(vec1, 3.5);
	
	
	std::cout << "Result of vec_pow(vec1, 3.5)" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}