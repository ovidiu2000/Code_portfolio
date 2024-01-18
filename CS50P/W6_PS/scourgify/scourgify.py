import csv
import sys


def main():

    # Expects 2 command-line arguments
    if len(sys.argv) < 3:
        print(len(sys.argv))
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3:
        print(len(sys.argv))
        sys.exit("Too many command-line arguments")

    # Create a list
    list = []

    # try to open an existing .csv file, read the rows, split the name in fist and last name, append to the list the data
    try:
        with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            for row in reader:
                full_name = row["name"]
                last, first = full_name.split(",")
                house = row["house"]
                list.append({"first": first.strip(), "last": last.strip(), "house": house})
    except FileNotFoundError:
        sys.exit(f"Could not read {sys.argv[1]}")

    # Write in to the new .csv file the data
    with open(sys.argv[2], "w") as doc:
        fields = ["first", "last", "house"]
        writer = csv.DictWriter(doc, fieldnames=fields)
        writer.writeheader()
        for row in list:
            writer.writerow(row)


if __name__ == "__main__":
    main()
