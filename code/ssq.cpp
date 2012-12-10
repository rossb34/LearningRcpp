#include <vector>
#include <numeric>
#include <iostream>

double ssq(const std::vector<double>& v1){
        return std::inner_product(v1.begin(), v1.end(), v1.begin(), 0.0);
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	double num1;
	num1 = ssq(vec1);
	
	std::cout << "Result of ssq(vec1): " << num1 << std::endl;
	
	return 0;
}