import os, shutil, time
import killFileExe as kle
from datetime import datetime
from threading import Thread

nameTarget = 'test'
direction = os.path.dirname(os.path.realpath(__file__))
dirFolderTest = ""
nameTargetExe = nameTarget + '.exe'
nameTargetCpp = nameTarget + '.cpp'
nameTargetInp = nameTarget + '.inp'
nameTargetOut = nameTarget + '.out'
nameAns = 'ans.out'
timeStart = timeEnd = datetime.now()
getObjOfDir = os.listdir(direction)
logFile = 'Score.log'

def joinPath(name1, name2):
    return os.path.join(name1, name2)

def wLog(info): #define writeLog
    with open(joinPath(direction, logFile), 'a') as writeLog:
        writeLog.write(info)

def init(name):
    os.rename(joinPath(dirFolderTest, nameTargetOut), joinPath(dirFolderTest, nameAns))
    shutil.copyfile(joinPath(direction, nameTargetExe), joinPath(dirFolderTest, nameTargetExe))

def runfile():
    #print(dirFolderTest)
    os.chdir(dirFolderTest)
    timeStart = datetime.now()
    os.system(joinPath(dirFolderTest, nameTargetExe))
    timeEnd = datetime.now()

def kill():
    kle.killFile(nameTargetExe)

def processingRun():
    checknonTLE = True
    try:
        thread1 = Thread(target=runfile)
        thread1.start()
        while float((datetime.now() - timeStart).seconds) < 1.0:
            pass
        if thread1.is_alive():
            kill()
    except Exception as e: print(e)
    else:
        print('Run file Success!')
    thread1.join()
    if float((timeEnd - timeStart).seconds) >= 1.0:
        checknonTLE = False
    time.sleep(0.5)
    return checknonTLE

if __name__ == "__main__":
    print("Target: %s \nDirectory: %s" % (nameTarget, direction))  
    with open(joinPath(direction, logFile), 'w') as writeLog:
        writeLog.write("Target: %s \nDirectory: %s\n" % (nameTarget, direction))
    for nameFolder in getObjOfDir:
        if os.path.isdir(joinPath(direction, nameFolder)) and nameFolder != '__pycache__':
            dirFolderTest = joinPath(direction, nameFolder)
            init(nameFolder)
            print("%s:" % nameFolder, end=" ")
            wLog("%s:" % nameFolder)
            if not processingRun():
                wLog("TLE\n")
                pass
            wLog('%f\n' % float((timeEnd - timeStart).seconds))