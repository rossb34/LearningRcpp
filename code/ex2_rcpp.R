library(Rcpp)
library(inline)

Sys.setenv(R_ARCH="/x86_64")

# sum1
# sum the vector using a loop
sum1 <- cxxfunction(signature(x = "numeric"),
                    'NumericVector xx(x);
                    double sum = 0;
                    for(int i = 0; i < xx.size(); i++){
                      sum += xx[i];
                    }
                    return wrap(sum);',
                    plugin = "Rcpp")

# sum2
# sum the vector using std::accumulate
sum2 <- cxxfunction(signature(x = "numeric"),
                    'NumericVector xx(x);
                    double res = std::accumulate(xx.begin(), xx.end(), 0.0);
                    return wrap(res);',
                    plugin = "Rcpp")

# sum3
# sum the vector using Rcpp sugar
sum3 <- cxxfunction(signature(x = "numeric"),
                    'NumericVector xx(x);
                    double res = sum(xx);
                    return wrap(res);',
                    plugin = "Rcpp")

# mean1
# compute the mean of a vector using Rcpp
mean1 <- cxxfunction(signature(x = "numeric"),
                    'NumericVector xx(x);
                    double sum = std::accumulate(xx.begin(), xx.end(), 0.0);
                    double res = sum / xx.size();
                    return wrap(res);',
                    plugin = "Rcpp")

# check to make sure mean1 is correct
mean1(1:100) == mean(1:100)

# test the sum functions with Rcpp and the base sum function
x <- 1:10000
# base R sum function
sum(x)

#check to make sure sum1, sum2, and sum3 are correct
sum1(x) == sum(x)
sum2(x) == sum(x)
sum3(x) == sum(x)

# test the speed of the two versions
library(rbenchmark)
res <- benchmark(sum(x), sum1(x), sum2(x), sum3(x),
                 columns = c("test", "replications", "elapsed",
                             "relative", "user.self", "sys.self"),
                 order = "relative", replications = 100)
print(res)
