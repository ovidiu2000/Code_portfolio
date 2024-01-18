import sys


def main():

    # Expects one command-line argument and check for correct program name
    if len(sys.argv) == 1:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")

    # Make sure file is has .py in file name
    try:
        name = sys.argv[1]
        name = name.split(".")[1]
    except IndexError:
        sys.exit
    if name != "py":
        sys.exit("Not a Python file")

    # try to open file
    try:
        with open(sys.argv[1]) as file:
            lines = file.readlines()
    except FileNotFoundError:
        sys.exit("File does not exist")

    print(line_counter(lines))


def line_counter(lines):

    counter = 0

    for line in lines:
        if line.lstrip().startswith("#"):
            pass
        elif line.isspace():
            pass
        else:
            counter += 1

    return counter


if __name__ == "__main__":
    main()
