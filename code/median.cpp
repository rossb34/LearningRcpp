#include <vector>
#include <algorithm>
#include <iostream>

double vec_median(std::vector<double> v1){
	/* compute the median of a vector */
	int sz = v1.size();
	sort(v1.begin(), v1.end());
	if(sz % 2 != 0){
		int med_pos = (sz + 1) / 2;
		double med = v1[med_pos - 1];
		return med;
	} else {
		int med_pos_l = (sz / 2) - 1;
		int med_pos_u = (sz / 2);
		double med = (v1[med_pos_l] + v1[med_pos_u]) / (double)2;
		return med;
	}
}

int main(){
	std::vector<double> vec1(9);
	std::vector<double> vec2(9);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	double num1 = vec_median(vec1);
	
	std::cout << "the median is: " << num1 << std::endl;
	
	return 0;
}