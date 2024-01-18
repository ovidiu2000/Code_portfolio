def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if find_zero(s) and alpha(s) and charnum(s) and punctuation(s) and middle_num(s):
        return True
    else:
        return False


# All vanity plates must start with at least two letters
def alpha(plate):
    plate = plate.lower()[0:2]

    for i in plate:
        if i.isalpha():
            return True
        else:
            return False


# Vanity plates may contain a maximum of 6 characters (letters or numbers) and a minimum of 2 characters.
def charnum(plate):
    if 2 <= len(plate) <= 6:
        return True
    else:
        return False


# No periods, spaces, or punctuation marks are allowed
def punctuation(plate):
    for i in plate:
        if i.isalpha():
            continue
        elif i.isalnum():
            continue
        else:
            return False
    return True


def find_zero(plate):
    text = plate
    for i in text:
        if i.isalpha():
            continue
        else:
            if i == "0":
                return False
            else:
                return True
    return True


def middle_num(plate):
    string = plate
    s = len(string) - 1

    if string[s].isalpha():
        for i in range(s):
            if string[i].isalpha():
                continue
            else:
                return False
    return True


main()
