#include <vector>
#include <algorithm>
#include <iostream>

std::vector<double> pct_rank(std::vector<double> v1){
	/* compute the percent rank of a vector */
	int sz = v1.size();
	sort(v1.begin(), v1.end());
	std::vector<double> v(sz);
	for(int i = 0; i < sz; i++){
		v[i] = (i + 1) / (double)sz;
	}
	return v;
}

int main(){
	std::vector<double> vec1(9);
	std::vector<double> vec2(9);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
		
	vec2 = pct_rank(vec1);
	
	for(int i = 0; i < vec2.size(); i++){
		std::cout << vec2[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}