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
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQDW/ZF2x6wEmUAQAAgdekTw3i7yQNEGG3gWfa7ceSoVnJ7Ipc0Opdi1WczqdxGT7LEGVxfV2LZEFJV/nDPzpCvVCMRJgGPHjk50MqaF4ul15iIC8h+5lSsOvcRNztURxt1tAKxHacV54YY5fmJdfD0SX1rOK0nIi9KcOmN5+bfrDtocs2Ny3lkkkv0mldphUdfFiA5w9o3K9Vmbx4BSfW/Zj8xJJc7+DhAOrV9l9W++/Bmt1nWgQf8tbLc5y3M9KPqJhfCJZXgLeYniR+pWr1iFxTOZ+bKo7yfaQZQXG6xtvXWvPn5ZIh/FRM/O/C56plSokqLQ0tVC0B1YumNGLR1A+q3a7S0ENEyBOIqZh+lXuvoS98eaduRJDOgdw7GMEv3fQvXHwgik+ebJLtbgsoHLSK/QPJ+YJvXClYkcL+f2bGlF7jvscQMur9D1K7yGgknr4Gkrl068KMZ0cr72ogH7ADie54J1xJNz7CvRA10oNcC5w8ZHhpfrqy9A==~-1~-1~-1',
    'defaultLang': 'en',
    'nsit': 'R3S2Q9oo7_9D7LPBe9NTKuo7',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNjUwMjk4OSwiZXhwIjoxNzM2NTEwMTg5fQ.5n7cNDnkls_PAicQeCL5qs8PQ1jEZppN-fLreqFE2_U',
    'AKA_A2': 'A',
    'ak_bmsc': '42F253AA14B565143A18F9B8F4398B01~000000000000000000000000000000~YAAQDW/ZF714wEmUAQAA+bykTxqIHyXeuqJCwX+iOJoT/6Vf8kjZqrEBWRu6iWbgiMA1Y7SH238yGkOlhb1PvlUJzdO8K6W5oozyKx4CzPugWTQGPo9zfnrilyHsCppz8+GOQS035/zrlT9G2vDzB0Dr3CoBpmcZwbwKMNqDSvrunowIGapq2Ep5GnYMKz9gPM/JsbhdRIcefnlTnjPikXv5WjY1W+cHmXKlk2DhwoV/Zq9PV3tHbSJWQjthhSahnOol4NfdrAjF48ewYSf4VmB4ZMeBLG1KXmjZql6iUOT2wNbl2ZwrC7VwKhwEMg1vgb1ASSvgHRHHDENND6TsctslO7ZlCMGEkbKuHnVCO83qF16DmahagaZaSiAnhUt4XSDxodCW2BCmb9wtfQ==',
    'bm_sz': '41DAE2607B1F7D731B6261C54C71162E~YAAQDW/ZF0J6wEmUAQAAcNSkTxrOu9IuH4g/crBNMGunONaPEIN2Tk7f4Y6DHCy4Z3Q7FPCDzdjFFP9vuQsODbfDZBWIMRjUfSuVYRht1GwNa/jCcoVqNXWqo+RRLVsBirCNEbf2KOotBUVQISiDtqiFUFxUbwhujl0dJ64cXknq8KZSZLfKEAXGr5IGTFeMm23q3c7Pl5sHzTQRT0rRVFPQAFi8WDvtmQ+tqYxTuSy/mrEU37qu3Gb5JN2IgfmPzCj3RtMDbKoX5PgT1SspIFlSpKOxES25328uTELDwmSivPCl+8ftCvXRRJ2DFd8Azk1ImKbruox7GQZcNW8XuxDiaV8PTwZPP67hxUdOpjbFBUhdY8uuXsgxyHWwOPaW3px3DFTgLj2P1z87PpR4wtCzqqs=~4408376~3359798',
    'bm_sv': '7FFB0F2656BC6DDB9607E3A57B5CECF9~YAAQDW/ZF0F6wEmUAQAAcNSkTxrxotUEyPk8cufRl4RHUpjOkpef8DiHIgp78iDR6OBYOinO57Yr59NO81/yQF9pVA/kCdfk6S2NqxbVnlP46Wh3d7e4ook9ZafzMAaWvZDhWIZ9DFPdHoEshEt/VgH055FhEms3k3RfbuxY5XpNcUq/qJP6yfLOLMnil5YPV1Z0cf91sosw+i88d54I8s2/uR8/guyN0E35AHlm3xDo1aQFQ/TDR44Vtf3wccO40X4=~1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
    'bm_mi': '29AAD818F9FCC9DBB3127DE20A91B909~YAAQDW/ZF0B6wEmUAQAAcNSkTxoCXgvAItevU3PZ+FxnDWlwBbptZNWpBf2ewl15TC4wdegoefXtsFE5Y0gakt2UQvVgHcRscsEQP5OZMJBQQc40dlJb7eerab4BuF4anyTdeLNWb3fsuLd5pUTX6ZPosxyjXYt+EU7vyqMeMRhucOTJggfaEdxkEfdXRBgDCqukU6NVnnUSK9lAWWvqQAov55NlcVDmpfhs+kkQCguuQadSMphkqSIwMbIGDDxqMfpm9fqUDgniUdexEzVI0hQtFzjC6mBiqOtfWwM0BXctGFVYf18w7YrpVIUO1qXAenC8M7X3N9errl/mu9LjYA==~1',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    # 'Cookie': '_abck=0F400126EE635FB8F03795F2E2C0EB01~0~YAAQDW/ZF2x6wEmUAQAAgdekTw3i7yQNEGG3gWfa7ceSoVnJ7Ipc0Opdi1WczqdxGT7LEGVxfV2LZEFJV/nDPzpCvVCMRJgGPHjk50MqaF4ul15iIC8h+5lSsOvcRNztURxt1tAKxHacV54YY5fmJdfD0SX1rOK0nIi9KcOmN5+bfrDtocs2Ny3lkkkv0mldphUdfFiA5w9o3K9Vmbx4BSfW/Zj8xJJc7+DhAOrV9l9W++/Bmt1nWgQf8tbLc5y3M9KPqJhfCJZXgLeYniR+pWr1iFxTOZ+bKo7yfaQZQXG6xtvXWvPn5ZIh/FRM/O/C56plSokqLQ0tVC0B1YumNGLR1A+q3a7S0ENEyBOIqZh+lXuvoS98eaduRJDOgdw7GMEv3fQvXHwgik+ebJLtbgsoHLSK/QPJ+YJvXClYkcL+f2bGlF7jvscQMur9D1K7yGgknr4Gkrl068KMZ0cr72ogH7ADie54J1xJNz7CvRA10oNcC5w8ZHhpfrqy9A==~-1~-1~-1; defaultLang=en; nsit=R3S2Q9oo7_9D7LPBe9NTKuo7; nseappid=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNjUwMjk4OSwiZXhwIjoxNzM2NTEwMTg5fQ.5n7cNDnkls_PAicQeCL5qs8PQ1jEZppN-fLreqFE2_U; AKA_A2=A; ak_bmsc=42F253AA14B565143A18F9B8F4398B01~000000000000000000000000000000~YAAQDW/ZF714wEmUAQAA+bykTxqIHyXeuqJCwX+iOJoT/6Vf8kjZqrEBWRu6iWbgiMA1Y7SH238yGkOlhb1PvlUJzdO8K6W5oozyKx4CzPugWTQGPo9zfnrilyHsCppz8+GOQS035/zrlT9G2vDzB0Dr3CoBpmcZwbwKMNqDSvrunowIGapq2Ep5GnYMKz9gPM/JsbhdRIcefnlTnjPikXv5WjY1W+cHmXKlk2DhwoV/Zq9PV3tHbSJWQjthhSahnOol4NfdrAjF48ewYSf4VmB4ZMeBLG1KXmjZql6iUOT2wNbl2ZwrC7VwKhwEMg1vgb1ASSvgHRHHDENND6TsctslO7ZlCMGEkbKuHnVCO83qF16DmahagaZaSiAnhUt4XSDxodCW2BCmb9wtfQ==; bm_sz=41DAE2607B1F7D731B6261C54C71162E~YAAQDW/ZF0J6wEmUAQAAcNSkTxrOu9IuH4g/crBNMGunONaPEIN2Tk7f4Y6DHCy4Z3Q7FPCDzdjFFP9vuQsODbfDZBWIMRjUfSuVYRht1GwNa/jCcoVqNXWqo+RRLVsBirCNEbf2KOotBUVQISiDtqiFUFxUbwhujl0dJ64cXknq8KZSZLfKEAXGr5IGTFeMm23q3c7Pl5sHzTQRT0rRVFPQAFi8WDvtmQ+tqYxTuSy/mrEU37qu3Gb5JN2IgfmPzCj3RtMDbKoX5PgT1SspIFlSpKOxES25328uTELDwmSivPCl+8ftCvXRRJ2DFd8Azk1ImKbruox7GQZcNW8XuxDiaV8PTwZPP67hxUdOpjbFBUhdY8uuXsgxyHWwOPaW3px3DFTgLj2P1z87PpR4wtCzqqs=~4408376~3359798; bm_sv=7FFB0F2656BC6DDB9607E3A57B5CECF9~YAAQDW/ZF0F6wEmUAQAAcNSkTxrxotUEyPk8cufRl4RHUpjOkpef8DiHIgp78iDR6OBYOinO57Yr59NO81/yQF9pVA/kCdfk6S2NqxbVnlP46Wh3d7e4ook9ZafzMAaWvZDhWIZ9DFPdHoEshEt/VgH055FhEms3k3RfbuxY5XpNcUq/qJP6yfLOLMnil5YPV1Z0cf91sosw+i88d54I8s2/uR8/guyN0E35AHlm3xDo1aQFQ/TDR44Vtf3wccO40X4=~1; nseQuoteSymbols=[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]; bm_mi=29AAD818F9FCC9DBB3127DE20A91B909~YAAQDW/ZF0B6wEmUAQAAcNSkTxoCXgvAItevU3PZ+FxnDWlwBbptZNWpBf2ewl15TC4wdegoefXtsFE5Y0gakt2UQvVgHcRscsEQP5OZMJBQQc40dlJb7eerab4BuF4anyTdeLNWb3fsuLd5pUTX6ZPosxyjXYt+EU7vyqMeMRhucOTJggfaEdxkEfdXRBgDCqukU6NVnnUSK9lAWWvqQAov55NlcVDmpfhs+kkQCguuQadSMphkqSIwMbIGDDxqMfpm9fqUDgniUdexEzVI0hQtFzjC6mBiqOtfWwM0BXctGFVYf18w7YrpVIUO1qXAenC8M7X3N9errl/mu9LjYA==~1',
    'Sec-Fetch-Dest': 'empty',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-GPC': '1',
    'Pragma': 'no-cache',
    'Cache-Control': 'no-cache',
    # Requests doesn't support trailers
    # 'TE': 'trailers',
}

# params = {
#     'symbol': 'GOLDBEES',
# }
#
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
