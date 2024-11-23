import yaml
import sys
# import yfinance as yf
from datetime import date, timedelta
from pprint import pprint
import math
from icecream import ic

with open("input.yaml", "r") as file:
    data = yaml.safe_load(file)


#
# tickers_string = " ".join(data['tickers'].keys())
# tickers = yf.Tickers(tickers_string)

# for t in data['tickers'].keys():
#     price = tickers.tickers[t].history(period = "1d")['Close'].iloc[0]
#     days_factor = (date.today() - data['tickers'][t]['last_buy']).days

per_ticker = data['dail_limit'] / len(data['tickers'].keys())

total_dip = 0

today_amount_allowed = 0

buys = {}

total_expenditure = 0

for t in data['tickers'].keys():
    if data['tickers'][t]['dip'] < -0.1:
        total_dip += abs(data['tickers'][t]['weight'] * data['tickers'][t]['rebalance_factor'] * data['tickers'][t]['dip'])

        today_amount_allowed += (data['tickers'][t]['weight'] * per_ticker)

# ic(today_amount_allowed)
# ic(total_dip)

for t in data['tickers'].keys():
    if data['tickers'][t]['dip'] < data['threshold']:
        dip = abs(data['tickers'][t]['weight'] * data['tickers'][t]['rebalance_factor'] * data['tickers'][t]['dip'])

        alloted_amount = today_amount_allowed * dip / total_dip
        ideal_no = alloted_amount / data['tickers'][t]['price']

        # ic(t, dip, alloted_amount, ideal_no)

        if alloted_amount - (math.floor(ideal_no) * data['tickers'][t]['price']) < (math.ceil(ideal_no) * data['tickers'][t]['price']) - alloted_amount:
            buys[t] = math.floor(ideal_no)
        else:
            buys[t] = math.ceil(ideal_no)

        total_expenditure += buys[t] * data['tickers'][t]['price'] 




ic(buys)
ic("Total Expenditure: ", total_expenditure)

if "rw" in sys.argv:
    for t in data['tickers'].keys():
        if t in buys:
            data['tickers'][t]['weight'] = 1
        else:
            data['tickers'][t]['weight'] += 1

    data['last_updated'] = date.today() 

    with open('input.yaml', 'w') as f:
        yaml.dump(data, f)

