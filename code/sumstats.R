# initialize a vector
# fill vec1 with 1 to 9
vec1 <- 1:9

# shuffle the elements of vec1
vec1 <- sample(vec1)
cat(vec1, "\n")

# compute the mean of vec1
mean1 <- mean(vec1)
cat("The mean is:", mean1, "\n")

#compute the median of vec1
median1 <- median(vec1)
cat("The median is:", median1, "\n")

# minimum value of vec1
min1 <- min(vec1)

# location of the minimum value
min1.location <- which.min(vec1)

cat("Minimum:", min1, ";\n")
cat("at index:", min1.location, "\n")

# maximum value of vec1
max1 <- max(vec1)

# location of the maximum value
max1.location <- which.max(vec1)

cat("Maximum:", max1, ";\n")
cat("at index:", max1.location, "\n")

# I can also use the summary function
summary(vec1)