#include <vector>
#include <algorithm>
#include <iostream>

double min(const std::vector<double>& v1){
	/* minimum element of a vector */
	return *std::min_element(v1.begin(), v1.end());
}

int which_min(const std::vector<double>& v1){
	/* position of the minimum element */
	std::vector<double>::const_iterator iter;
	iter = std::min_element(v1.begin(), v1.end());
	return distance(v1.begin(), iter);
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	// use random_shuffle to change the order of the elements
	std::random_shuffle(vec1.begin(), vec1.end());
	
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Minimum: " << min(vec1) << "; ";
	std::cout << "at position: " << which_min(vec1) << std::endl;
	
	return 0;
}