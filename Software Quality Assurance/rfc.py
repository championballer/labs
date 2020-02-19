"""
The Response Set (RS) of a class is a set of methods that can potentially be executed by an object of that class. RFC is the count of these methods belonging to the set.
"""

class Example:

	member_data = None
	def __init__(self):
		print(1)
		

	def method1(self):
		self.member_data = 1
		print(self.member_data)
		return 1

	def method2(self):
		return 2

	def method3(self):
		return 3

	def method4(self):
		return 4

class Example2(Example):

	def __init__(self):
		super()

	def method1(self):
		return "Woooyi"

	def method5(self):
		return "Mamamamiya"

ex1 = Example()
ex2 = Example2()

print("Response Set for example1 object:", dir(ex1))
print()
print("Response Set for example2 object:", dir(ex2))
print("Response for object belonging to Class example1:",len(dir(ex1)))

print("Response for object belonging to class example2:",len(dir(ex2)))