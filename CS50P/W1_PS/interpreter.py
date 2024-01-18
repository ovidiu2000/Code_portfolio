string = input("Expression: ")

x, y, z = string.strip().split(" ")

x = int(x)
z = int(z)

match y:
    case "+":
        print(float(x + z))
    case "-":
        print(float(x - z))
    case "/":
        print(float(x / z))
    case "*":
        print(float(x * z))












