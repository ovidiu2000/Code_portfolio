# Inport libraryes
from pyfiglet import Figlet
import sys
import random

# Declare variables and usage of the libraryes
figlet = Figlet()
font_list = figlet.getFonts()

# Set up the command line argument conditions
if len(sys.argv) == 1:
    # Ask for input from the user
    user_input = input("Input: ")

    # Mesure number of fonts
    font_count = len(font_list)

    # Randomise selection of font based on number
    rand_number = random.randint(0, font_count)

    # Set the font by indexing in the list with the random number
    figlet.setFont(font=font_list[rand_number])
    print(figlet.renderText(user_input))

# If the user wahnts a specific font it must provide the corect syntax
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--f"):
    user_font = sys.argv[2]

    # If the font is in the list use it to generate text
    if user_font in font_list:
        user_input = input("Input: ")
        figlet.setFont(font=user_font)
        print(figlet.renderText(user_input))
    else:
        sys.exit("Invalid usage")

else:
    sys.exit("Invalid usage")
