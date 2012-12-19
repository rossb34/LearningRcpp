# initialize a vector
# fill vec1 with 1 to 10
vec1 <- 1:10

# square each element in vec1
# multiply vec1 by itself
vec2 <- vec1 * vec1

# use the ^ operator to square each element in vec1
vec3 <- vec1^2

# function to add 3 to the argument
add3 <- function(x){
  x + 3
}

# pass vec1 as an argument to add3
add3(vec1)

# because the type of argument is not specified in R, I
# can also use this on a scalar
add3(5)