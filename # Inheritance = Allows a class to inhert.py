# Inheritance = Allows a class to inhertit attributes and methods form another class
# Helps with code reusability and extensibility
# class child(Parent)
class Animal:
    def __init__(self, name):
        self.name = name
        self.is_alive = True
    def eat(self):
        print(f"{self.name} is eating")
    def sleep(self):
        print(f"{self.name} is sleeping")

class Dog(Animal):
    def speak(self):
        print("WOOF!")
class Cat(Animal):
    def speak(self):
        print("MEOW!")
class Mouse(Animal): 
    def speak(self):
        print("SQUEEK!")
dog = Dog("Scooby")
cat = Cat("Garfield")
mouse = Mouse("Mickey")
dog.speak()
