#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

std::vector<double> run_mean(const std::vector<double>& v, int x){
	/* computes the moving average */
	std::vector<double> vec(v.size());
	int sz = v.size();
	for(int i = 0; i < sz; i++){
		vec[i+x-1] = std::accumulate(v.begin() + i, v.end() - sz + x + i, 0.0);
	}
	std::transform(vec.begin(), vec.end(), vec.begin(), 
		std::bind2nd(std::divides<double>(), (double)x));
	return vec;
}

int main(){
	std::vector<double> vec1(10);
	std::vector<double> vec2(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1.3;
	}
	
	vec2 = run_mean(vec1, 3);
	
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec2[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}