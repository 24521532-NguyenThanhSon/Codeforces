class Car:
    wheels = 4
    num_car = 0
    def __init__(self, model, year, color, for_sale):
        self.model = model
        self.year = year
        self.color = color
        self.for_sale = for_sale
        Car.num_car += 1
    def drive(self, mavuong):
        print("You drive the car")
    def stop(self):
        print("You stop the car")
car = Car(1,1,1,1)
