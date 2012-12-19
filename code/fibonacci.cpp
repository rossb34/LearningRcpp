#include <vector>
#include <iostream>

std::vector<int> fib(int n){
	/* Computes the fibonacci sequence 
	   with seed values of 1 and 2 */

        std::vector<int> vec_fib(n);
        vec_fib[0] = 1;
        vec_fib[1] = 2;

        for(int i = 2; i < n; i++)
        {
                vec_fib[i] = vec_fib[i-1] + vec_fib[i-2];
        }
        return vec_fib;
}

int main(){
	std::vector<int> vec1(10);
	
	vec1 = fib(10);
	
	// output of fibonacci
	for(int i = 0; i < vec1.size(); i++){
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}