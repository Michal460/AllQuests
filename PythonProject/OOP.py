# class Animal:
#     def __init__(self, name):
#         self.name = name
#
#     def speak(self):
#         pass
#
# class Dog(Animal):
#         def speak(self):
#             return "Gav!"
#
# class Cat(Animal):
#     def speak(self):
#         return "Meow!"
#
# dog = Dog("Bobik")
# cat = Cat("Sharik")
#
# print(dog.speak())
# print(cat.speak())
#
# def animal_speak(animal):
#     return animal.speak()
#
# animal_list = [Dog("Bobik"), Cat("Sharik")]
#
# for animal in animal_list:
#     print(animal_speak(animal))
#//////////////////////////////////
#from abc import ABC, abstractmethod
# class Shape(ABC):
#     @abstractmethod
#     def area(self):
#         pass
#
# class Rectangle(Shape):
#     def __init__(self, width, height):
#         self.width = width
#         self.height = height
#
#     def area(self):
#         return self.width * self.height
#
# area = Rectangle(5,6)
#
# print(area.area())
#/////////////////////////////////////////////////
#
# class Car:
#     def __init__(self, brand):
#         self.brand = brand
#         self._protected_info = 'This is protected info'
#         self.__private_info = 'This is private info'
#
#     def get_private_info(self):
#         return self.__private_info
#
# car = Car("Toyota")
# print(car.brand)
# print(car.get_private_info())
# print(car._protected_info)
#///////////////////////////////////////////
# class Animal:
#     def speak(self):
#         pass
#
# class Dog(Animal):
#     def speak(self):
#         return "Gav!"
#
# class Cat(Animal):
#     def speak(self):
#         return "Meow!"
#
# def animal_speak(animal):
#     return animal.speak()
#
# dog = Dog()
# cat = Cat()
#
# print(animal_speak(dog))
# print(animal_speak(cat))
#///////////////////////////////////////////////
# class MyClass:
#     count = 0
#     def __init__(self, name):
#         self.name = name
#         MyClass.count += 1
#
#     @classmethod
#     def total_instances(cls):
#         return cls.count
#
# obj1 = MyClass("First")
# obj2 = MyClass("Second")
#
# print(MyClass.total_instances())
#/////////////////////////////////////////////////
# class Circle:
#     def __init__(self, radius):
#         self._radius = radius
#
#     @property
#     def radius(self):
#         return self._radius
#
#     @radius.setter
#     def radius(self, value):
#         if value < 0:
#             raise ValueError("Radius is bad")
#         self._radius = value
#
# circle = Circle(5)
# print(circle._radius)
# circle = Circle(7)
# print(circle._radius)
#//////////////////////////////////////////
# from abc import ABC, abstractmethod
# class Shape(ABC):
#     @abstractmethod
#     def area(self):
#         pass
#
#     @abstractmethod
#     def perimeter(self):
#         pass
#
# class Rectangle(Shape):
#     def __init__(self, width, height):
#         self.width = width
#         self.height = height
#
#     def area(self):
#         return self.width * self.height
#
#     def perimeter(self):
#         return 2*(self.width + self.height)
#
# rect = Rectangle(5,6)
# print(rect.area())
#//////////////////////////////////////////
# class Animal:
#     def move(self):
#         pass
#
# class Bird(Animal):
#     def move(self):
#         return "Летит"
#
# class Fish(Animal):
#     def move(self):
#         return "Плывет"
#
# def movement_description(animal):
#     return animal.move()
#///////////////////////////////////////
# from abc import ABC, abstractmethod
# class Shape(ABC):
#     @abstractmethod
#     def area(self):
#         pass
#
#     @abstractmethod
#     def perimeter(self):
#         pass
#
# class Rectangle(Shape):
#     def __init__(self, width, height):
#         self.width = width
#         self.height = height
#
#     def area(self):
#         return self.width * self.height
#
#     def perimeter(self):
#         return 2*(self.width * self.height)
#////////////////////////////////////////////////////
# from abc import ABC, abstractmethod
#
# class Vehicle(ABC):
#     __speed = 0
#
#     @abstractmethod
#     def drive(self):
#         pass
#
#     @property
#     def get_speed(self):
#         return self.__speed
#
#     @get_speed.setter
#     def set_speed(self, speed):
#         if speed < 0:
#             raise ValueError("Speed cannot be negative")
#         self.__speed = speed
#
# class Car(Vehicle):
#     def __init__(self, move):
#         super().__init__()  # Вызов конструктора родительского класса
#         self.move = move
#
#     def drive(self):
#         return self.move
#
# class Boat(Vehicle):
#     def __init__(self, move):
#         super().__init__()  # Вызов конструктора родительского класса
#         self.move = move
#
#     def drive(self):
#         return self.move
#
# def vehicle_description(vehicle):
#     return vehicle.drive()  # Убрали input()
#//////////////////////////////////////////////////////////////////
# class Animal:
#     def __init__(self, name):
#         self.name = name
#
#     def speak(self):
#         raise NotImplementedError("Subclass must implement in this method")
#
# class Dog(Animal):
#     def speak(self):
#         return f"{self.name} says Woof!"
#
# class Cat(Animal):
#     def speak(self):
#         return f"{self.name} says Meow!"
#
# dog = Dog("Buddy")
# cat = Cat("Whiskers")
#
# print(dog.speak())
# print(cat.speak())
#///////////////////////////////////////////////////
# from abc import ABC, abstractmethod
#
# class Vehicle(ABC):
#     __speed = 0
#     __fuel = 0
#
#     @abstractmethod
#     def drive(self):
#         pass
#
#     @property
#     def get_speed(self):
#         return self.__speed
#
#     @property
#     def check_fuel(self):
#         return self.__fuel
#
#     @get_speed.setter
#     def set_speed(self, speed):
#         if speed < 0:
#             raise ValueError("Speed cannot be negative")
#         self.__speed = speed
#
#     @check_fuel.setter
#     def change_fuel(self, fuel):
#         if fuel == 0:
#             raise ("U cant move")
#         self.__fuel = fuel
#
# class Car(Vehicle):
#     def __init__(self, move):
#         super().__init__()
#         self.move = move
#
#     def drive(self):
#         return self.move
#
# class Boat(Vehicle):
#     def __init__(self, move):
#         super().__init__()
#         self.move = move
#
#     def drive(self):
#         return self.move
#
# class Plane(Vehicle):
#     def __init__(self, move):
#         super().__init__()
#         self.move = move
#
#     def drive(self):
#         return self.move
#
#     def change_fuel(self, fuel):
#         if fuel == 0:
#             raise ("U cant move")
#         self.__fuel = fuel
#
# def vehicle_print(vehicle):
#     if vehicle == 'Boat':
#         print("Boat is sailing in the sea")
#     if vehicle == 'Car':
#         print("Car is moving on the road")
#     if vehicle == 'Plane':
#         print("Plane is flying in the cloud")
#////////////////////////////////////////////////////////////
#Singleton
# class Singleton:
#     _instance = None
#     def __new__(cls, *args, **kwargs):
#         print("Working...\n")
#         if not cls._instance:
#             cls._instance = super(Singleton, cls).__new__(cls)
#         return cls._instance
#
# obj1 = Singleton()
# obj2 = Singleton()
#
# print(obj1)
#
# print(obj1 == obj2)
#////////////////////////////////////////////////////////////////
#Fabric Method
# from abc import ABC, abstractmethod
# class Animal(ABC):
#     @abstractmethod
#     def speak(self): pass
# class Dog(Animal):
#     def speak(self): return "Woof!"
# class Cat(Animal):
#     def speak(self): return "Meow!"
# class AnimalFactory:
#     def create_animal(self, animal_type):
#         if animal_type == 'dog': return Dog()
#         if animal_type == 'cat': return Cat()
# factory = AnimalFactory()
# dog = factory.create_animal('dog')
# print(dog.speak())
#///////////////////////////////////////////////////////
#Observer
#наблюдатель
# class Observer:
#     def update(self, message):
#         pass
# #субьект
# class Subject:
#     def __init__(self):
#         self._observers = []
#     def add_observer(self, observer):
#         self._observers.append(observer)
#     def remove_observer(self, observer):
#         self._observers.remove(observer)
#     def notify_observers(self, message):
#         for observer in self._observers:
#             observer.update(message)
# class User(Observer):
#     def __init__(self, name):
#         self.name = name
#     def update(self, message):
#         print(f"{self.name} получил сообщение: {message}")
# sub = Subject()
# us1 = User("Alex")
# us2 = User("Maria")
# sub.add_observer(us1)
# sub.add_observer(us2)
# sub.notify_observers("Скидка 50% на все товары!")
#///////////////////////////////////////////////////////////////
#strategy
# Стратегии
# class DiscountStrategy:
#     def calculate_discount(self, amount):
#         pass
#
# class RegularCustomerStrategy(DiscountStrategy):
#     def calculate_discount(self, amount):
#         return amount * 0.1
#
# class VIPCustomerStrategy(DiscountStrategy):
#     def calculate_discount(self, amount):
#         return amount * 0.3
#
# class SeasonalCustomerStrategy(DiscountStrategy):
#     def calculate_discount(self, amount):
#         return amount * 0.2
#
# # Контекст
# class ShoppingCart:
#     def __init__(self, strategy):
#         self._strategy = strategy
#
#     def checkout(self, amount):
#         return amount - self._strategy.calculate_discount(amount)
#
# # Использование
# cart1 = ShoppingCart(RegularCustomerStrategy())
# print(cart1.checkout(100))  # 90.0 (10% скидка)
#
# cart2 = ShoppingCart(VIPCustomerStrategy())
# print(cart2.checkout(100))  # 70.0 (30% скидка)
#////////////////////////////////////////////////////////////////
#Decorator
# Компонент
# class Coffee:
#     def cost(self):
#         return 5
#
#     def description(self):
#         return "Кофе"
#
# # Базовый декоратор
# class CoffeeDecorator(Coffee):
#     def __init__(self, coffee):
#         self._coffee = coffee
#
#     def cost(self):
#         return self._coffee.cost()
#
#     def description(self):
#         return self._coffee.description()
#
# # Декораторы
# class MilkDecorator(CoffeeDecorator):
#     def cost(self):
#         return self._coffee.cost() + 2
#
#     def description(self):
#         return self._coffee.description() + ", с молоком"
#
# class SugarDecorator(CoffeeDecorator):
#     def cost(self):
#         return self._coffee.cost() + 1
#
#     def description(self):
#         return self._coffee.description() + ", с сахаром"
#
# # Использование
# simple_coffee = Coffee()
# print(simple_coffee.description(), "стоит", simple_coffee.cost())
#
# milk_coffee = MilkDecorator(Coffee())
# print(milk_coffee.description(), "стоит", milk_coffee.cost())
#
# sugar_milk_coffee = SugarDecorator(MilkDecorator(Coffee()))
# print(sugar_milk_coffee.description(), "стоит", sugar_milk_coffee.cost())
#////////////////////////////////////////////////////////////////////////////////
#Singleton
# class Database:
#     _instance = None  # Приватная переменная для хранения экземпляра
#
#     def __new__(cls):
#         if not cls._instance:
#             cls._instance = super(Database, cls).__new__(cls)
#         return cls._instance
#
#     def connect(self):
#         return "Подключение к базе данных установлено."
#
# # Использование
# db1 = Database()
# db2 = Database()
#
# print(db1 is db2)  # Вывод: True, один и тот же экземпляр
#
# print(db1.connect())  # Подключение к базе данных установлено.
# print(db2.connect())  # Подключение к базе данных установлено.
#///////////////////////////////////////////////////////////////////////////
#Practise
#1
# class Animal:
#     def make_sound(self):
#         pass
# class Dog(Animal):
#     def make_sound(self):
#         return "Woof!"
# class Cat(Animal):
#     def make_sound(self):
#         return "Meow!"
# class Bird(Animal):
#     def make_sound(self):
#         return "Tweet!"
# dog = Dog().make_sound()
# cat = Cat().make_sound()
# bird = Bird().make_sound()
# print(dog, cat, bird)
#2
# class Logger:
#     _instance = None
#     def __new__(cls, *args, **kwargs):
#         if not cls._instance:
#             cls._instance = super(Logger, cls).__new__(cls)
#         return cls._instance
#     def log_message(self, text):
#         with open("log.txt", "a", encoding='utf-8') as file:
#             file.write(text)
#3
# class BakeryItem:
#     def cost(self):
#         pass
#     def description(self):
#         pass
# class Bun(BakeryItem):
#     def cost(self):
#         return 5
#     def description(self):
#         return 'булочка'
# class BunDecorator(Bun):
#     def __init__(self, bun):
#         self._bun = bun
#     def cost(self):
#         return self._bun
#     def description(self):
#         return self._bun
# class CreamDecorator(BunDecorator):
#     def cost(self):
#         return self._bun + 2,5
#     def description(self):
#         return self._bun + 'с кремом'
# class ChocolateDecorator(BunDecorator):
#     def cost(self):
#         return self._bun + 3
#     def description(self):
#         return self._bun + 'с шоколадом'
#4 реализация паттерна Observer
# class Observer:
#     def update(self, message):
#         pass
# class Subject:
#     def __init__(self):
#         self._observers = []
#     def add_element(self, observer):
#         return self._observers.append(observer)
#     def remove_element(self, observer):
#         return self._observers.remove(observer)
#     def notify(self, message):
#         for obs in self._observers:
#             obs.update(message)
# class User(Observer):
#     def __init__(self, name):
#         self.name = name
#     def update(self, message):
#         return f"{self.name} получил сообщение {message}"
#5
# class PaymentStrategy:
#     def pay(self, price):
#         return price
# class CreditCard(PaymentStrategy):
#     def pay(self, price):
#         return f'вы оплачиваете сумму {price} с помощью кредитной карты'
# class PayPal(PaymentStrategy):
#     def pay(self, price):
#         return f'вы оплачиваете сумму {price} с помощью PayPal'
# class BankRemittance(PaymentStrategy):
#     def pay(self, price):
#         return f'вы оплачиваете сумму {price} с помощью банковского перевода'
# class PaymentContext:
#     def __init__(self, strategy):
#         self._strategy = strategy
#     def checkout(self, price):
#         return self._strategy.pay(price)
#6
# class Beverage:
#     def __init__(self, name):
#         self._name = name
#     def get_description(self):
#         return self._name
#     def cost(self):
#         pass
# class Espresso(Beverage):
#     def cost(self):
#         return 20
# class CondimentDecorator(Beverage):
#     def get_description(self):
#         pass
# class Milk(CondimentDecorator):
#     def __init__(self, beverage):
#         super().__init__("with milk")
#         self.beverage = beverage
#7
# from abc import ABC, abstractmethod
# class Car(ABC):
#     @abstractmethod
#     def year_create(self):
#         pass
#     @abstractmethod
#     def max_fuel(self):
#         pass
#     @abstractmethod
#     def max_oil(self):
#         pass
# class Sedan(Car):
#     def year_create(self):
#         return 1998
#     def max_fuel(self):
#         return 100
#     def max_oil(self):
#         return 60
#     def name_engine(self):
#         return 'f20b'
# class SUV(Car):
#     def year_create(self):
#         return 2006
#     def max_oil(self):
#         return 70
#     def max_fuel(self):
#         return 130
#     def name_engine(self):