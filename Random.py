import random
def Random_Color():
    color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
    return color 
Lis = dict()
class Point:
    def __init__(self, col, radius, x, y):
        self.col = col
        self.radius = radius
        self.x = x
        self.y = y
for i in range(1, 20):
    Lis[i] = Point(Random_Color(), 60, random.randint(0, 50), random.randint(0, 50))
    print(Lis[i].x)