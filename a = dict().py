a = dict()
a[2] = (10, 2, 3)
a[1] = (9, 11, 11)

# sorted(a)
for key, value in a.items():
    v1, v2, v3 = value
    print(v1)