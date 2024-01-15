def main():
   string = input("Text here: ")
   print (convert(string))
   





def convert(string):
   string = string.replace(':)',"🙂")
   string = string.replace(':(', '🙁')
   return string

main()
