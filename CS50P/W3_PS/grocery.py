# Define variables
x = 0
number = 1
dict1 = {}
list1 = []

# Make a while loop
while True:

# Create a "try" block
    try:

# Promt the user for items
        text = input("")
# Upper the input
        text = text.upper()

# Update dictionary
        if text in dict1:
            x = dict1[text]
            x = int(x)
            x = x + 1
            dict1[text] = x
        else:
            dict1.update({text:number})
# When the user presses Ctrl + D exit and break - is not exiting  if i add morecode after
    except EOFError:
        break

# Create a list with the items
for j in dict1:
    list1.append(j)

# Sort the list
list1.sort()

# Print the items with quantity
for k in (list1):
    print(dict1[k],k)








# Use a for loop to iterate over the list and create a dict

# Make a if condition that checks if the item is already present

# Count the duplicate numbers

# Print the item with the number of times was entered



