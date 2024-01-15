
# Define the while loop
while True:
# the "try" block
    try:
# Get input from the user
        text = input("Fraction: ")
# Split the text
        num1, num2 = text.split("/")
# Convert to int
        num1 = int(num1)
        num2 = int(num2)
        if num1 > num2:
            continue
# Split
        num3 = num1 / num2
# Getting the float * 100
        num3 = round(num3, 2) * 100
# Condifition for 1% and 99%
        if num3 <= 1:
            print("E")
            break
        elif num3 >= 99:
            print("F")
            break
        else:
            print(int(num3), "%", sep="")
            break
    except (ValueError, ZeroDivisionError):
        pass









