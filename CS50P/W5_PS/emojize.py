import emoji

user_input = input("Input: ")

x = emoji.emojize(user_input, language='alias')

print(x)
