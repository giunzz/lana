import os, subprocess, sys

direction = dirFolderTest = os.path.dirname(os.path.realpath(__file__))
name = 'test.exe'
# #print(os.path.join(direction, name))
# out = sys.stdout
# inp = sys.stdin
# sys.stdout = open(os.path.join(direction, 'test.out'), 'w')
# sys.stdin = open(os.path.join(direction, 'test.inp'), 'r')
#print('start /wait cmd /c %s' % os.path.join(direction, name))
os.chdir(direction)
os.system(os.path.join(direction, name))
#subprocess.call([os.path.join(direction, name)])