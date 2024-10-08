import pandas as pd
import yfinance as yf
import locale


locale.setlocale(locale.LC_ALL, 'en_IN')

def f(x):
    ticker = yf.Ticker(x + ".NS")
    return {
        "ETF": x,
        "1D": locale.format_string("%d", ticker.history(period="1d")["Volume"].mean(), grouping=True),
        "5D": locale.format_string("%d", ticker.history(period="5d")["Volume"].mean(), grouping=True),
        "1MO": locale.format_string("%d", ticker.history(period="1mo")["Volume"].mean(), grouping=True),
        "3MO": locale.format_string("%d", ticker.history(period="3mo")["Volume"].mean(), grouping=True),
        "6M0": locale.format_string("%d", ticker.history(period="6mo")["Volume"].mean(), grouping=True),
        # "1Y": ticker.history(period="1y")["Volume"].mean(),
        "YTD": locale.format_string("%d", ticker.history(period="ytd")["Volume"].mean(), grouping=True),
        "MAX": locale.format_string("%d", ticker.history(period="max")["Volume"].mean(), grouping=True),
    }


etfs = [
    "CPSEETF",
    "MIDCAPETF",
    "MON100",
    "SMALLCAP",
    "HDFCSML250",
    "MOSMALL250",
    "MOM30IETF",
    "ALPHAETF",
]

vol = pd.DataFrame(list(map(lambda x: f(x), etfs)))

print(vol)



