# Import Libraries
import sys
import random

# Create a while loop to check user input
while True:
    try:
        user_input = int(input("Level: "))
        if user_input > 0:
            break
        else:
            pass
    except ValueError:
        pass

random_number = random.randint(1,user_input)

while True:
    try:
        guess = int(input("Guess: "))

    except ValueError:
        continue

    if guess > random_number:
        print("Too large!")
        pass
    elif guess < random_number:
        print("Too small!")
        pass
    elif guess == random_number:
        print("Just right!")
        break




