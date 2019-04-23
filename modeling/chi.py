from scipy.stats import chisquare

N=int(input("Enter the number of times experiment is performed"))
classes=int(input("Enter the interval/classes"))

expected=[]

for i in range(0,classes):
	expected.append(N/classes) 

print("Enter the outcomes") 

actual=[]

for i in range(0,classes):
	x=int(input(str(i+1)))

actual.append(x) 
x=chisquare(actual,expected) 
print(x)