n=int(input("Please enter a num to start with :"))
num = n
rand_set = set()
counter=0
numlength = len(str(num))

while num not in rand_set:
    counter+=1
    rand_set.add(num)
    init = int(numlength - numlength/2);
    fini = int(numlength + numlength/2);
    num = int(str(num*num).zfill(numlength)[init:fini])
    print (f"{counter}: {num}")
