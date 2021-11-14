-- More Fun With Functions

module MoreFunWithFunctions where

waxOn     = x * 5
  where z = 7
        y = z + 8
        x = y ^ 2


triple x = x * 3

waxOff x = ((triple x)^2) ^ 3
