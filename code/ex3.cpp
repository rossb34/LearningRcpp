// example perform operations on vectors
// add two vectors

#include <iostream>
#include <vector>

// function to add two vectors of ints and 
// return a vector that stores the result
std::vector<int> addVec(const std::vector<int>& v1,
						const std::vector<int>& v2){
	std::vector<int> result(v1.size());
	for(int i = 0; i < v1.size(); i++){
		result[i] = v1[i] + v2[i];
	}
	return result;
}

int main(){
	// initialize vectors
	std::vector<int> vec1(10);
	std::vector<int> vec2(10);
	
	// loop to assign elements 1:10 to vec1
	// and assign elements 20:30 to vec2
	for(int i = 0; i < vec1.size(); i++){
		vec1.at(i) = i + 1;
		vec2.at(i) = i + 20;
	}
	
	// initialize a vector to store the results
	// of adding vec1 and vec2
	std::vector<int> res;
	
	res = addVec(vec1, vec2);
	
	// print the vector elements to cout
	for(int i = 0; i < res.size(); i++){
		std::cout << res.at(i) <<" ";
	}
	std::cout << std::endl;
	
	return 0;
}