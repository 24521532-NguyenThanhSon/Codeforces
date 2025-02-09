class Animal:
    def __init__(self, name):
        self.name  = name
class Dog(Animal):
    def __init__(self, name, color):
        super().__init__(name)
        self.color = color
dog = Dog("Name", "Color")
print(dog.name)