import os, shutil, time
import checkSolution as cS
import killFileExe as kle
from createFile import delFile
from datetime import datetime
from threading import Thread

nameTarget = ''
direction = os.path.dirname(os.path.realpath(__file__))
dirFolderTest = ''
nameTargetExe = nameTargetCpp = nameTargetInp = nameTargetOut = ''
nameAns = 'ans.out'
timeStart = timeEnd = datetime.now()
getObjOfDir = os.listdir(direction)
logFile = 'Score.log'
cntAC = cntTest = timeLimit = 0

def createVariables(name, time):
    global nameTarget, nameTargetCpp, nameTargetExe, nameTargetInp, nameTargetOut, timeLimit
    nameTarget = name
    nameTargetExe = nameTarget + '.exe'
    nameTargetCpp = nameTarget + '.cpp'
    nameTargetInp = nameTarget + '.inp'
    nameTargetOut = nameTarget + '.out'
    timeLimit = time

def joinPath(name1, name2):
    return os.path.join(name1, name2)

def wLog(info): #define writeLog
    with open(joinPath(direction, logFile), 'a') as writeLog:
        writeLog.write(info)

def init():
    os.rename(joinPath(dirFolderTest, nameTargetOut), joinPath(dirFolderTest, nameAns))
    shutil.copyfile(joinPath(direction, nameTargetExe), joinPath(dirFolderTest, nameTargetExe))

def runfile():
    global timeStart, timeEnd
    os.chdir(dirFolderTest)
    timeStart = datetime.now()
    os.system('start /wait cmd /c %s' % joinPath(dirFolderTest, nameTargetExe))
    timeEnd = datetime.now()

def kill():
    kle.killFile(nameTargetExe)

def processingRun():
    checknonTLE = True
    try:
        thread1 = Thread(target=runfile)
        thread1.start()
        time.sleep(timeLimit + 1.0)
        if thread1.is_alive():
            kill()
    except Exception as e: print(e)
    else:
        print('Run file Success!')
    thread1.join()
    if float((timeEnd - timeStart).total_seconds()) > timeLimit:
        checknonTLE = False
    time.sleep(0.5)
    return checknonTLE

def Checker(name, time):
    global cntTest, dirFolderTest, cntAC
    createVariables(name, time)
    print("Target: %s \nDirectory: %s" % (nameTarget, direction))  
    with open(joinPath(direction, logFile), 'w') as writeLog:
        writeLog.write("Target: %s \nDirectory: %s\n" % (nameTarget, direction))
    for nameFolder in getObjOfDir:
        if os.path.isdir(joinPath(direction, nameFolder)) and nameFolder != '__pycache__':
            cntTest += 1
            dirFolderTest = joinPath(direction, nameFolder)
            init()
            print("%s:" % nameFolder, end=" ")
            wLog("%s: " % nameFolder)
            if not processingRun():
                wLog("TLE\n")
                delFile(dirFolderTest, nameTargetExe, nameTargetOut, nameAns)
                continue
            if not os.path.exists(joinPath(dirFolderTest, nameTargetOut)):
                wLog("No File Output Found\n")
                delFile(dirFolderTest, nameTargetExe, nameTargetOut, nameAns)
                continue
            wLog('%fs\n' % float((timeEnd - timeStart).total_seconds()))
            reqCheck = cS.checkSol(dirFolderTest, nameAns, nameTargetOut)
            if reqCheck == 'Accept':
                cntAC += 1
            wLog('%s\n' % reqCheck)
            delFile(dirFolderTest, nameTargetExe, nameTargetOut, nameAns)
    wLog('AC: %d/%d' % (cntAC, cntTest))
    os.remove(joinPath(direction, nameTargetExe))

if __name__ == "__main__":
    Checker('test', 1.0)
    pass