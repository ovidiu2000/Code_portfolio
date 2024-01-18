# Create "dict"
menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
price = 0.00
# Create while loop
while True:

# try block
    try:

# Get input from user
        item = input("Item: ")

# Lower case input and titlecase
        item = item.lower().title()

# Find the product in dict and calculate the total
        if item in menu:
            price = price + menu[item]
            print(f"Total: ${price:.2f}")
    except (KeyError, ValueError):
        pass
    except EOFError:
        print("\n")
        break


