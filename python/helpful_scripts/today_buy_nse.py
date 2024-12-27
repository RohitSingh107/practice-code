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
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQDW/ZF09zOZuTAQAAQVnv8g1K5ZOXCV8wkxz/qX3l67sDLLstGJBpyTeFe3wh/glWp0iscksQ1na2fB8pfW9Vcm+ez7TZfShOIbLpTOCZIOX0/3EF8KJYqfMwyu7gMjiyCsoUI1uVCnbAaIIFX/PiD+PulJ82obYDwX/f3FKrhBeaGVA6zQwGnom60RIWx1+YmrHaOXgXsZWeiQHxD39ZUkAru/zJ1Cg+U8A8IV6mwbojt+h3Fjo4vNgrUfHXkdCqGF4TWAR7cHfZgiVS8TOn+553skcv1wMocJ3LDCssRTqapxiOQq1mL061SWMQ3DXNIecyF8TstJNVgtFhaiqrTp8r4lXb1e3yaWrED1LIXSwNkAKTz3D8X0fjTQb/YcPaXvFdn6fz82jGQbFkg3DdGAb5mPWsTs/n33mrKng6G+r7/C8I4nTJt6fFCzmIQeFiG2hjL4OpUIWhsze4N1qz+CVbgvwD0KwYyG085BSgjxe7L8WnRQZ1D8HrZw==~-1~-1~-1',
    'defaultLang': 'en',
    'nsit': 'lVDKDYTLtTup4o_4xWKuWa34',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNDk0NzU5MSwiZXhwIjoxNzM0OTU0NzkxfQ.Szb8ipnYbFyJLhZ98WgUniBOjfez9wbixhHa523Cdwg',
    'AKA_A2': 'A',
    'ak_bmsc': '90E54BF018EF97C9C86FE70F8869B0E0~000000000000000000000000000000~YAAQDW/ZFw1tOZuTAQAAXPbu8hqiiA7LcJixeqlEaP2W6bQJuvoKgMpSqbjKgmXAGRPMseOp3Hbmq3pyDaAWkKXzyPjwQH3Rn62uOjeipZ/RaFeqMt3Vk5/u11fDYwzbJAayqyJu52sfEDNQHyk8G0a7v1hRAfp4Q62sE1o1/p9AKIzAhY+JxJllsNVeNr8cB1a5TMyY6m9kPl0+Tv5PYpSOEkAdiwubeB0YCWqSVSKcSfjYDfGzd2CJFzEHr7sMIJa/Crof/E95tGvrrZ0gDGJGJT+sbsIvx8IPwX9k3uJOl09dforaSlhI+1AX1IAxW7R/Wj3drmQobkMPjorHwCfGdYgqBiO/m6ihU/bCvEToeShbNSKG02Nw5yqPANRNkToSBpjOkMERGXjqoA==',
    'bm_sz': '7428B76EA1A0D899D3DBA63664EAAD33~YAAQDW/ZFy9zOZuTAQAAd1fv8hqOLCP81ivhXKYiscr4z7d3JjqlZ9mLPIPYvAJWKptd1LHr2IWLzvqI2Ndn4xavMwq4fCzwcPULGPTQdxk6EXZMbYfMmrdByLnEYIUbQGBbecazj2cTjGHJQJPH2vibsqtjvMaUNKZOitCWWkVmP9rWiwkcarpw7U6l2muaOwXkRZblDiXbCCvA+GrEkauZYjgu2G3ppnj7PsJkxiF1Dvx9eLq+OnFFhy0VDwoz6XIhICNZBSdywNG35Wo3ZgH0FMOqaVkkrCsPvzpQasxJWG++n0vMkwdpX4uN+MUfMe5XFcZQht5heglB5ERt11T0mwNhnH4E4jMKFWVdChhcAYTi3hewaKfWuaSo1vULI+y+c4hJNzmtRlG0UkIdUgPHIeSZzt7UK0iozQ==~3355444~4273976',
    'bm_sv': '556F6309F18BAAD9C123667C5C91C86D~YAAQDW/ZFy5zOZuTAQAAd1fv8hqRm4D1+TdJADVC07RrpP20q447b963o5Km+HbhnY3jTcnSeWvfbBDa+9ZXVFzTsDBTJIJYV9snQ9+kZ9P8SiIHuXN/kUGCflrSpH6r7FprZD6ljYRdXpCALr1mtcFmN5SeZiFKpI6hI9mJOarWRmSUQXx4LE1zxVpiKopY+artk1FFOVCGbxL/b+ydAPFyfCe4GFqmUar26g/c5L8rIF3VebMD0ZQwwu8mk5yaVqw=~1',
    'bm_mi': 'FAB949FC80912DCD7B5A4FF680198AB3~YAAQDW/ZF1VwOZuTAQAA6Srv8hp+MBK47Ia2L5eyu4onlYoKFRqkGQZ+wKeooExxRE/xONaSMjFTqM7J9BvolNrYIlMm5eCe29DYMLkOpwu4CONg0CqAkYWTIXoZUDXMltNhoDOjTR/hrj81LKpLi6o1AF52QmDUL1dcWAIo4Uc5Sc2W6CVPj4VqNwQb1Y+zWu07vnB9lNxvOv0KJBFNN3rvidLNl+M9P5Jdm5vtzNJuswKHkhCq1yD2dSZwATpWa0cENYvTtN3AwH6OK9HwioSZPegir6cxMvCuyM9WO1TA54S2COEUEcyxtKrz1gWSmKJ6iW3ZCd46Ek377VpbGw==~1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    # 'Cookie': '_abck=0F400126EE635FB8F03795F2E2C0EB01~0~YAAQDW/ZF09zOZuTAQAAQVnv8g1K5ZOXCV8wkxz/qX3l67sDLLstGJBpyTeFe3wh/glWp0iscksQ1na2fB8pfW9Vcm+ez7TZfShOIbLpTOCZIOX0/3EF8KJYqfMwyu7gMjiyCsoUI1uVCnbAaIIFX/PiD+PulJ82obYDwX/f3FKrhBeaGVA6zQwGnom60RIWx1+YmrHaOXgXsZWeiQHxD39ZUkAru/zJ1Cg+U8A8IV6mwbojt+h3Fjo4vNgrUfHXkdCqGF4TWAR7cHfZgiVS8TOn+553skcv1wMocJ3LDCssRTqapxiOQq1mL061SWMQ3DXNIecyF8TstJNVgtFhaiqrTp8r4lXb1e3yaWrED1LIXSwNkAKTz3D8X0fjTQb/YcPaXvFdn6fz82jGQbFkg3DdGAb5mPWsTs/n33mrKng6G+r7/C8I4nTJt6fFCzmIQeFiG2hjL4OpUIWhsze4N1qz+CVbgvwD0KwYyG085BSgjxe7L8WnRQZ1D8HrZw==~-1~-1~-1; defaultLang=en; nsit=lVDKDYTLtTup4o_4xWKuWa34; nseappid=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNDk0NzU5MSwiZXhwIjoxNzM0OTU0NzkxfQ.Szb8ipnYbFyJLhZ98WgUniBOjfez9wbixhHa523Cdwg; AKA_A2=A; ak_bmsc=90E54BF018EF97C9C86FE70F8869B0E0~000000000000000000000000000000~YAAQDW/ZFw1tOZuTAQAAXPbu8hqiiA7LcJixeqlEaP2W6bQJuvoKgMpSqbjKgmXAGRPMseOp3Hbmq3pyDaAWkKXzyPjwQH3Rn62uOjeipZ/RaFeqMt3Vk5/u11fDYwzbJAayqyJu52sfEDNQHyk8G0a7v1hRAfp4Q62sE1o1/p9AKIzAhY+JxJllsNVeNr8cB1a5TMyY6m9kPl0+Tv5PYpSOEkAdiwubeB0YCWqSVSKcSfjYDfGzd2CJFzEHr7sMIJa/Crof/E95tGvrrZ0gDGJGJT+sbsIvx8IPwX9k3uJOl09dforaSlhI+1AX1IAxW7R/Wj3drmQobkMPjorHwCfGdYgqBiO/m6ihU/bCvEToeShbNSKG02Nw5yqPANRNkToSBpjOkMERGXjqoA==; bm_sz=7428B76EA1A0D899D3DBA63664EAAD33~YAAQDW/ZFy9zOZuTAQAAd1fv8hqOLCP81ivhXKYiscr4z7d3JjqlZ9mLPIPYvAJWKptd1LHr2IWLzvqI2Ndn4xavMwq4fCzwcPULGPTQdxk6EXZMbYfMmrdByLnEYIUbQGBbecazj2cTjGHJQJPH2vibsqtjvMaUNKZOitCWWkVmP9rWiwkcarpw7U6l2muaOwXkRZblDiXbCCvA+GrEkauZYjgu2G3ppnj7PsJkxiF1Dvx9eLq+OnFFhy0VDwoz6XIhICNZBSdywNG35Wo3ZgH0FMOqaVkkrCsPvzpQasxJWG++n0vMkwdpX4uN+MUfMe5XFcZQht5heglB5ERt11T0mwNhnH4E4jMKFWVdChhcAYTi3hewaKfWuaSo1vULI+y+c4hJNzmtRlG0UkIdUgPHIeSZzt7UK0iozQ==~3355444~4273976; bm_sv=556F6309F18BAAD9C123667C5C91C86D~YAAQDW/ZFy5zOZuTAQAAd1fv8hqRm4D1+TdJADVC07RrpP20q447b963o5Km+HbhnY3jTcnSeWvfbBDa+9ZXVFzTsDBTJIJYV9snQ9+kZ9P8SiIHuXN/kUGCflrSpH6r7FprZD6ljYRdXpCALr1mtcFmN5SeZiFKpI6hI9mJOarWRmSUQXx4LE1zxVpiKopY+artk1FFOVCGbxL/b+ydAPFyfCe4GFqmUar26g/c5L8rIF3VebMD0ZQwwu8mk5yaVqw=~1; bm_mi=FAB949FC80912DCD7B5A4FF680198AB3~YAAQDW/ZF1VwOZuTAQAA6Srv8hp+MBK47Ia2L5eyu4onlYoKFRqkGQZ+wKeooExxRE/xONaSMjFTqM7J9BvolNrYIlMm5eCe29DYMLkOpwu4CONg0CqAkYWTIXoZUDXMltNhoDOjTR/hrj81LKpLi6o1AF52QmDUL1dcWAIo4Uc5Sc2W6CVPj4VqNwQb1Y+zWu07vnB9lNxvOv0KJBFNN3rvidLNl+M9P5Jdm5vtzNJuswKHkhCq1yD2dSZwATpWa0cENYvTtN3AwH6OK9HwioSZPegir6cxMvCuyM9WO1TA54S2COEUEcyxtKrz1gWSmKJ6iW3ZCd46Ek377VpbGw==~1; nseQuoteSymbols=[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
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
