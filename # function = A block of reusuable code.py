# function = A block of reusuable code
# place () after the function name to involve it
# def Happy_birthday(name):
    # print(f"What the fuck? {name}")
# Happy_birthday("John")
# def create_name(first, last):
#     first = first.upper()
#     last = last.upper()
#     return first + last
# fullname = create_name("thanh", "son")
# print(fullname)
# def net_price(price, discount = 0, tax = 0):
#     print(price * (1 - discount) * (1 + tax))
# net_price(50)
import time
def count(start, end):
    for x in range(start, end + 1):
        print(x)
        time.sleep(1)
    print("Done")
count(1, 10)