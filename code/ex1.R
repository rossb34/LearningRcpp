# initialize a vector of 5 elements initialized to 0
vec <- vector(mode="numeric", length=5)

# get the size of vec
vec_size <- length(vec)

cat("number of elements in vec:", vec_size, "\n")

# print the vector elements
cat(vec, "\n")

# assign values to the elements
# the index starts at 1 in R
vec[1] <- 6
vec[2] <- 2
vec[3] <- 5
vec[4] <- 1
vec[5] <- 8

# print the vector elements
cat(vec, "\n")

# add elements to the end of the vector
vec <- c(vec, 5)
vec <- c(vec, 7)
vec <- c(vec, 3)

cat(vec, "\n")

# delete the last element
vec <- head(vec, -1)

# print the vector elements
cat(vec, "\n")
