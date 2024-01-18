def main():

    word = input("Input: ")
    print(shorten(word))


def shorten(word):
    txt = word
    text = word
    for i in text:
        if i == "a" or i== "e" or i == "i" or i == "o" or i == "u":
            txt = text.replace(i,"")
        elif i == "A" or i== "E" or i == "I" or i == "O" or i == "U":
            txt = text.replace(i,"")

    return txt



if __name__ == "__main__":
    main()
