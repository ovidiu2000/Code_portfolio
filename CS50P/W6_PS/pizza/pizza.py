import sys

import csv

from tabulate import tabulate


def main():

    # Expects one command-line argument and check for correct program name
    if len(sys.argv) == 1:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")

    # Make sure file is has .csv in file name
    try:
        name = sys.argv[1]
        name = name.split(".")[1]
    except IndexError:
        sys.exit
    if name != "csv":
        sys.exit("Not a CSV file")

    # try to open file
    list = []
    try:
        with open(sys.argv[1]) as csvfile:
            table = csv.reader(csvfile)
            for row in table:
                list.append(row)

    except FileNotFoundError:
        sys.exit("File does not exist")

    print(tabulate(list, headers="firstrow", tablefmt="grid"))


if __name__ == "__main__":
    main()
