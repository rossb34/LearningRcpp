#include <vector>
#include <algorithm>
#include <iostream>

std::vector<double> vec_squared(const std::vector<double>& v1){
	std::vector<double> v(v1.size());
	for(int i = 0; i < v1.size(); i++){
		v[i] = v1[i] * v1[i];
	}
	return v;
}

std::vector<double> vec_squared1(const std::vector<double>& v1){
        std::vector<double> v(v1.size());
        std::transform(v1.begin(), v1.end(), v1.begin(), v.begin(),
                        std::multiplies<double>());
        return v;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	vec3 = vec_squared(vec1);
	
	std::vector<double> vec4(10);
	vec4 = vec_squared1(vec1);
	
	std::cout << "Result of vec_squared(vec1)" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Result of vec_squared1(vec1)" << std::endl;	
	for(int i = 0; i < vec4.size(); i++){
		std::cout << vec4[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}