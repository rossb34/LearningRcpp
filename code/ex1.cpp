#include <iostream>
#include <vector>

int main(){
	// initialize a vector of 5 elements initialized to 0
	std::vector<int> vec(5);
	
	// get the size (number of elements) of vec
	int vec_size = vec.size();
	
	std::cout << "number of elements in vec: " << 
		vec_size << std::endl;
		
	// print the vector elements to cout
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl; // this just adds a new line
	
	// assign values to the elements using the [] operator
	// the index starts at 0 in C++
	vec[0] = 6;
	vec[1] = 2;
	vec[2] = 5;
	vec[3] = 1;
	vec[4] = 8;
	
	// print the vector elements to cout
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	// add elements to the end of the vector
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(3);
	
	// print the vector elements to cout
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	// delete the last element
	vec.pop_back();
	
	// print the vector elements to cout
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}