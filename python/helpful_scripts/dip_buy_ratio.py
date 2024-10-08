from typing import Tuple, List
from icecream import ic
import math

def closest_amount(eq : Tuple[float, float]):
    price = eq[0]
    allocated_amount = eq[1]
    floor = math.floor(allocated_amount/ price)
    ceil = math.ceil(allocated_amount/ price)

    if ceil * price - allocated_amount < allocated_amount - floor * price:
        return ceil
    else:
        return floor

def f(total_amount : int, equity : List[Tuple[float, float]]):
    total_dip = sum(y for (_,y) in equity)
    allocated_amounts = tuple(map(lambda x : (x[0], total_amount * x[1] / total_dip), equity))

    ic(tuple(map(closest_amount, allocated_amounts)))


    return allocated_amounts

total_amount = 1000
# equity = [(22.27, 0.45), (96.80, 0.79), (36.72, 1.05), (183.83, 1.14)]
equity = [(101.35, 0.21), (185.56, 0.22)]
ic(f(total_amount, equity))
