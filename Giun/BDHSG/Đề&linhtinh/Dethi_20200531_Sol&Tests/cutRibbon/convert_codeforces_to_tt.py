import os
f=open("savett.txt","r")
data=f.read().split("Test")
f.close()
t=0
for d in data[1:]: 
	print("==========")
	x=d.split("\n")
	tt=str(t)
	if len(tt)==1: tt='0'+tt
	tt='test'+tt
	if(not os.path.exists(tt)): os.mkdir(tt)
	tt=tt+'/cutRibbon'
	print(tt)
	f=open(tt+".inp","w")
	f.write(x[2])
	f.close()
	f=open(tt+".out","w")
	f.write(x[4])
	f.close()
	print(x[2])
	print(x[4])
	t=t+1
	
