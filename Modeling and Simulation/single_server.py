import random 
import math 

s=[]
N=10

def generate_random(): 
	x=random.random() 
	x=x*50+1 
	x=math.floor(x) 
	return x

for i in range(0,N): 
	x=generate_random() 
	temp=[] 
	temp.append(x) 
	x=generate_random() 
	temp.append(x) 
	s.append(temp)

s.sort() 
print(s)
 
cur_time=0
i=0 
service_start=[] 
service_end=[] 

while(i<N):
	if(cur_time>=s[i][0]): 
		service_start.append(cur_time) 
		cur_time+=s[i][1] 
		service_end.append(cur_time)
	else:
		cur_time=s[i][0] 
		service_start.append(cur_time) 
		cur_time+=s[i][1] 
		service_end.append(cur_time)
	i+=1

print(service_start) 
print(service_end)