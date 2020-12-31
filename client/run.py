import os, filecmp, subprocess
from distutils.dir_util import copy_tree
from shutil import copyfile
from time import sleep
from datetime import datetime

__location__ = os.path.dirname(os.path.realpath(__file__))
global locationGit
listProbs = []

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
    while True:
        gitPush()
        readPing = open(joinPath(__location__, 'ping.txt'), 'r')
        content = readPing.read().split()
        if len(content):
            break
        sleep(10)

def statusProb():
    global listProbs
    while not os.path.exists(joinPath(__location__, 'probs')) or len(os.listdir(joinPath(__location__, 'probs'))) == 0:
        gitPull()
        sleep(10)
    readPing = open(joinPath(__location__, 'ping.txt'), 'r')
    listProbs = readPing.read().split()

def statusTasks():
    cprTasksTemp = filecmp.dircmp(joinPath(__location__, 'tasks'), joinPath(__location__, 'temp'))
    dirTasks = joinPath(__location__, 'tasks')
    dirTemp = joinPath(__location__, 'temp')
    checkStatus = 0
    for nameTask in cprTasksTemp.left_only:
        splitTask = nameTask.split('.')
        if len(splitTask) == 2 and splitTask[1] == '.cpp' and splitTask[0] in listProbs:
            checkStatus = 1
            copyfile(joinPath(dirTasks, nameTask), joinPath(dirTemp, nameTask))
    return checkStatus

if __name__ == "__main__":
    print(0)
    getLocationGit()
    # print(locationGit)
    print(1)
    statusConnect()
    print(2)
    statusProb()
    print(listProbs)
