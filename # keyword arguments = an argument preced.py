# keyword arguments = an argument preceded by an identifier 
#                     helps with readability
#                     order of arguments doesn't matter
#                     1.positional 2. default 3. KEyword 4. arbitrary
# def add(*args):
#     total = 0
#     for arg in args:
#         total += arg
#     return total

# print(add(1, 2, 3))   
# def display_name(*/args):
    # for arg in args:
        # print(arg, end = " ")
# display_name(("s", "c"))
# def food_money(**menu):
#     for food, value in menu.items():
#         print(food, end = " ")  
#         print(value)
# food_money(street = 20,
#             city = 20)  