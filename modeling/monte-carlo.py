import random
from math import floor

N=int(input("Number of customers to be simulated: "))

name=["Filling","Crown","Cleaning","Extraction","Checkup"] 

time=[45,60,15,45,15]
freq=[40,15,15,10,20]

total=0
for val in freq:
	total+=val

prob=[]
for i in range(len(freq)):
	prob.append(freq[i]*100/total) 

cummalative=[] 
cummalative.append(prob[0]) 
for i in range(1,len(prob)):
	cummalative.append(prob[i]+cummalative[i-1])

random_numbers=[]
for i in range(N):
	random_numbers.append(floor(random.random()*100))

time_required=[]
for i in range(N):
	service=-1
 	for j in range(len(cummalative)):
		x=random_numbers[i] 
		prev=0
		if j!=0:
			prev=j-1
			if x>=cummalative[prev] and x<cummalative[j]:
				service=j-1
				break

			time_required.append(time[service])

start_time=0
patient_wait=[]
doctor_wait=[]
arrival=[]

for i in range(N): 
	arrival.append(i*30)
for i in range(N):
	if arrival[i]>start_time:
		doctor_wait.append(arrival[i]-start_time) 
		patient_wait.append(0) 
		start_time=arrival[i]+time_required[i]
	else: 
		patient_wait.append(start_time-arrival[i]) doctor_wait.append(0) start_time+=time_required[i]

for i in range(len(freq)):
	print(str(name[i])+" "+str(time[i])+" "+str(freq[i])+" "+str(prob[i])+" "+str(cummalative[i]))

for i in range(N):
	print(str(random_numbers[i])+" "+str(time_required[i])+" "+str(arrival[i])+""+str(patient_wait[i])+" "+str(doctor_wait[i]))

avg_doc=0
avg_pat=0
for i in range(N):
	avg_doc+=doctor_wait[i]
	avg_pat+=patient_wait[i] avg_doc/=N
	avg_pat/=N

print(str(avg_doc)+" "+str(avg_pat))