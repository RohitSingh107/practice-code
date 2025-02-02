from icecream import ic
import yaml
from collections import defaultdict
import requests
import asyncio
import httpx
import sys
import math
from datetime import date

import requests


cookies = {
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQ3QVaaIdxpo6UAQAAtw6IxQ0itmK3AnPXQ1Bmci9roJ1GkD6BwjHyz5WCuzzoYVs9Xa9GKf+DyOv34xjEV5cf57SLcnPY2s7H3bH1N9mw/MlFjiNgulMYkGI7fbmEe2swRxguJsj0KSeFPVClR4XlNlcQtZxrldu6bcZ7FE/bpAwjen6zWMw1InFVzyqx8+Up0pwsdyCA5Avx2hjkAbAcBeIQBltMRMC8G7PDlrfPv3CB49mSircvGnbMBSL1W8XmLDvPBZsFIFePILnxrFcXq8kYIS3B6GvRUuIqepOPBncK2MSBaYULMIOgxRSLqRaV3psuNir78I8mNkKseXtGOLr+3fClDEVaHtIlvU1JJNGomLLHfMrZRgEUfO+pfC+N844uSDUcP3puFFCFu4TmDj0zhGrPbjhNIzlPhy+9Aam9tKUAS6KILFBC5zcdZW6issWtMWIxpqT6WvCzPZzPJgYbWShw3t6PYBrI+XMQpbEdPUVv912xQEZOAQ==~-1~-1~-1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
    'defaultLang': 'en',
    'nsit': 'G65usarMW7zGpThZwZUO-ofJ',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczODQ4MDgxNCwiZXhwIjoxNzM4NDg4MDE0fQ.yucRgdc7j0eLWFd2KXmjNHPGlfS4nCc36geO_Mbe44A',
    'AKA_A2': 'A',
    'ak_bmsc': 'E06BDB41860DB0FF8F50CB4976FB320C~000000000000000000000000000000~YAAQ3QVaaDlxpo6UAQAAxvuHxRrd7C2KO40wJbubFZIDOZErscxuJOGfJ3xRXOi1rc0gi8wSsFEuSmUUBz6pNqLzpiCbCikUYf3ymgQjSDMYVAdakvtoZXyzIcmLTr1tJCCjDzoLGhcqm6v97oknC7DCXiW7q7XQJrJNvJiHKTmhdvsmVmtrWrnES6JhnzmNp24WC2BcZ4RlQRD89oAQbBpx+3SwXazzZONZL2UXA5ntn+kchJ0mQV+TztPurH05R6NE2FsXY6Okqko/nq/T7hVfEsoeunHpytAxxPZX4HJ5aqVJ80bTkScpBAuNhDCujEph/FNkjUVyVtXZx1YBzKUE60czQtBxIDDNT1zLtbu+N6oCfaEOi5ml0wnQvHpv9alGBGjWgrcCQfPu',
    'bm_sz': 'F561D2E7CEBEFB9C541C3D019CF9AC00~YAAQ3QVaaIJxpo6UAQAAEA2IxRo8+5CFEcYXt+GT9xi27r17HUpUPc3t5sRPChP9qfde5oTJheI3SlrHjpNhHvMuay4DJQCS/m+/iNYP0jnWWSrYPZm3ZZ4ClBKGcXARbJvkLNS85lSmTLkf/5WekXDNssovwwsfZWJxEwOp4RQF52qg6RG7TiCcXQ/CA+Af+csddUxKhDrrtLzr1PCagVuPn5iwKhWCLbjfeHq3XCCHRUzJWc+qd0kQESuABGT2NRh/wk+LsaN2yKptHitd+ubL03htxiMxzaOJ73e7aTefidMIlB4Nw2JSHDKn2O6FKefVyfB+0O9s0flgY/s3Fn2kgTlowiREyZw/HtZg+Zz1DuKthaqL+fQrMZwxf2HzA7WmsL115dRDHmlF/ZAmp4fFfg==~4343346~4273204',
    'bm_sv': '78594D74C4429E4FE29FAB6CF973D7CF~YAAQ3QVaaIFxpo6UAQAAEA2IxRpo695TlZGhU4KdDHo5wu4Hy00/zswZQO9Eq1WQuXXRTHMrejcuRL7pPDj7gPTo5cs1/6nrvTxmB0cREEcmdanOEFP1/bCnlJzbXOjkP42NGR6X7fwgEpdNTN/nyfksUwGDQmyDTyEtqd7TWhGS1sWNZ8ZWt8BfbbEWN4FfJ+9HkBUJzdDXocwZqrEg3J54Wc9O/zQmbeDykXc5UeBZ+1rtEHUT12uD6iDujpUGNWo=~1',
    'bm_mi': '359A0F1D98AE7E2D59B1F300764DE73A~YAAQ3QVaaIBxpo6UAQAAEA2IxRrmRriAnXnGbmkSAEJGHRR5CdihPCG8msKdz8up1xYLBv5tpJ7mpNeoC/TgtaZkJ/mnBGEbg1wAyzp+cSWIBa/9f27xvvn9S7ptmJBVI1yzOYULYFRbWsBW/7LnEjxTPhikRO8YI5uSNgv6rN3yCVdbRit8xP4kl/0yvD7SstSBMGY0bik6lk51jWH+INBzDfsPBoDYnh8W+4PyacDL/R+yCMvJ1Zasmp7hb6xq/QSJIRPCF51PQ8pTMAM8sjFgYK3Js4wRJvxleyTDpcwi43hrtQC9vdwFFpakOvQb8hAPRg+f2e1jzVAZsG4xUqw=~1',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    # 'Cookie': '_abck=0F400126EE635FB8F03795F2E2C0EB01~0~YAAQDW/ZFwnWyZ2UAQAAfqDvwA0rypImRf4bFTgL9mNLWP8Xq/kjiheO2xPNbdXLmnmKzWvH+tIELtN8hcgFLhGUe+JNqlGwl5FcjDv0zN49tWIGyp4VUArZpHyfz59Tu/vlVypeLE5/8OPMbeYTj5BGLGnKNfJcrLuxfwEh6B7+jIMGub47x2BKdP8eoo8pEmhP7jsn2yiW+0bTi1HB/F2Q8uMUOZjjI0LaNqk9GHG6zktOW4l2XDsCGz+a88RPl+T2H1IXhczJjkCXMgzsHeeyMY/goIr0DuDtNOoZe5gEU9e0h7DfsVVJ1hCafZHDHTVCq+fdGmlNscHCRQYzMSL0mmUOxxFsCsbBwVWcyoGUvPDnWhn3IKq6U+mcOODHIqQhtd1VDsN7WHUNHFb7wJKxnlOuMXFNRxlMF7FdPraCK106OREGCky7TqPk33FFvxKdoNUtrVAMgfMYfUKtOJwyD6CNjEax5a5npqdelSMZ8j2BFw8kDDHBnQ/qaQ==~-1~-1~-1; defaultLang=en; nsit=mGsLCXku88ZrBluGKB5LaZdX; nseappid=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczODQwMzcxNiwiZXhwIjoxNzM4NDEwOTE2fQ.S5PJpb0PWfUFd7V88V83jHk4CudqFEnlqyCHNmYDOXg; AKA_A2=A; ak_bmsc=40B4FD20204E9857E04B21EFE8D9ACEC~000000000000000000000000000000~YAAQDW/ZFzLCyZ2UAQAAp0zuwBrs/1/2KPSsSLrT+iKCq6YWVOX8p2+H1E3m9p/Le3pgJwGafGdaNBwAdMwNCTEqi2nWP24VMLEK5Mc37+ttbMbTc6UVJrMf+gL153bn/AKDbQbBLiIKr1xo5dE9UoK722BVXPQgKELUN4sLkfwgvGrYu4/kLHJyYFooGnP07te9dZbzYjgYt8WdSl/scfu/q4WYU+YEh5oh2ZNVFt7Tkz1M0DMeNpx3mHbZYw9kmTDT8g7qe9KrnJ/8CNknDNPNjzwO65duNIKsQ+5iPq3DZcDzioClbrkmxCmNJVohAUahaI6G0jtVv43oYlANI21XMTVkMG6TiTNrX3hydfm8jiLNhNFLnTBpJGeke0GrhshcgDv+pRS19PAP; bm_sz=99E5F91901B7FED689FB5053B9E9B557~YAAQDW/ZF/fVyZ2UAQAAb57vwBqiKmHOjIXASoVSHNxIQZK5EesJvD2iyFZJqX5k7P8uunf0FfXVs2QYD9XhmAc4DAG61+hPo9I5lOZJVb6yhvDV5Qrqr2hvqZgBVM/snPuzDUsx/fsH9C/vdMIp07Ozt4kGVh5cEMM5ByTpo8ZEC5QfDAB3PHc1gI/gZWJIAXyylRY3sNbAzDSjzVR0ikWkfCWg15T29iQHS1nbEjot4dC6gC/1uBtbPxWDxNbGD4vDnsNfXx0zW/3Z+Xfaxf4/y0DJAAQBMVuhIcOlVg29e+OZ+DjI7hq3gbCRS4NrpTLE2zPJuQwuM63jvgtKAkhr2o1fd8pjZ6dvIW7Jr141zVPJMra9ZN2W8Tck6Gg5gga0kfxsJUl3F5vFTq8QvJA0+/hO~3618096~3684150; bm_sv=368819A78B933ECFC5F662CD54AE014F~YAAQDW/ZF/bVyZ2UAQAAb57vwBqexQrIVVT7S0qfas4Yocma5nk4zwKsWoqOAWMMZ/PRH1RWNheHQ3SM098RdfFckf6jKcy9NAtjl7GmLAieRSWHNNheklkVxay+4QhClCOXNyZBNP/dC3ab/9FaAeS9JxF+p0PwYX+AptnYoR38e+i77OMjYbkhK9BYzbs7KobF/rXikGbIlqAxhaoFUeFC+MAyxaE4jSqiSTHp8yr2Us7XA31j+J6tXwKTcsXcaZAd~1; nseQuoteSymbols=[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]; bm_mi=C9744A7505CB4C6971159CBA3967594E~YAAQDW/ZF/XVyZ2UAQAAb57vwBph6CycHPSaGARWONsxlIE6nFL8hruvZe3WujxAcvL0WbDmXCERgw+NQIRREidMUvnnHuZOEcT5VRubHtwzhtfGpdRHLmHlrsAAS1xsjywGTXZmLtf1XRcsM7gg72Of6O2Ho7CT/3BX0nHoKLczIWpZmvCPTwfqx80XYSxXJyevTTGQrUh/a4J7MaIKpJTNASYX+tkW4M9hTs+50TPYd237JOq94mJldl9Wb3fB4lwue5Z/mTX8loXbCUxfBguFuDsU+V0M4tmOxqg+zg6QFDkgEy0hbDHvmdM6+Uo0to4kTbfcmomwjLzJkpmJ9ZY=~1',
    'Sec-Fetch-Dest': 'empty',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-GPC': '1',
    'Pragma': 'no-cache',
    'Cache-Control': 'no-cache',
    # Requests doesn't support trailers
    # 'TE': 'trailers',
}

params = {
    'symbol': 'GOLDBEES',
}

# response = requests.get('https://www.nseindia.com/api/quote-equity', params=params, cookies=cookies, headers=headers)
async def fetch_etf_price(etf_symbol, cookies, headers):
    print(etf_symbol)
    url = 'https://www.nseindia.com/api/quote-equity'
    params = {'symbol': etf_symbol}
    timeout = httpx.Timeout(60.0)
    async with httpx.AsyncClient(timeout=timeout) as client:
        response = await client.get(url, params=params, cookies=cookies, headers=headers)
        response.raise_for_status()  # Raise an error for bad status codes
        etf_price_info = response.json()
        print(etf_symbol)
        return {
            'price': etf_price_info['priceInfo']['lastPrice'],
            'change': etf_price_info['priceInfo']['pChange']
        }

async def fetch_all_etf_prices(etf_symbols, cookies, headers):
    tasks = [fetch_etf_price(etf_symbol, cookies, headers) for etf_symbol in etf_symbols]
    results = await asyncio.gather(*tasks)
    return dict(zip(etf_symbols, results))


def trie():
    return defaultdict(trie)

async def main():

    with open("input.yaml", "r") as file:
        data = yaml.safe_load(file)

        etfs_prices_info = {}

        for etf_symbol in data['tickers'].keys():
            params = {'symbol' : etf_symbol}
            ic(etf_symbol)
            response = requests.get('https://www.nseindia.com/api/quote-equity', params=params, cookies=cookies, headers=headers)
            ic(response)
            etf_price_info =response.json()
            etfs_prices_info[etf_symbol] = {'price' : etf_price_info['priceInfo']['lastPrice'], 'change' : etf_price_info['priceInfo']['pChange']}

        # etf_symbols = list(data['tickers'].keys())
        # etfs_prices_info = await fetch_all_etf_prices(etf_symbols, cookies, headers)


        ic(etfs_prices_info)



        per_ticker = data['dail_limit'] / len(data['tickers'].keys())

        total_dip = 0

        today_amount_allowed = 0

        buys = {}

        total_expenditure = 0

        for t in data['tickers'].keys():
            if etfs_prices_info[t]['change'] < -0.1:
                total_dip += abs(data['tickers'][t]['weight'] * data['tickers'][t]['rebalance_factor'] * etfs_prices_info[t]['change'])

                today_amount_allowed += (data['tickers'][t]['weight'] * per_ticker)

        for t in data['tickers'].keys():
            if etfs_prices_info[t]['change'] < data['threshold']:
                dip = abs(data['tickers'][t]['weight'] * data['tickers'][t]['rebalance_factor'] * etfs_prices_info[t]['change'])

                alloted_amount = today_amount_allowed * dip / total_dip
                ideal_no = alloted_amount / etfs_prices_info[t]['price']

                # ic(t, dip, alloted_amount, ideal_no)

                if alloted_amount - (math.floor(ideal_no) * etfs_prices_info[t]['price']) < (math.ceil(ideal_no) * etfs_prices_info[t]['price']) - alloted_amount:
                    buys[t] = math.floor(ideal_no)
                else:
                    buys[t] = math.ceil(ideal_no)

                total_expenditure += buys[t] * etfs_prices_info[t]['price'] 

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



if __name__ == "__main__":
    asyncio.run(main())
