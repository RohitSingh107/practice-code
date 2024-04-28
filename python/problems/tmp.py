

from functools import reduce, cached_property
import io
import sys
import math
import itertools
import collections

b = io.StringIO()

sys.stdout = b

help(itertools)

sys.stdout = sys.__stdout__

# print(b.getvalue())

print(help("".count))


