from math import exp

def center_diff(f, x, h=0.0001):
  df = (f(x+h) - f(x-h))/(2.0*h)
  return df

x = 0.5
df = center_diff(exp, x)
print("first derivative = {0}".format(df))
print("exp({0}) = {1}".format(x,exp(x)))


h=0.125
for i in range(50):
  df = center_diff(exp, x, h)
  print("h = {0}, df= {1}".format(h,df))
  
  h = h/2.0
