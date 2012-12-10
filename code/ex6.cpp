// fibonacci

#include <iostream>
#include <vector>

// returns a vector with the first
// n numbers in the fibonacci sequence
std::vector<int> fib(int n)
{
	// fibonacci function with seed
	// values of 1 and 2
	
	// declare a vector of ints
	std::vector<int> vec_fib(n);
	vec_fib.at(0) = 1;
	vec_fib.at(1) = 2;
	
	for(int i = 2; i < n; i++)
	{
		vec_fib[i] = vec_fib[i-1] + vec_fib[i-2];
	}
	return vec_fib;
}

int main(){
	const int size = 10;
	
	std::vector<int> vec1(size);
	
	vec1 = fib(size);
	
	// print the elements of the vector
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1.at(i) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}