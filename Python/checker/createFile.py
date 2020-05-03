import os

currentDirectory = os.path.dirname(os.path.realpath(__file__))
nameTarget = ''

def createExe():
    for nameFileCpp in os.listdir(currentDirectory):
        if nameFileCpp.endswith('.cpp'):
            nameTarget = ''.join(nameFileCpp.split('.cpp'))
            try:
                os.system('cd "%s" && g++ %s -o %s' % (currentDirectory, os.path.join(currentDirectory, nameFileCpp), os.path.join(currentDirectory, nameTarget + '.exe')))
            except:
                print('Build file Error!')
    return nameTarget

def delFile(directoryTest, nameExe, nameOut, nameAns):
    try:
        os.remove(os.path.join(directoryTest, nameExe))
    except:
        pass
    try:
        os.remove(os.path.join(directoryTest, nameOut))
    except:
        pass
    try:
        os.rename(os.path.join(directoryTest, nameAns), os.path.join(directoryTest, nameOut))
    except:
        pass

if __name__ == "__main__":
    delFile(os.path.join(currentDirectory, 'test0'), 'test.exe', 'test.out', 'ans.out')