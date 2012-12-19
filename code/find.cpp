#include <vector>
#include <algorithm>
#include <iostream>


bool search1(std::vector<double> v1, double n){
	/* search for an element in a vector */
	sort(v1.begin(), v1.end());
	return binary_search(v1.begin(), v1.end(), n);
}

void find1(const std::vector<double>& v1, double n){
	std::vector<double>::const_iterator it;
	it = find(v1.begin(), v1.end(), n);
	if(it == v1.end()){
		std::cout << "NA" << std::endl;
	} else {
		std::cout << *it << std::endl;
	}
}

int find1_which(const std::vector<double>& v1, double n){
	std::vector<double>::const_iterator it;
	it = find(v1.begin(), v1.end(), n);
	if(it == v1.end()){
		return NULL;
	} else {
		return distance(v1.begin(), it);
	}
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
	
// 	std::cout << "in? " << search1(vec1, 40) << std::endl;
// 	std::cout << find1(vec1, 40) << std::endl;
	
	std::cout << "enter a number: ";
	double num;
	std::cin >> num;
	
	std::cout << "positon: " << find1_which(vec1, num) << std::endl;
	
	return 0;
}