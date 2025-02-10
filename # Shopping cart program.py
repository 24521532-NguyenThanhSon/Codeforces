# Shopping cart program 
foods = []
prices = []
total = 0
while True:
    food = input("Enter a food to buy (q to quit): ")
    if(food.lower() == "q"):
        break
    else:
        price = float(input(f"Enter the price of a {food}: $"))
        foods.append(food)
        prices.append(price)

# for food in foods:
#     print(food,  end =" ")