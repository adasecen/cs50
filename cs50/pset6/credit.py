# TODO
import sys

from cs50 import get_int

# we get input from user
while True:
    try:
        n = get_int("Number: ")
        if (n > 0):
            break
    except:
        print("", end="")
# we change iint to string
y = str(n)

# credit card number lenght
if len(y) != 16 and len(y) != 13 and len(y) != 15:
    print("INVALID", end="")
    print()

    sys.exit()

# declare a numbers
t1, t2, sum = 0, 0, 0

for i in range(len(y) - 2, -1, -2):

    multi = int(y[i]) * 2
    if (multi < 10):
        t1 = multi

    # if multiplication is two digit and we need a remainder
    else:
        t2 = multi % 10
        multi = t2 + 1

    sum += multi


sum1 = 0
# no multi total
for i in range(len(y) - 1, -1, -2):
    sum1 += int(y[i])

total = sum1 + sum

if (total % 10 == 0):
    first_numb = int(y[0])
    second_numb = int(y[1])

    if first_numb == 3 and second_numb == 4 or second_numb == 7:
        print("AMEX")
    elif first_numb == 5 and 1 <= second_numb <= 5:
        print("MASTERCARD")
    elif first_numb == 4:
        print("VISA")
    else:
        print("INVALID")