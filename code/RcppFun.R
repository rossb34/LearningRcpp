# examples of the Rcpp sugar functions

library(Rcpp)
library(inline)

Sys.setenv(R_ARCH="/x86_64")

# all
# Are all of the values ... ?
all_1 <- cxxfunction(signature(),
                    'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                     return all(y == 1);',
                    plugin = "Rcpp")
all_1()

all_2 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return all(y <= 10);',
                    plugin = "Rcpp")
all_2()

all_3 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return all(y + 10 > 10);',
                     plugin = "Rcpp")
all_3()

# any
# are any of the values ... ?
any_1 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return any(y == 1);',
                     plugin = "Rcpp")
any_1()

any_2 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return any(y * y > 1);',
                     plugin = "Rcpp")
any_2()

any_3 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return any(y + 5 == 1);',
                     plugin = "Rcpp")
any_3()

foo1 <- cxxfunction(signature(),
                     'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      return y = y + 5.0;',
                     plugin = "Rcpp")
foo1()

foo2 <- cxxfunction(signature(),
                    'NumericVector y = NumericVector::create(1,2,3,7,8,9);
                      NumericVector x = NumericVector::create(4,6,2,3,5,1);
                      NumericVector z = x + y;
                      return z;',
                     plugin = "Rcpp")
foo2()

diff_1 <- cxxfunction(signature(),
                    'NumericVector y(10);
                      NumericVector z(10);
                      for(int i = 0; i < y.size(); i++){
                        y[i] = i + 1.0;
                      }
                      z = diff(y);
                      return z;',
                    plugin = "Rcpp")
diff_1()