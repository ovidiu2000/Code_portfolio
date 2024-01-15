import random


def main():
    # Get variable level vrom get_level() function
    level = get_level()
    generate_problems(level)


def get_level():
    # Define a while loop to promt the user for input
    while True:
        # Try block for input
        try:
            level = int(input("Level: "))

            # Condition : if is smaller than 1 and bigger than 3 pass, else return level
            if level < 1 or level > 3:
                print("EEE")
                pass
            else:
                return level

        # Exception
        except ValueError:
            print("EEE")
            pass


def generate_integer(level):
    if level == 1:
        return random.randint(0, 9)
    elif level == 2:
        return random.randint(10, 99)
    elif level == 3:
        return random.randint(100, 999)
    else:
        raise ValueError


def generate_problems(level):
    # Declare variables
    X, Y = 0, 0
    calc = 0
    user_correct = 0
    user_wrong = 0
    problem_count = 0

    # Create a while loop
    while problem_count < 10:
        # Asign random numbers to X, Y
        X = generate_integer(level)
        Y = generate_integer(level)

        # Calculate sum of X and Y
        calc = X + Y

        # Create a a while loop for the try bloc for user input
        user_wrong = 0
        while user_wrong < 3:
            try:
                result = int(input(f"{X} + {Y} = "))
                if result == calc:
                    user_correct += 1
                    break
                else:
                    print("EEE")
                    user_wrong += 1

            except ValueError:
                print("EEE")
                pass

        problem_count += 1
        if user_wrong == 3:
            print(f"{X} + {Y} = {calc}")

    print(f"Score: {user_correct}")


if __name__ == "__main__":
    main()
