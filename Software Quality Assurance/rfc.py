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

ex = Example()
ex1 = Example2()
ex.method1()
print(dir(ex))
print()
print(dir(ex1))
print(type(dir(ex)))
print(len(dir(ex)))

print(len(dir(ex1)))