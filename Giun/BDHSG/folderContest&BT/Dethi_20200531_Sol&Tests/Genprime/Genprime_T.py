from random import seed
from random import randint
import os
seed(1)
for tt in range(20):
	s=str(tt)
	if len(s)==1: s='0'+s
	s='test'+s
	if not os.path.exists(s): os.mkdir(s)
	t=randint(0,10)+1
	f=open(s+'/genprime.inp',"w")
	f.write(str(t)+'\n')
	for i in range(t):
		while 1:
			n=randint(0,10000000*(tt+1)/2)+1
			m=randint(0,10000000*(tt+1)/2)+1
			if(n-m<=100000 and n>m): break
		f.write(str(m)+' '+str(n)+'\n')
	f.close()