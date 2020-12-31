import os, filecmp
from distutils.dir_util import copy_tree
from time import sleep
from datetime import datetime

__location__ = os.path.dirname(os.path.realpath(__file__))
global locationGit

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
    os.system('cd %s && git pull origin quang' % locationGit)

def gitPush():
    os.system('cd %s && gts quang' % locationGit)

def statusConnect():
    open(joinPath(__location__, 'ping.txt'), 'w')
    while True:
        gitPush()
        readPing = open(joinPath(__location__, 'ping.txt'), 'r')
        content = readPing.read()
        content.split()
        if len(content):
            break
        sleep(10)

def statusTasks():
    cprTasksTemp = filecmp.dircmp(joinPath(__location__, 'tasks'), joinPath(__location__, 'temp'))
    dirTasks = joinPath(__location__, 'tasks')
    dirTemp = joinPath(__location__, 'temp')
    checkStatus = 0
    if len(cprTasksTemp.left_only):
        copy_tree(dirTasks, dirTemp)
        checkStatus = 1
    return checkStatus

if __name__ == "__main__":
    # getLocationGit()
    # print(locationGit)
    statusConnect()
