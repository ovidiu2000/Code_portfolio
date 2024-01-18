# Import libraryes
import inflect

# Assign variable to library
p = inflect.engine()

# Creat list
name_list = []

# Create while loop
while True:
    # Implement try block
    try:
        # Ask for user input
        user_input = input("Input: ")

        # Append to the list the user input
        name_list.append(user_input)

    # Exception
    except EOFError:
        break

# Join list
join_list = p.join(name_list)

# Print
print(f"Adieu, adieu, to {join_list}")
