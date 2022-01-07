import requests, json
from win10toast import ToastNotifier
import time
import math
toaster = ToastNotifier()

def oil_balance():
    balance_json = json.loads(requests.get("https://lightapi.eosamsterdam.net/api/balances/wax/viralclover1").content)['balances']

    for currency in balance_json:
        if(currency['contract'] == 'novarallytok' and currency['currency'] == 'SNAKOIL'):
            current_oil = int(currency['amount'])
    
    return current_oil

prev_oil = oil_balance()
f = open("payment.txt")
req_payment = math.ceil(float((f.read())))
f.close()
print(req_payment)

while req_payment!=0:
    current_oil = oil_balance()
    if(prev_oil!=current_oil):
        new_oil = current_oil-prev_oil
        req_payment=req_payment-new_oil
        toaster.show_toast("Payment  Recieved",f"{new_oil} has been recieved,{req_payment} is pending")
        print("should work")
        time.sleep(5)
        prev_oil = current_oil

f = open("payment.txt", "w")
f.write("0")
f.close()

# print(prev_oil)

