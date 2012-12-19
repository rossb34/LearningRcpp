#include <vector>
#include <algorithm>
#include <iostream>


void sort_a(std::vector<double>& v1){
	/* sort vector in ascending order */
	sort(v1.begin(), v1.end());
}

void sort_d(std::vector<double>& v1){
	/* sort vector in descending order */
	sort(v1.begin(), v1.end(), std::greater<double>());
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	// use random_shuffle to change the order of the elements
	std::random_shuffle(vec1.begin(), vec1.end());
	
	std::cout << "shuffled vector" << std::endl;
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	
	/* vec1 sorted in ascending order */
	sort_a(vec1);
	
	std::cout << "sorted vector" << std::endl;
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	
	/* vec1 sorted in descending order*/
	sort_d(vec1);
	
	std::cout << "reversed vector" << std::endl;
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}