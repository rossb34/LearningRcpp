#include <iostream>
#include <vector>
#include <numeric>


int main(){
	std::vector<double> v(10);
	for(int i = 0; i < v.size(); i++){
		v[i] = i + 1;
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	
	double num1 = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
	
	std::cout << num1 << std::endl;
	
	return 0;
}