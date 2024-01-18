text = input("camelCase: ")


for i in text:
    if i.islower():
        print(i, end="")
    else:
        print("_",i.lower(), sep="", end="")
print()

