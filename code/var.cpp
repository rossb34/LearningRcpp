#include <vector>
#include <numeric>
#include <iostream>

double variance(const std::vector<double>& v){
        /* Computes the sample variance of a vector */

        double ssq = 0;
        double sum = 0;
        double mean = 0;
        double sz = (double)v.size();
        double var;

        ssq = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
        sum = std::accumulate(v.begin(), v.end(), 0.0);
        mean = sum / sz;

        var = (ssq - sum * mean) / (sz - 1);
        return var;
}

int main(){
	std::vector<double> vec1(10);
	
	// fill vec1 with 1 to 10
	for(int i = 0; i < vec1.size(); i++){
		vec1[i] = i + 1;
	}
	
	double num1 = variance(vec1);
	
	std::cout << num1 << std::endl;
	
	return 0;
}