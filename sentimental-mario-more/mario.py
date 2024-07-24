from cs50 import get_int

height = 0

# check for height to be between 1 and 8
while height < 1 or height > 8:
    height = get_int("Enter Height: ")
    # This loop is to iterate rows
for i in range(1, height + 1):
    # This loop is to get spaces before the hashes
    for j in range(height - i):
        print(" ", end="")
    # This loop is to iterate hashes and Printing hashes of left side of pyramid
    for k in range(i):
        print("#", end="")
    #  Printing two whitespaces between sides of pyramid
    print("  ", end="")
    for l in range(i):
        # This loop is to iterate hashes and Printing hashes of right side of pyramid
        print("#", end="")
    print()
