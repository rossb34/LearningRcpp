#include <vector>
#include <numeric>
#include <iostream>

std::vector<double> cumsum1(const std::vector<double>& v1){
	/* compute the cumulative sum of a vector */
	std::vector<double> v(v1.size());
	double acc = 0;
	for(int i = 0; i < v.size(); i ++){
		acc += v1[i];
		v[i] = acc;
	}
	return v;
}

std::vector<double> cumsum2(const std::vector<double>& v1){
	/* compute the cumulative sum of a vector */
    std::vector<double> v(v1.size());
    std::partial_sum(v1.begin(), v1.end(), v.begin());
    return v;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	vec3 = cumsum1(vec1);
	
	std::vector<double> vec4(10);
	vec4 = cumsum2(vec1);
	
	std::cout << "Result of cumsum1(vec1)" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Result of cumsum2(vec1)" << std::endl;	
	for(int i = 0; i < vec4.size(); i++){
		std::cout << vec4[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}