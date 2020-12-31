import os, filecmp, subprocess
from distutils.dir_util import copy_tree
from shutil import copyfile
from time import sleep
from datetime import datetime

__location__ = os.path.dirname(os.path.realpath(__file__))
global locationGit
listProbs = []
examplePull = 'examPull.log'

def joinPath(name1, name2):
    return os.path.join(name1, name2)

def wRunClient(info):
    now = datetime.now().strftime('%d/%m/%Y %H:%M:%S ---> ')
    with open(joinPath(joinPath(__location__, 'log'), 'status.log'), 'a') as wLog:
        wLog.write(now + info + '\n')

def getLocationGit():
    global locationGit
    listLoca = __location__.split('\\')
    listLoca.pop(len(listLoca) - 1)
    listLoca[0] = listLoca[0] + '\\'
    locationGit = os.path.join(*listLoca)

def gitPull():
    with open(joinPath(__location__, 'log\\temp.log'), 'w') as wlog:
        subprocess.run(["cd", locationGit, "&&", "git", "pull", "origin", "quang"], stdout=wlog, stderr=wlog, shell=True)

def gitPush():
    gitPull()
    with open(joinPath(__location__, 'log\\temp.log'), 'w') as wlog:
        subprocess.run(["cd", locationGit, "&&", "git", "add", ".", "&&", "git", "commit", "-m", "\"sync\"", "&&", "git", "push", "-u", "origin", "quang"], stdout=wlog, stderr=wlog, shell=True)

def statusConnect():
    open(joinPath(__location__, 'ping.txt'), 'w')
    gitPush()
    while True:
        gitPull()
        readPing = open(joinPath(__location__, 'ping.txt'), 'r')
        content = readPing.read().split()
        readPing.close()
        if len(content):
            break
        sleep(10)

def statusProb():
    global listProbs
    # direcLog = joinPath(__location__, 'log')
    while not os.path.exists(joinPath(__location__, 'probs')) or len(os.listdir(joinPath(__location__, 'probs'))) == 0:
        gitPull()
        sleep(10)
    # while filecmp.cmp(joinPath(direcLog, examplePull), joinPath(direcLog, 'temp.log')):
    #     gitPull()
    #     sleep(10)
    readPing = open(joinPath(__location__, 'ping.txt'), 'r')
    listProbs = readPing.read().split()
    readPing.close()

def statusTasks():
    dirTasks = joinPath(__location__, 'tasks')
    dirTemp = joinPath(__location__, 'temp')
    checkStatus = 0
    for nameTask in os.listdir(dirTasks):
        # print(nameTask)
        splitTask = nameTask.split('.')
        if len(splitTask) == 2 and splitTask[1] == 'cpp' and splitTask[0] in listProbs:
            wlog = open(joinPath(__location__, 'log\\compare.log'), 'w')
            if (nameTask in os.listdir(dirTemp)) and not subprocess.run(['fc', joinPath(dirTasks, nameTask), joinPath(dirTemp, nameTask), '/w'], stdout=wlog, stderr=wlog, shell=True).returncode:
                continue
            if not nameTask in os.listdir(dirTemp):
                open(joinPath(dirTemp, nameTask), 'w')
            checkStatus = 1
            copyfile(joinPath(dirTasks, nameTask), joinPath(dirTemp, nameTask))
            wlog.close()
    return checkStatus

def waitGetRes():
    gitPull()
    direcLog = joinPath(__location__, 'log')
    # print(filecmp.cmp(joinPath(direcLog, examplePull), joinPath(direcLog, 'temp.log')))
    while filecmp.cmp(joinPath(direcLog, examplePull), joinPath(direcLog, 'temp.log')):
        gitPull()
        sleep(10)

def init():
    gitPull()
    with open(joinPath(__location__, 'log\\examPull.log'), 'w') as wlog:
        subprocess.run(["cd", locationGit, "&&", "git", "pull", "origin", "quang"], stdout=wlog, stderr=wlog, shell=True)

def run():
    wRunClient('Running')
    print('Running')

    try:
        getLocationGit()
    except Exception as e: wRunClient(str(e))
    else:
        wRunClient('Get location root folder: ' + locationGit)
    
    try:
        init()
    except Exception as e: wRunClient(str(e))
    else:
        wRunClient('Init Success')
    
    try:
        wRunClient('Trying connect server')
        print('Connecting to server')
        statusConnect()
    except Exception as e: wRunClient(str(e))
    else:
        wRunClient('Connected to server')
        print('Connected')
    
    try:
        wRunClient('Waiting for server')
        statusProb()
    except Exception as e: wRunClient(str(e))
    else:
        wRunClient('Received Problem and Start Contest')
        print('Start Contest')

    timeDo = [23, 35]
    try:
        while datetime.now().hour < timeDo[0] or (datetime.now().hour == timeDo[0] and datetime.now().minute <= timeDo[1]):
            if statusTasks():
                gitPush()
                wRunClient('Send tasks to server')
                print(datetime.now(), ' Detected tasks')
                try:
                    waitGetRes()
                except Exception as e: wRunClient(str(e))
                else:
                    wRunClient('Received result')
                    print('Received result')
            sleep(10)
    except Exception as e: wRunClient(str(e))
    else:
        wRunClient('Server Nice')
    wRunClient('End Contest and Off Server')
    print('End Contest')


if __name__ == "__main__":
    run()
