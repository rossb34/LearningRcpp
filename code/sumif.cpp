#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>

bool is_odd(int x){
	return ((x % 2) == 1);
}

int main(){
		std::vector<int> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	int sum = 0;
	for(int i = 0; i < vec1.size(); i++){
		if(vec1[i] % 2 == 1){
			sum += vec1[i];
		}
	}
	
	int sum2 = std::accumulate(vec1.begin(), vec1.end(), 0);
	
	std::cout << "Sum of odd numbers: " << sum2 << std::endl;
	return 0;
}