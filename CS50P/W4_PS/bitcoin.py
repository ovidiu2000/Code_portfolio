import requests
import sys

# Implement command - line argument request from the user with the number of bitcoins
if len(sys.argv) != 2:
    sys.exit("Missing command-line argument")

try:
    bitcoin_quant = float(sys.argv[1])
except ValueError:
    sys.exit("Command-line argument is not a number")

try:
    request = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    json_obj = request.json()
    rate_float = json_obj["bpi"]["USD"]["rate_float"]
    amount = rate_float * bitcoin_quant

except (requests.RequestException, ValueError):
    sys.exit()


print(f"${amount:,.4f}")
