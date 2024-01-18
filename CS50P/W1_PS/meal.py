def main():
# get input from user
    time = input("What time is it? ")

# use the convert() function
    convtime = convert(time)

# conditions
    if 7 <= convtime <= 8:
        print("breakfast time")
    elif 12 <= convtime <= 13:
        print("lunch time")
    elif 18 <= convtime <= 19:
        print("dinner time")



def convert(time):
# split the string
    hours, minutes = time.split(":")

# convert string to ints
    hours = int(hours)
    minutes = int(minutes)

# convert time float number
    convt = ((hours * 60) + minutes) / 60
    return convt


if __name__ == "__main__":
    main()


