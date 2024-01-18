text = input("Input: ")



for i in text:
    if i == "a" or i== "e" or i == "i" or i == "o" or i == "u":
        print("", end="")
    elif i == "A" or i== "E" or i == "E" or i == "O" or i == "U":
        print("", end="")
    else:
        print(i, end="")
print()

