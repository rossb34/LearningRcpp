# initialize a vector
# fill vec1 with 1 to 10
vec1 <- 1:10

# length of vec1
len1 <- length(vec1)

num <- 5

# count the elements of vec1 that are less than num
count1 <- length(vec1[vec1 < num])

# count the elements of vec1 that are less than or equal to num
count2 <- length(vec1[vec1 <= num])

# count the elements of vec1 that are greater than num
count3 <- length(vec1[vec1 > num])

# count the elements of vec1 that are greater than or equal to num
count4 <- length(vec1[vec1 >= num])

# count the elements of vec1 that are equal to num
count5 <- length(vec1[vec1 == num])

# count the elements of vec1 that are not equal to num
count6 <- length(vec1[vec1 != num])

# count the elements of vec1 that are even
count7 <- length(vec1[(vec1 %% 2) == 0])

# count the elements of vec1 that are odd
count8 <- length(vec1[(vec1 %% 2) != 0])

cat("There are: ", "\n")
cat(count1, "numbers less than", num, "\n")
cat(count2, "numbers less than or equal to", num, "\n")
cat(count3, "numbers greater than", num, "\n")
cat(count4, "numbers greater than or equal to", num, "\n")
cat(count5, "numbers equal to", num, "\n")
cat(count6, "numbers not equal to", num, "\n")
cat(count7, "even numbers", num, "\n")
cat(count8, "odd numbers", num, "\n")