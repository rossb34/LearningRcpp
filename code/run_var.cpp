#include <vector>
#include <numeric>
#include <functional>
#include <math.h>
#include <iostream>

std::vector<double> run_var(const std::vector<double>& v, int x){
		/* compute the running variance */
        double ssq, sum, mean, var;
        int sz = v.size();

        std::vector<double> res(sz);

        for(int i = 0; i < sz; i++){
        	ssq = std::inner_product(v.begin() + i, v.end() - sz + x + i,
        			v.begin() + i, 0.0);

        	sum = std::accumulate(v.begin() + i, v.end() - sz + x + i, 0.0);
        	mean = sum / (double)x;
        	var = (ssq - sum * mean) / (double)(x - 1);
        	res[i+x-1] = var;
        }
        return res;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	std::vector<double> vec3(10);
	
	vec3 = run_var(vec1, 3);
	
	std::cout << "run_var" << std::endl;
	for(int i = 0; i < vec3.size(); i++){
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}