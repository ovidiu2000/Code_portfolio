# Promt the user for a date formatted like 9/8/1636 or September 8, 1636
list = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
]

# If the user’s input is not a valid date in either format, prompt the user again
# Implement try bloc
while True:
    try:
        date = input("Date: ")

        month1, day1, year1 = date.split("/")
        day1, month1, year1 = int(day1), int(month1), int(year1)

        if day1 <= 31 and month1 <= 12 and year1 <= 9999:
            print(f"{year1}-{month1:02}-{day1:02}")
            break
        else:
            pass

    except ValueError:
        try:
            month2, day2, year2 = date.split(" ")

            if day2.endswith(","):
                day2 = day2.removesuffix(",")
                day2, year2 = int(day2), int(year2)

                if month2 in list and day2 <= 31:
                    x = list.index(month2)
                    x += 1
                    print(f"{year2}-{x:02}-{day2:02}")
                    break
                else:
                    pass

            else:
                pass

        except ValueError:
            pass


# Output that same date in YYYY-MM-DD format

