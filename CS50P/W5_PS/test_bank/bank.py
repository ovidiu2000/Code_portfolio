def main():

    greeting = input ("Greeting: ")

    print(value(greeting))



def value(greeting):

    text = greeting.strip().lower()

    if text.startswith("hello"):
        return 0
    elif text.startswith("h"):
        return 20
    else:
        return 100


if __name__ == "__main__":
    main()
