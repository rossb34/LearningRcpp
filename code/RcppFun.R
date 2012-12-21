# examples of the Rcpp sugar functions

library(Rcpp)
library(inline)

# this is required in Rstudio when using my mac
Sys.setenv(R_ARCH="/x86_64")

#### working with vectors ####
# These examples will consider the NumericVector class

# initialize a vector with 10 elements
# by default, all the elements are 0
vec1 <- cxxfunction(signature(),
                    'NumericVector x(10);
                     return x;',
                    plugin = "Rcpp")
vec1()

# initialize a vector with 10 elements
# each with an initial value of 5
vec2 <- cxxfunction(signature(),
                    'NumericVector x(10, 5.0);
                     return x;',
                    plugin = "Rcpp")
vec2()

# initialize a vector where the values are specified
vec3 <- cxxfunction(signature(),
                     'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                      return x;',
                    plugin = "Rcpp")
vec3()

#### OPERATORS ####

# The operators (+, -, *, /) work just like they do in R thanks
# to a little magic with Rcpp sugar.

# foo1: add a vector and a scalar
foo1 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     return x = x + 5.0;',
                    plugin = "Rcpp")
foo1()

# foo2: add 2 vectors of the same length
foo2 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     NumericVector y = NumericVector::create(4,6,2,3,5,1);
                     NumericVector z = x + y;
                     return z;',
                    plugin = "Rcpp")
foo2()

# foo3: subtract a vector and a scalar
foo3 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     return x = 5.0 - x;',
                    plugin = "Rcpp")
foo3()

# foo4: subtract 2 vectors of the same length
foo4 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     NumericVector y = NumericVector::create(4,6,2,3,5,1);
                     NumericVector z = x - y;
                     return z;',
                    plugin = "Rcpp")
foo4()

# foo5: multiply a vector and a scalar
foo5 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     return x = 3.5 * x;',
                    plugin = "Rcpp")
foo5()

# foo6: multiply 2 vectors of the same length
foo6 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     NumericVector y = NumericVector::create(4,6,2,3,5,1);
                     NumericVector z = x * y;
                     return z;',
                    plugin = "Rcpp")
foo6()

# foo7: divide a vector and a scalar
foo7 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     return x = x / 8.0;',
                    plugin = "Rcpp")
foo7()

# foo8: divide 2 vectors of the same length
foo8 <- cxxfunction(signature(),
                     'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                      NumericVector y = NumericVector::create(4,6,2,3,5,1);
                      NumericVector z = x / y;
                      return z;',
                    plugin = "Rcpp")
foo8()

# foo9: multiple expressions
foo9 <- cxxfunction(signature(),
                     'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                      NumericVector y = NumericVector::create(4,6,2,3,5,1);
                      return x = x + 5.0 * 2.0 - 1.0 / y;',
                    plugin = "Rcpp")
foo9()

#### all ####

# all: Are all of the values ... ?

# Are all of the values equal to 1?
all_1 <- cxxfunction(signature(),
                    'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                     return all(x == 1);',
                    plugin = "Rcpp")
all_1()

# Are all of the values less than or equal to 10?
all_2 <- cxxfunction(signature(),
                     'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                      return all(x <= 10);',
                    plugin = "Rcpp")
all_2()

# If I addd 10 to each element of the vector, are all of the values
# greater than 10?
all_3 <- cxxfunction(signature(),
                     'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                      return all(x + 10 > 10);',
                     plugin = "Rcpp")
all_3()

#### any ####

# any: Are any of the values ... ?

# Are any of the values equal to 1?
any_1 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                        return any(x == 1);',
                     plugin = "Rcpp")
any_1()

# If I multiply the vector x by itself (i.e. square it),
# are any of the values greater than 1?
any_2 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                        return any(x * x > 1);',
                      plugin = "Rcpp")
any_2()

# If I add 5 to the vector, are any of the values equal to 1?
any_3 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                        return any(x + 5 == 1);',
                      plugin = "Rcpp")
any_3()

#### clamp ####
#### complex ####

#### cumsum ####
# compute the cumulative sum of a vector
rcpp_cumsum <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,3,7,8,9);
                        NumericVector z = cumsum(x);
                        return z;',
                      plugin = "Rcpp")
rcpp_cumsum()

#### diff ####
# compute the difference between consecutive elements of a vector
rcpp_diff <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,7,3,9,8);
                        NumericVector z = diff(x);
                        return z;',
                      plugin = "Rcpp")
rcpp_diff()

#### duplicated ####

#### head ####
# display the first n elements of the vector
rcpp_head <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,7,3,9,8);
                        NumericVector z = head(x, 3);
                        return z;',
                      plugin = "Rcpp")
rcpp_head()


#### ifelse ####
# vectorized version of if, then, else
# if x is equal to 3, then 0, else x
rcpp_ifelse <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,7,3,9,8);
                        NumericVector z(6);
                        z = ifelse(x == 3, 0, x);
                        return z;',
                      plugin = "Rcpp")
rcpp_ifelse()

#### is_na ####
# combine with the function any() to to see if NA is in a vector
rcpp_is_na1 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,NA_REAL,3,9,8);
                        return any(is_na(x));',
                      plugin = "Rcpp")
rcpp_is_na1()

rcpp_is_na2 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,4,3,9,8);
                        return any(is_na(x));',
                      plugin = "Rcpp")
rcpp_is_na2()

#### match ####
# is x in the vector
# not working???
rcpp_match <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        return wrap(match(5.0, x));',
                      plugin = "Rcpp")
rcpp_match()

#### mean ####
# compute the mean of a vector
rcpp_mean <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = mean(x);
                        return wrap(z);',
                      plugin = "Rcpp")
rcpp_mean()

#### min ####
# return the minimum of a vector
rcpp_min <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,0.8,5,3,9,8);
                          double z = min(x);
                          return wrap(z);',
                      plugin = "Rcpp")
rcpp_min()

#### max ####
# return the maximum of a vector
rcpp_max <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                          double z = max(x);
                          return wrap(z);',
                      plugin = "Rcpp")
rcpp_max()

#### pmin ####
# compute the parallel minimum of a vector and a scalar
rcpp_pmin1 <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                          NumericVector z = pmin(3, x);
                          return z;',
                      plugin = "Rcpp")
rcpp_pmin1()

# compute the parallel minimum of two vectors
rcpp_pmin2 <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                          NumericVector y = NumericVector::create(4,1,5,6,2,3);
                          NumericVector z = pmin(y, x);
                          return z;',
                      plugin = "Rcpp")
rcpp_pmin2()

#### pmax ####
# compute the parallel maximum of a vector and a scalar
rcpp_pmax1 <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                          NumericVector z = pmax(3, x);
                          return z;',
                      plugin = "Rcpp")
rcpp_pmax1()

# compute the parallel maximum of two vectors
rcpp_pmax2 <- cxxfunction(signature(),
                         'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                          NumericVector y = NumericVector::create(4,1,5,6,2,3);
                          NumericVector z = pmax(y, x);
                          return z;',
                      plugin = "Rcpp")
rcpp_pmax2()

#### pow ####
# raise a value x to the power of n (i.e. pow(x, n) or x^n)
# return 2 to the power of 3
rcpp_pow1 <- cxxfunction(signature(),
                       'double x = 2.0;
                        double n = 3.0;
                        double z = pow(x, n);
                        return wrap(z);',
                      plugin = "Rcpp")
rcpp_pow1()

# raise each element of the vector x to the power of 3
rcpp_pow2 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        NumericVector z = pow(x, 3);
                        return z;',
                      plugin = "Rcpp")
rcpp_pow2()

#### rep_each ####

#### rep ####

#### rev ####

#### sd ####
# compute the standard deviation of a vector
rcpp_sd <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = sd(x);
                        return wrap(z);',
                      plugin = "Rcpp")
rcpp_sd()

#### self_match ####
#### seq_along ####

#### seq_len ####
# create a vector of a given length in which the values sequence from 1 to n
rcpp_seq_len <- cxxfunction(signature(),
                       'NumericVector x(10);
                        x = seq_len(10);
                        return x;',
                      plugin = "Rcpp")
rcpp_seq_len()

#### set_diff ####
#### sign ####

#### sum ####
# compute the sum of a vector
rcpp_sum <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = sum(x);
                        return wrap(z);',
                       plugin = "Rcpp")
rcpp_sum()

#### table ####

#### tail ####
# display the last n elements of the vector
rcpp_tail <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,7,3,9,8);
                        NumericVector z = tail(x, 3);
                        return z;',
                      plugin = "Rcpp")
rcpp_tail()

#### unique ####
# return a vector with only unique values (i.e. removes duplicates)
rcpp_unique1 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,3,7,3,3,1);
                        NumericVector z = unique(x);
                        return z;',
                      plugin = "Rcpp")
rcpp_unique1()

# count the number of unique values
rcpp_unique2 <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,3,7,3,3,1);
                        NumericVector z = unique(x);
                        return wrap(z.size());',
                      plugin = "Rcpp")
rcpp_unique2()

#### var ####
# compute the sample variance of a vector
rcpp_var <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = var(x);
                        return wrap(z);',
                       plugin = "Rcpp")
rcpp_var()

#### which_max ####
# returns the index where the maximum value occurs
rcpp_which_max <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = which_max(x);
                        return wrap(z);',
                      plugin = "Rcpp")
rcpp_which_max()

#### which_min ####
# returns the index where the minimum value occurs
rcpp_which_min <- cxxfunction(signature(),
                       'NumericVector x = NumericVector::create(1,2,5,3,9,8);
                        double z = which_min(x);
                        return wrap(z);',
                      plugin = "Rcpp")
rcpp_which_min()

#### lapply ####
#### mapply ####
#### sapply ####
