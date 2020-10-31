import os
from shutil import copyfile
from glob import glob
lfd=glob("TEST*")
if len(lfd)==0:
	lfd=glob("$*")
print(lfd)
fn=glob(lfd[0]+'\*.inp')[0]
fn=fn[len(lfd[0])+1:-4]
i=0

os.mkdir('input')
os.mkdir('output')
for fd in lfd:
	fni=fd+'/'+fn+'.inp'
	fno=fd+'/'+fn+'.out'
	
	stt=str(i)
	if i<10:
		stt='0'+stt;
	i+=1
	copyfile(fni,'input/input'+stt+'.txt')
	copyfile(fno,'output/output'+stt+'.txt')
	print(fni,fno)