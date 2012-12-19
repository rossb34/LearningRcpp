# initialize a vector
# fill vec1 with 1 to 10
vec1 <- 1:10

# compute the sum of vec1
num1 <- sum(vec1)

# compute the cumulative sum of vec1
vec2 <- cumsum(vec1)

# compute the sum of squares of vec1
num2 <- sum(vec1 * vec1)

# compute the sum of squares using the inner product
# this actually makes num3 a 1x1 matrix
num3 <- vec1 %*% vec1