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
    '_abck': '0F400126EE635FB8F03795F2E2C0EB01~0~YAAQN2/ZF67jwlGUAQAAGYUTXw0L2vAPwuFgeWFgQlcHRPSRTRd5f409N2njGbxF8UulNOQ73R+nHPdZXiimkKCWOe68ndUz9CBWR79jOYCngNwo6rM0uVEMaPU0+tZBk5l8kN3RCNJ6foB+KOHlBIBvmtp22IrH9SIvuT0IRyEi2fhyNY3E1DIVQ0MHBvIZykIxd/qwaQCKkl2uKCKUfj5xGsDkJnmD/gj2V9WMB6/U1cxXyAFpxLcKIw4hMbXMQb0QGi5EOP55136LjF3Ex3zu2uRO97o6YHggXzW4YlMlA7Dd6OwKSME8udZVlvKgdwxgV3nOF9Ez9PtMgefG9nF8FLvczMRm8s6HAz4QWtswb11CyAZM2FFvGkL8q57nOPXFHBOeCI/DFcFN4jwdaZrTG+cv8JFaSWRB4RjCnnD8nmcgUVkCKRWZfol2PS8k+9b9Czbvx7M4RJEz+X2kFL2cfQzHai+CVgBHzbT0okc+gWTqp3irbhGgrniCdg==~-1~-1~-1',
    'defaultLang': 'en',
    'nsit': 'V--69kfvs0QXfGS8TYWH9b8e',
    'nseappid': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNjc2MTkwMCwiZXhwIjoxNzM2NzY5MTAwfQ.lL01RpWCeRjQejXYsDR0rn07ToBFXkuxdzoKZPv39_w',
    'AKA_A2': 'A',
    'ak_bmsc': '4CC7E061A055D19BC8EC865EF21260C9~000000000000000000000000000000~YAAQN2/ZF2++wlGUAQAAC+ARXxpsxi4H5Jfsz5nFuPQ1wCw6zgQSmh3WVkh7h4ytnUCcwcOGpm9kz4nhD1MakvsTwskPmrCaJ5UtwteCeXZWOurXHBMpYlM779sDsDl99sN+bt+t7ibh5hGQrvBKmPrWV76fcMVW3pF3wRtBEBHaho2sjlDUPaQQDyCbTrx3wxIPbUvAWmxf18qo8aJ4m59QJVDwmpOd0CEWxAXF6ioDdOZSxNitjieFsTKFdnXd9fsJDWzM5D1gXqf8srpnZz014vE1uz3Zq9gBKJa5GT6Q58qFpeyQ2TED9wI3bV6tQgHedRamaZmyf08IkHkLCvON0jnN/Kgog1HF+ipE3oJjF2lvCtKi8pOFzeP6ZF4ka69DdzlzKxj33mC1jA==',
    'bm_sz': '0A785FEC25FECEEEAFFAD20616D6AF14~YAAQN2/ZF3DjwlGUAQAAEYATXxosmV3sRJ7Ll6Ij4xd/7dPkDBFap0/ZXCAOPnGUZd5oKvzNOA0eK+1bbfImNkbOukh0uDmZ1zvHjguxWpSL85BmVAIE/3rCMACjvQSGW5vgDL3T/dvyxpZdQ4ZJrzeuIzbdCzQuwXeKn1+jOYdVMM4dbCvQrWI7SvCcUhwzR+0kuzCBsRYw1CCShN+3CFQDwfkc/nVk+i+WulHael/NgZUz8uFjhmvw1I4rS9uxLHniitHZRRvysa/pgFcT55kkb7kh+7Tu+d1FSfC17HNLnzS/IzZ8N0s1x2Q2y2wYlY9wMVqlWZfVyzUMJRixFfj8yQIA1IxVcTZESQlVHlMzfyrnYqPRM6KW5i9qJhhLpiwVSWMF2RZQ49pLcylZ+AOAg8YuXz1X~4600898~4535096',
    'bm_sv': '77721525B33B18EA076FA5C5B8C0BC76~YAAQN2/ZF2/jwlGUAQAAEYATXxqi/2J5diaE/ej7pWfWM7bO2vtQKStBd3wy/9oABTF7JA+C7F6iOkBSz+I9g8+24Dm3rrYPvZGq4MuiSAEsBNGAMs/HjJcGQIXvlDEqpHdQRKmRIVXieYJQhoDmbbVGRz+NOLWYZmToxXJoLUmSCT8e0uAXyfkliAlidob16AU7lzRbrmnILhQmw4nmbqjjMTBfCoGzzqK8TO04+Sj2e3FkVhApHBfugQqLFunkC3iY~1',
    'nseQuoteSymbols': '[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]',
    'bm_mi': 'B6D8339A753D29E354EA2382B49D567A~YAAQN2/ZF27jwlGUAQAAEYATXxrlCnrviF+NEH3Qht+pL9LvUpUc/3vodSfnjSNTQu5vmqugeF1c5JavIGRA0nQwP1ewXwifVQK0EL5UMKTNJ2xg8Fj2zaafLc5PEHj8INlqNZjexgYw6ezKeIaiDzVxR+caxLR80ICgaYX2HQsM27SaywQruQUPnK0hrB9mi+/Nk9D3ta+biUmnfnJjjTAkrXsLHrGoXYdLMSs0bItcP0/KP/ahrGGuSYQg/NN8LkXEo4w4pvN08NC3ABv0pYLZoCRIN425lfM6ngdbI0fHk/p0f2aX/tUf70bSIwwTfkMMl4FxsE9w0klAoQUb+g==~1',
}

headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:131.0) Gecko/20100101 Firefox/131.0',
    'Accept': '*/*',
    'Accept-Language': 'en-US,en;q=0.5',
    # 'Accept-Encoding': 'gzip, deflate, br, zstd',
    'Connection': 'keep-alive',
    'Referer': 'https://www.nseindia.com/get-quotes/equity?symbol=GOLDBEES',
    # 'Cookie': '_abck=0F400126EE635FB8F03795F2E2C0EB01~0~YAAQN2/ZF67jwlGUAQAAGYUTXw0L2vAPwuFgeWFgQlcHRPSRTRd5f409N2njGbxF8UulNOQ73R+nHPdZXiimkKCWOe68ndUz9CBWR79jOYCngNwo6rM0uVEMaPU0+tZBk5l8kN3RCNJ6foB+KOHlBIBvmtp22IrH9SIvuT0IRyEi2fhyNY3E1DIVQ0MHBvIZykIxd/qwaQCKkl2uKCKUfj5xGsDkJnmD/gj2V9WMB6/U1cxXyAFpxLcKIw4hMbXMQb0QGi5EOP55136LjF3Ex3zu2uRO97o6YHggXzW4YlMlA7Dd6OwKSME8udZVlvKgdwxgV3nOF9Ez9PtMgefG9nF8FLvczMRm8s6HAz4QWtswb11CyAZM2FFvGkL8q57nOPXFHBOeCI/DFcFN4jwdaZrTG+cv8JFaSWRB4RjCnnD8nmcgUVkCKRWZfol2PS8k+9b9Czbvx7M4RJEz+X2kFL2cfQzHai+CVgBHzbT0okc+gWTqp3irbhGgrniCdg==~-1~-1~-1; defaultLang=en; nsit=V--69kfvs0QXfGS8TYWH9b8e; nseappid=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJhcGkubnNlIiwiYXVkIjoiYXBpLm5zZSIsImlhdCI6MTczNjc2MTkwMCwiZXhwIjoxNzM2NzY5MTAwfQ.lL01RpWCeRjQejXYsDR0rn07ToBFXkuxdzoKZPv39_w; AKA_A2=A; ak_bmsc=4CC7E061A055D19BC8EC865EF21260C9~000000000000000000000000000000~YAAQN2/ZF2++wlGUAQAAC+ARXxpsxi4H5Jfsz5nFuPQ1wCw6zgQSmh3WVkh7h4ytnUCcwcOGpm9kz4nhD1MakvsTwskPmrCaJ5UtwteCeXZWOurXHBMpYlM779sDsDl99sN+bt+t7ibh5hGQrvBKmPrWV76fcMVW3pF3wRtBEBHaho2sjlDUPaQQDyCbTrx3wxIPbUvAWmxf18qo8aJ4m59QJVDwmpOd0CEWxAXF6ioDdOZSxNitjieFsTKFdnXd9fsJDWzM5D1gXqf8srpnZz014vE1uz3Zq9gBKJa5GT6Q58qFpeyQ2TED9wI3bV6tQgHedRamaZmyf08IkHkLCvON0jnN/Kgog1HF+ipE3oJjF2lvCtKi8pOFzeP6ZF4ka69DdzlzKxj33mC1jA==; bm_sz=0A785FEC25FECEEEAFFAD20616D6AF14~YAAQN2/ZF3DjwlGUAQAAEYATXxosmV3sRJ7Ll6Ij4xd/7dPkDBFap0/ZXCAOPnGUZd5oKvzNOA0eK+1bbfImNkbOukh0uDmZ1zvHjguxWpSL85BmVAIE/3rCMACjvQSGW5vgDL3T/dvyxpZdQ4ZJrzeuIzbdCzQuwXeKn1+jOYdVMM4dbCvQrWI7SvCcUhwzR+0kuzCBsRYw1CCShN+3CFQDwfkc/nVk+i+WulHael/NgZUz8uFjhmvw1I4rS9uxLHniitHZRRvysa/pgFcT55kkb7kh+7Tu+d1FSfC17HNLnzS/IzZ8N0s1x2Q2y2wYlY9wMVqlWZfVyzUMJRixFfj8yQIA1IxVcTZESQlVHlMzfyrnYqPRM6KW5i9qJhhLpiwVSWMF2RZQ49pLcylZ+AOAg8YuXz1X~4600898~4535096; bm_sv=77721525B33B18EA076FA5C5B8C0BC76~YAAQN2/ZF2/jwlGUAQAAEYATXxqi/2J5diaE/ej7pWfWM7bO2vtQKStBd3wy/9oABTF7JA+C7F6iOkBSz+I9g8+24Dm3rrYPvZGq4MuiSAEsBNGAMs/HjJcGQIXvlDEqpHdQRKmRIVXieYJQhoDmbbVGRz+NOLWYZmToxXJoLUmSCT8e0uAXyfkliAlidob16AU7lzRbrmnILhQmw4nmbqjjMTBfCoGzzqK8TO04+Sj2e3FkVhApHBfugQqLFunkC3iY~1; nseQuoteSymbols=[{"symbol":"GOLDBEES","identifier":"","type":"equity"}]; bm_mi=B6D8339A753D29E354EA2382B49D567A~YAAQN2/ZF27jwlGUAQAAEYATXxrlCnrviF+NEH3Qht+pL9LvUpUc/3vodSfnjSNTQu5vmqugeF1c5JavIGRA0nQwP1ewXwifVQK0EL5UMKTNJ2xg8Fj2zaafLc5PEHj8INlqNZjexgYw6ezKeIaiDzVxR+caxLR80ICgaYX2HQsM27SaywQruQUPnK0hrB9mi+/Nk9D3ta+biUmnfnJjjTAkrXsLHrGoXYdLMSs0bItcP0/KP/ahrGGuSYQg/NN8LkXEo4w4pvN08NC3ABv0pYLZoCRIN425lfM6ngdbI0fHk/p0f2aX/tUf70bSIwwTfkMMl4FxsE9w0klAoQUb+g==~1',
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
