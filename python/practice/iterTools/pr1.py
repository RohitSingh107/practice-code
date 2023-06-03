
import itertools as it
import operator as op

il = [2,7,6,9,3,5]
cl = ['b', 'd', 'b', 'a', 'x', 'x', 'z', 'x', 'w']

data = [{'name': 'Alan', 'age': 34},
         {'name': 'Catherine', 'age': 34},
         {'name': 'Betsy', 'age': 29},
         {'name': 'David', 'age': 33},
         {'name': 'Rohit', 'age': 34}
        ]

r = list(it.accumulate(il, op.add))
print("accumulate add", r)

r = list(it.accumulate(il, min))
print("accumulate min", r)
r = list(it.accumulate(il, max))
print("accumulate max", r)

print("chain", list(it.chain('ABC', 'DEF')))
print("chain", list(it.chain([1, 2], [3, 4, 5, 6], [7, 8, 9])))

print("combinations", list(it.combinations(cl, 3)))
print("combinations", list(it.combinations(cl, 6)))
print("combinations", list(it.combinations(['a', 'b', 'b', 'c'], 2)))

print("combinations wit replacmet", list(it.combinations_with_replacement(['a', 'b', 'b', 'c'], 2)))
print("combinations wit replacmet", list(it.combinations_with_replacement(cl, 2)))

print("compress", list(it.compress('ABCDEF', [1,0,1,0,1,1])))

counter = it.count(start=0.5, step= -0.75)
print("count", list(next(counter) for _ in range(5)))

print("count", list(zip(it.count(), ['a', 'b', 'c'])))


alternating_ones = it.cycle([1, -1])
# print("cycle", list(alternating_ones))

print("dropwhile", list(it.dropwhile(lambda x: x < 3, [0, 1, 2, 3, 4, -1])))

print("filterfalse", list(it.filterfalse(lambda x: x <= 0, [0, 1, -1, 2, -2])))

print("groupby:")
grouped_data = it.groupby(data, key=lambda x: x['age'])
for key, grp in grouped_data:
    print('{}: {}'.format(key, list(grp)))

print("groupby", dict(it.groupby([2,3,4,5], lambda x: x != 3)))

print("is Slice", list(it.islice([2,5,6,7], 3)))

print("pairwise", list(it.pairwise([2,3,4,5,6])))

print("permutations", list(it.permutations(['a', 'b', 'c'])))
print("permutations", list(it.permutations(['a', 'b', 'b', 'c'])))
print("permutations", list(it.permutations(['a', 'b', 'b', 'c'], 2)))
print("permutations", list(it.permutations('abc')))

print("product", list(it.product([1, 2], ['a', 'b', 'c'])))


print("repeat", list(it.repeat('abc', 9)))

print("starmap", list(it.starmap(pow, [(2,5), (3,2), (10,3)])))

print("takewhile", list(it.takewhile(lambda x: x < 3, [0, 1, 2, 3, 4])))

print("zip longest", list(it.zip_longest([1, 2, 3, 4, 5], ['a', 'b', 'c'])))

iterator1, iterator2 = it.tee([1, 2, 3, 4, 5], 2)
print("tee", list(iterator2))
