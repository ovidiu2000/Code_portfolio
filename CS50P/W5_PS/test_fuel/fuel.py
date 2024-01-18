def main():

    fraction = input("Fraction: ")
    percentage = convert(fraction)
    print(gauge(percentage))


def convert(fraction):
    try:
        x, y = fraction.split("/")
        x, y = int(x), int(y)
    except ValueError:
        raise ValueError

    try:
        z = x / y
    except ZeroDivisionError:
        raise ZeroDivisionError
    if x > y:
        raise ValueError
    else:
        return int(round(z, 2) * 100)


def gauge(percentage):

    if percentage <= 1:
        return "E"
    elif percentage >= 99:
        return "F"
    else:
        return str(percentage) + "%"


if __name__ == "__main__":
    main()
