from random import seed
from random import randint
import os
seed(1)
for tt in range(50):
	s=str(tt)
	if len(s)==1: s='0'+s
	s='test'+s
	if not os.path.exists(s): os.mkdir(s)
	n=(tt+1)*(randint(0,20)+1)
	if(tt>45): n=1000
	f=open(s+'/BeautP.inp',"w")
	f.write(str(n)+'\n')
	for i in range(n):
		x= (tt+1)*(randint(0,19)+1)
		if tt%2 ==0: x=x//2+1
		if tt%5 ==0: x=x//3+1
		if tt%13==0: x=x//13+1

		f.write(str(x)+' ')
	f.close()