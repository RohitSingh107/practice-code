from icecream import ic
import yaml
from collections import defaultdict
import requests
import asyncio
import httpx
import sys
import math
from datetime import date

cookies = {
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQ5wVaaBPe3EOTAQAA9ES8WQy7udJZGjiMTTWNjurmw4DzUann4vFJAmjwgnZEY8jGoKTCT2m6NeY0c6BU/BWGBXXdxeOspnOJeWh5xL/g+8A1pizMBuPwrvDByhmuCuHpiKiGdOs+CTvYW8gTEaU8aeoymtQkc5+ClJuS++9x8xmtSSeuejY5J4rJ4c6HY/+zYPdqZd8CGu4nJIeTO7KAuNP/t+RtTH0B1JJItJUprP/Kw10wNb+2WH5mtyyTjPSQt80jS8tAekFrQSAI6OgCbLExi2adqPWp/PKFaFy0/04STuS1920RGc+6M9aKtc2h7HB2rkL+xet8s8IZiNYVT9cVcWfXyG/Hgx5kD+JCTJshI78Gl8LlUBjCDyo+drDu+ZYSDVRnRuJKPYgzEufUkRJOhTYjiyxTwcMg793VTZqq95hjtKK1y/MDx/gI1LWcCkXVWq3k60gP/qRjqgiqqv6Xl8SzOMJbuNbyznjmeBFrWt6n291bBXMl2A==~-1~-1~-1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":null,"type":"equity"}]',
    'defaultLang': 'en',
    'nsit': 'iM9f30KwrtNcVSIRw5zYSDX_',
    'AKA_A2': 'A',
    'ak_bmsc': '4AF145588CD9389BA83223DC299D5F1E~000000000000000000000000000000~YAAQ5wVaaALe3EOTAQAAWUK8WRm923ujXDCx1zIlcWLc4KN/+GX9T8hsuFT/JdB3WxU5cBcnaJ2ovp+3xcC2z6evkSh6HoftUgDLu2lqsfP8NaKI/Jql0x94UT1yhxMGDtofnGw2t27BecxwIFpLaXsNUd+9Kc7/nEU+y8CNwkbVmWjyzEVAg/b/6YGpM0HtmGoasq6DFWpuiSIdKeeVrbuOM92dYNS3YUWdB8mlitaVKUApGUNBZP1GHsiO4O5JBZO/TEXkzW0rmBrUnj+q0zL5Y3zeRjfyVrETkFtKkgSFl4LQaxEB/O0iTX4+tjdXXh8xWcd1MooAQv/XDShN2pfnFSn0caqZDKvhYj5EB5Vn0AgZjAk+sWIyM/pEJm7jhbG7LnhyNVtrdmQe+g==',
    'bm_sz': 'C2CCB86356EA85524E71729DC3CE402D~YAAQ5wVaaFDg3EOTAQAAerK8WRkGqObLDyozjh4o84pLg2pHw8j2EPxIHHKTnWRRNaD7NX+0Qv8wAvA1FrwEmM+/bQf+6DgWoXAN8gTz2S77bmgIfOmLNQ68S1rLfUKFXEP5GzCubW2uq9e+9jRpMhF/c0DBKtcXFU99y5c04d5xPIpmdp4GQ8zLL2/L1iWg2FSUHW7D4pJ9zIk3XZPo00cHHrfa6zEJ/C7i3Lp+Ph7U12wmgbCZyxa+a0A+UajiQLwf/vmWgV3Izgix4FhxxbsOmTt+i04WTppDRP586M/sP7T2jmR1BSj2by8iftDKmcU7SUyWOE/fUyQlGL2FkzhHUpVxwNKTOnuZDD9Bc+Oj9nl1YQUD59pfRKPlHSJez6nY/SjOrT6ASdqVVmg3Ef+Ji3owOV9UE4fzkQ==~4408884~3487029',
    'bm_sv': '27D546B3D001FDB8D892B337CD24DA89~YAAQ5wVaaE/g3EOTAQAAerK8WRnHpAOIIjaZnCpwqneNgPiOZAxLdf9s8frGR0vlFqnOQ4hwLLqOtvWMz3WU2AVFeH4noWAXQNO9szQOx0rr5DoHickbAPXmJbYqwwO5MAWq+XtlX0x4IxiyCtmIGydrEgwsI3xJo74hFklkTFdFAr2pXuPZegJfzzNEgtbtsLMcp5RVBJzuKf2LmqKI3j0G2jHDN+n5kFVuH5HlQ5DpaX/sS+EKUKCmf+/uD3My6yQ3~1',
    'bm_mi': '9A1A2B988E4ABD65ED37968E52157A6D~YAAQ5wVaaDzf3EOTAQAA+Ia8WRkdnsTtwzSoC0ahQc4PUBNj8bRV85yLiueO9kT0930P/6CYmOH4aGvz4V8iV2ZrykUOvXKjZYczUL3hAXJOIEvV8poEWih07LmT2vmcwimVyMw07HrimPbFY4Di82iSCqLoNuIf/AKjYLMAcEKFaOSzHzcZvO47q5ZP5XhUp+4EB6AkaA2WMgz4YlRVAZ8iC3v7ZtFIjhCwIZRTUwD3j/MnPzj43cKi9Jmy9eu04toQHmpfHTN1eeM6jFkFpe/50mUSXaTBGpqpCBMfU/t0c3tkr/vzAtdntvooDXNEFMeAjl718C5LJ3ELl6sjMPo=~1',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczMjM3NzM1OCwiZXhwIjoxNzMyMzg0NTU4fQ.q7W6uNzL7sRIRZwh0MnlNC4GAe5KSS1Slo03PkaIe60',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    'Sec-Fetch-Dest': 'empty',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-GPC': '1',
    # Requests doesn't support trailers
    # 'TE': 'trailers',
}

# params = {
#     'symbol': 'GOLDBEES',
# }

# response = requests.get('https://www.nseindia.com/api/quote-equity', params=params, cookies=cookies, headers=headers)
# print(response.json())


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
            response = requests.get('https://www.nseindia.com/api/quote-equity', params=params, cookies=cookies, headers=headers)
            etf_price_info =response.json()
            etfs_prices_info[etf_symbol] = {'price' : etf_price_info['priceInfo']['lastPrice'], 'change' : etf_price_info['priceInfo']['pChange']}

        # # etf_symbols = list(data['tickers'].keys())
        # # etfs_prices_info = await fetch_all_etf_prices(etf_symbols, cookies, headers)
        #
        #
        # ic(etfs_prices_info)



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
