# super() = funtion used in a child classs to call methods from a parent class (superclasss)
#   Allows you to extend the functionality of the inherited methods

class Shape:
    def __init__(self, color, filled):
        self.color = color
        self.filled = filled
class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.radius = radius
class Square(Shape):
    def __init__(self, color, isfilled, width):
        super().__init__(color, isfilled)
        self.width = width
class Triangle(Shape):
    def __init__(self, color, filled, width, height):
        super().__init__(color, filled)
        self.width = width 
        self.height = height

circle = Circle("Blue","Red",2)
square = Square("Blue","Red", 2)
print(square.filled)