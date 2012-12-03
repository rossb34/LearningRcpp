// operations on vectors
// add a scalar to a vector
// multiply a vector by a scalar

#include <iostream>
#include <vector>

// function to add a double to a vector of doubles
// note that the values of v will be changed
// because the functions are pass by reference
std::vector<double> add(std::vector<double>& v, double n){
	for(int i = 0; i < v.size(); i++){
		v[i] += n;
	}
	return v;
}

// function to multiply a double to a vector of doubles
// note that the values of v will be changed
// because the functions are pass by reference
std::vector<double> mult(std::vector<double>& v, double n){
	for(int i = 0; i < v.size(); i++){
		v[i] *= n;
	}
	return v;
}

int main(){
	// initialize vectors
	std::vector<double> vec1(10);
	
	// loop to assign values 1:10 to the vector
	for(int i = 0; i < vec1.size(); i++){
		vec1.at(i) = i + 1;
	}
	
	// add 3.8 to vec1
	add(vec1, 3.8);
	
	std::cout << "vec1 after adding 3.8: ";
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1.at(i) << " ";
	}
	std::cout << std::endl;
	
	// multiply vec1 by 5.2
	mult(vec1, 5.2);
	
	std::cout << "vec1 after multiplying by 5.2: ";
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1.at(i) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}