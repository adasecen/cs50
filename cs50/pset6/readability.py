# TODO
from cs50 import get_string
# we want to user a text
text = get_string("Text: ")

count1, count2, count3 = 0, 1, 0
# count a letters in text
for i in text:
    if (i >= "a" and i <= 'z') or (i >= "A" and i <= "Z"):
        count1 += 1

# count a space in text
for i in text:
    if i == " ":
        count2 += 1

# count a special characters in text
for i in text:
    if i == '!' or i == '.' or i == '?':
        count3 += 1


L = (count1 / count2 * 100)
S = (count3 / count2 * 100)

index = round(((0.0588 * L) - (0.296 * S) - 15.8))

if (index < 1):

    print("Before Grade 1")
    print()

elif (index >= 16):

    print("Grade 16+")
    print()

else:

    print(f"Grade ", {index})
    print()
