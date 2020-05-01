from threading import Thread
from datetime import datetime
import os, time

#print(os.getcwd())
#os.listdir
testdirect = os.path.dirname(os.path.realpath(__file__))
os.rename(os.path.join(testdirect, 'test.txt'), os.path.join(testdirect, 'testcopy.txt'))
print(testdirect)
# p = os.listdir(testdirect)
# for i in p:
#     if os.path.isdir(os.path.join(testdirect, i)):
#         print(i)
#print(p)
