# TODO
# TODO

while True:
    try:
        height = int(input("Height: "))
        if(height > 0 and height < 9):
            break
    # height is a negatif number or not number a in 1 and 8 return height
    except:
        print("", end="")


for column in range(height):
    # space a column
    for space in range(height - column - 1):
        print(" ", end='')

    for has in range(column + 1):
        print("#", end='')
    # end two has spacee
    print(end="  ")
    # has loop and 2
    for has in range(column + 1):
        print("#", end='')
    # new line print space
    print()