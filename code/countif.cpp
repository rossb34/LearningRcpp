#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

bool is_even(int x){
	return ((x % 2) == 0);
}

bool is_odd(int x){
	return ((x % 2) == 1);
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	int count1, count2, count3, count4, count5, count6, count7, count8;
	int num = 5;
	
	count1 = count_if(vec1.begin(), vec1.end(), bind2nd(std::less<double>(), num));
	count2 = count_if(vec1.begin(), vec1.end(), bind2nd(std::less_equal<double>(), num));

	count3 = count_if(vec1.begin(), vec1.end(), bind2nd(std::greater<double>(), num));
	count4 = count_if(vec1.begin(), vec1.end(), bind2nd(std::greater_equal<double>(), num));
	
	count5 = count_if(vec1.begin(), vec1.end(), bind2nd(std::equal_to<double>(), num));
	count6 = count_if(vec1.begin(), vec1.end(), bind2nd(std::not_equal_to<double>(), num));
	
	count7 = count_if(vec1.begin(), vec1.end(), is_even);
	count8 = count_if(vec1.begin(), vec1.end(), is_odd);
	
	std::cout << "There are: " << std::endl;
	std::cout << count1 << " numbers less than " << num << std::endl;
	std::cout << count2 << " numbers less than or equal to " << num << std::endl;
	std::cout << count3 << " numbers greater than than " << num << std::endl;
	std::cout << count4 << " numbers greater than or equal to " << num << std::endl;
	std::cout << count5 << " numbers equal to " << num << std::endl;
	std::cout << count6 << " numbers not equal to " << num << std::endl;
	
	std::cout << "There are " << count7 << " even numbers" << std::endl;
	std::cout << "There are " << count8 << " odd numbers" << std::endl;
	
	return 0;
}