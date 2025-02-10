# Multiple class inheritance = inherit from more than one parent class
#   C(A, B)
#   multilever inheritance = inherit from a parent which inherits form another parent
#   C(B) <- B(A) <- A
class Animal:
    def __init__(self, name):
        self.name = name
    def eat(self):
        print(f"This animal {self.name} is eating")
    def sleep(self):
        print("This animal is sleeping")
class Prey(Animal):
    def flee(self):
        print("This animal is fleeing")
class Predator(Animal): 
    def hunt(self):
        print("This animal is hunting")
class Rabbit(Prey):
    pass
class Hawk(Predator):
    pass
class Fish(Prey, Predator):
    pass
rabbit = Rabbit("John")
hawk = Hawk("Petter")
fish = Fish("Robber")
