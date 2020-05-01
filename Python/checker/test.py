import os

direction = dirFolderTest = os.path.dirname(os.path.realpath(__file__))
direction = os.path.join(direction, 'test0')
name = 'test.exe'
print(os.path.join(direction, name))
os.system(os.path.join(direction, name))