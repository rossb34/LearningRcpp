#include <vector>
#include <functional>
#include <iostream>

std::vector<double> sub_vec(const std::vector<double>& v1,
	const std::vector<double>& v2){
    std::vector<double> v(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), v.begin(),
                    std::minus<double>());
    return v;
}

std::vector<double> sub_vec(const std::vector<double>& v1,
	const double& n){
        std::vector<double> v(v1.size());
        std::transform(v1.begin(), v1.end(), v.begin(),
                        std::bind2nd(std::minus<double>(), n));
        return v;
}

int main(){
	std::vector<double> vec1(10);
	std::vector<double> vec2(10);
	
	// fill vec1 with 1 to 10
	// fill vec2 with 10 to 19 
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
		vec2[i] = i + 10;
	}
	
	std::vector<double> vec3(10);
	vec3 = sub_vec(vec1, vec2);
	
	std::vector<double> vec4(10);
	vec4 = sub_vec(vec1, 5.5);
	
	std::cout << "Result of sub_vec(vec1, vec2)" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Result of sub_vec(vec1, 5.5)" << std::endl;
	for(int i = 0; i < vec4.size(); i++){
		std::cout << vec4[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}