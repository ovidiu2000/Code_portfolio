
amount = 50
while True:
    print(f"Amount Due: {amount}")
    coin = int(input("Insert coin: "))
    if coin == 25 or coin == 10 or coin == 5:
        amount -= coin



    if amount == 0:
        print ("Change Owed: 0")
        break

    elif amount < 0:
        amount = amount * (-1)
        print(f"Change Owed: {amount}")
        break





