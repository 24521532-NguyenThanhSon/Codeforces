# List comprehension = A concise way to create lists in Python
# Compact and easier to read than traditional loops
# [Expression for value in iterable if conditions]
doubles = []
for x in range(1, 12):
    doubles.append(x * 2)
# del doubles[2] -> delete values in index 2
# doubles.remove(2) -> remove element with value 2
# doubles = [x for x in doubles if x >= 5]
