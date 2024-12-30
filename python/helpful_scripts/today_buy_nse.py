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
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQVm/ZF+1rzbaTAQAAPhf6Fg3VmK6hTSNeYGCxayP0CQ8cvDvbZMBZE+TMzEjcQu060dfU0SdFmSeRsQLHav8Bem66Nql+WDgNk7PgoF7zBhuth5JYYpfYpsuM/L4G+8FaD4cbEoGY2Jt5nyrnnnNl9+1iy/7sQ81x6OHmf3WuSaT6mD26KaplPnBEwPAqMGzcLO5O/fXFvTy4A6ig1Gk/f5nQbT6tkY+RsokLn5QA+h1OP6/SlvIcF5cCTGLLrSFtKuBdABO7s1iBemaDuq78m1s7FhAeOJWZ1iEZoIaBm3FUHtyfoBThgdXbZguATR5lKDYT5KWGyPm4BeqwyLz3jwpSW2Lj/nqwCSqKOWGSZM8D1dGchcD0C29ZID+WQRdJ9B/w3r4GzvkXFAuGZWGAxK5sPHY3aegySzB2WAp02GkiTOBS48bAh2oAJmOl9I0c/L3XkT/R2Qin1erqYGErfP3LXSvzCgRyaVryHN2fzPMa114tKT82QY/MRQ==~-1~-1~-1',
    'defaultLang': 'en',
    'nsit': 'xPDacGtzfBVtVaFOOi5kgyKn',
    'AKA_A2': 'A',
    'ak_bmsc': '3F71763279A2682C77087CE733AD7796~000000000000000000000000000000~YAAQVm/ZFxtizbaTAQAAdsj5FhrJb4Q05SK3S6Q4OCBCbBZkdih8qQVQyPciNihaxVi9VHhbmjSVv4gcSTsYCSX3tGgu1P8iuQ0p1DEvgFhCAOZd0r7Frm5pNrt2oVsXROlRM/x4elM23+Qxwqup0zAnwgXWKKTyjqwTHaiGpTnR90NW3T8CZqa/ZZa3ZFbYOaGfTjpuGMVDzbFUH7EJFlNIClLnxkbKXYW1yt6woEAzs3wt5xPaDqvS6AyZbKQZG1sre2nPtrIKBnoyIsf/BHgeVqDIUQkyguoZ5Oiuej/j6OND6t4RuNvH4bVY0S5lIg4h9lceass2FyEuz2EJ7M3bSSAw0B1Jq47ddvhpE8++YvbUDWwCpAra4dshC2G8P5nSL1fYP1d3NuFm8w==',
    'bm_sz': '0843D4C0393146C17DDF28ADCAE66FA6~YAAQVm/ZF3JrzbaTAQAAvhP6FhrEjqhfIdRUmIUIjploGk5UEqZBX8a3epsGA1T2kIC49W82081lOrXQ5pmjlw0NieEgE1EVTSWZ7l2HqN8u75INFK3ONMp95qZR+1PRS8hBOrsu5tUJEJIsOg7FlWPOFeAuTHv5GI+a1MQqQFATNtS2lvd4sZeTPyu9zoyhDsSRwZEATPPT6hKEp+cprEDOPC/w4Cn3qToDD5k6ReXoVomqbfRyl2klMNBKiO/mFLl4qrytTaKoUt8gytqvJaAcZddJCrylEZRJbOIeMZAYbyUu4pgsbuaQWMRIYe8oOSo53CCEsdXYDlH0KnkoT4zEEH7aOuPnfRAv8sMyezkb5HddjLLnO3V2XEqO8pbxJryA26esk2AfwtzNkoCB/RAiyhQ5SibTEBpN~4539204~3225650',
    'bm_sv': '2A530E1C7F059728253B6823DCA69DCE~YAAQVm/ZF3FrzbaTAQAAvhP6FhoPmGKIRDpKtAZ38YZmW/Lpo5FWrK9HHrRaydPA6tbcH8isFXPA41aXysZn5rfmmw/jH6DuO/9f/VnEMPdW3DyKqCdP/4EwnVV0sJmLj4hmdHgIW+lTJ/DHXaPX68mZoFWskJl2tyGN3hUcMMXN6PUlut5eZShp7L9XC1O4+us0fz8TbgWfqxaocdhXZOB7PlWiStjW+iJu5XNaI5DnOUXvqn2AXRF0gknGvRmUz1H4~1',
    'bm_mi': 'EE9077D6DF877D88FB0A0E9CE7F61630~YAAQVm/ZFxVozbaTAQAAzvf5Fhrp2HWrUX4Xm4p6KVoo6rnQwQtgpFoV7yxiRlL0sBhrYWw2uWYVhYexu/JEhlvou3XFVHf9zMTjbuVsaE7o56L+eGyJuB8NYQoi5jGTTjSIIsT8SjmBh7oru1p0kziGftXt/nPOfTv+/YOCfS8h6vq+xEFy9hlUQUZWa3bhhohVUqf9UUGfsiqqabLRnOaWw2N42/35TepIhikWfPh8RD9UK3PtGl5M4pXkFvx6BIGxM9Zb93yBk0ObZRCrW0wmsNlSpJ/obeJJ/ClFtMVLsEt41g0mTLDNWTaHN9W+A+eHbDXDgte+d0REnL3mrQ==~1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNTU1MjI3NCwiZXhwIjoxNzM1NTU5NDc0fQ.e7Vew8Rxi8Io8BqWsE_AeiCy1pKsO7z5T6_462MX4ww',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    # 'Cookie': '_abck=0F400126EE635FB8F03795F2E2C0EB01~0~YAAQVm/ZF+1rzbaTAQAAPhf6Fg3VmK6hTSNeYGCxayP0CQ8cvDvbZMBZE+TMzEjcQu060dfU0SdFmSeRsQLHav8Bem66Nql+WDgNk7PgoF7zBhuth5JYYpfYpsuM/L4G+8FaD4cbEoGY2Jt5nyrnnnNl9+1iy/7sQ81x6OHmf3WuSaT6mD26KaplPnBEwPAqMGzcLO5O/fXFvTy4A6ig1Gk/f5nQbT6tkY+RsokLn5QA+h1OP6/SlvIcF5cCTGLLrSFtKuBdABO7s1iBemaDuq78m1s7FhAeOJWZ1iEZoIaBm3FUHtyfoBThgdXbZguATR5lKDYT5KWGyPm4BeqwyLz3jwpSW2Lj/nqwCSqKOWGSZM8D1dGchcD0C29ZID+WQRdJ9B/w3r4GzvkXFAuGZWGAxK5sPHY3aegySzB2WAp02GkiTOBS48bAh2oAJmOl9I0c/L3XkT/R2Qin1erqYGErfP3LXSvzCgRyaVryHN2fzPMa114tKT82QY/MRQ==~-1~-1~-1; defaultLang=en; nsit=xPDacGtzfBVtVaFOOi5kgyKn; AKA_A2=A; ak_bmsc=3F71763279A2682C77087CE733AD7796~000000000000000000000000000000~YAAQVm/ZFxtizbaTAQAAdsj5FhrJb4Q05SK3S6Q4OCBCbBZkdih8qQVQyPciNihaxVi9VHhbmjSVv4gcSTsYCSX3tGgu1P8iuQ0p1DEvgFhCAOZd0r7Frm5pNrt2oVsXROlRM/x4elM23+Qxwqup0zAnwgXWKKTyjqwTHaiGpTnR90NW3T8CZqa/ZZa3ZFbYOaGfTjpuGMVDzbFUH7EJFlNIClLnxkbKXYW1yt6woEAzs3wt5xPaDqvS6AyZbKQZG1sre2nPtrIKBnoyIsf/BHgeVqDIUQkyguoZ5Oiuej/j6OND6t4RuNvH4bVY0S5lIg4h9lceass2FyEuz2EJ7M3bSSAw0B1Jq47ddvhpE8++YvbUDWwCpAra4dshC2G8P5nSL1fYP1d3NuFm8w==; bm_sz=0843D4C0393146C17DDF28ADCAE66FA6~YAAQVm/ZF3JrzbaTAQAAvhP6FhrEjqhfIdRUmIUIjploGk5UEqZBX8a3epsGA1T2kIC49W82081lOrXQ5pmjlw0NieEgE1EVTSWZ7l2HqN8u75INFK3ONMp95qZR+1PRS8hBOrsu5tUJEJIsOg7FlWPOFeAuTHv5GI+a1MQqQFATNtS2lvd4sZeTPyu9zoyhDsSRwZEATPPT6hKEp+cprEDOPC/w4Cn3qToDD5k6ReXoVomqbfRyl2klMNBKiO/mFLl4qrytTaKoUt8gytqvJaAcZddJCrylEZRJbOIeMZAYbyUu4pgsbuaQWMRIYe8oOSo53CCEsdXYDlH0KnkoT4zEEH7aOuPnfRAv8sMyezkb5HddjLLnO3V2XEqO8pbxJryA26esk2AfwtzNkoCB/RAiyhQ5SibTEBpN~4539204~3225650; bm_sv=2A530E1C7F059728253B6823DCA69DCE~YAAQVm/ZF3FrzbaTAQAAvhP6FhoPmGKIRDpKtAZ38YZmW/Lpo5FWrK9HHrRaydPA6tbcH8isFXPA41aXysZn5rfmmw/jH6DuO/9f/VnEMPdW3DyKqCdP/4EwnVV0sJmLj4hmdHgIW+lTJ/DHXaPX68mZoFWskJl2tyGN3hUcMMXN6PUlut5eZShp7L9XC1O4+us0fz8TbgWfqxaocdhXZOB7PlWiStjW+iJu5XNaI5DnOUXvqn2AXRF0gknGvRmUz1H4~1; bm_mi=EE9077D6DF877D88FB0A0E9CE7F61630~YAAQVm/ZFxVozbaTAQAAzvf5Fhrp2HWrUX4Xm4p6KVoo6rnQwQtgpFoV7yxiRlL0sBhrYWw2uWYVhYexu/JEhlvou3XFVHf9zMTjbuVsaE7o56L+eGyJuB8NYQoi5jGTTjSIIsT8SjmBh7oru1p0kziGftXt/nPOfTv+/YOCfS8h6vq+xEFy9hlUQUZWa3bhhohVUqf9UUGfsiqqabLRnOaWw2N42/35TepIhikWfPh8RD9UK3PtGl5M4pXkFvx6BIGxM9Zb93yBk0ObZRCrW0wmsNlSpJ/obeJJ/ClFtMVLsEt41g0mTLDNWTaHN9W+A+eHbDXDgte+d0REnL3mrQ==~1; nseQuoteSymbols=[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]; nseappid=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNTU1MjI3NCwiZXhwIjoxNzM1NTU5NDc0fQ.e7Vew8Rxi8Io8BqWsE_AeiCy1pKsO7z5T6_462MX4ww',
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
