from datetime import datetime
from colorama import Fore, init
import time, os, win32gui

# test
# secForPrepare = 5
# minForPrepare = 0.2
# hoursForTask = 0.005

secForPrepare = 5
minForPrepare = 10
hoursForTask = 2

def printMsgSec(msg, diff):
    os.system('cls')
    print(msg)
    while diff > 0:
        print(str(int(diff)) + '\a\r', end='')
        diff -= 1
        time.sleep(1)

def printMsgMin(msg, diff):
    timeStart = timeEnd = datetime.now()
    os.system('cls')
    print(msg, end=' ')
    print(time.strftime('%H:%M:%S', (time.gmtime(diff * 60))))
    while int((timeEnd - timeStart).total_seconds()) <= diff * 60:
        diffTime = timeEnd - timeStart
        print(time.strftime('%H:%M:%S', time.gmtime(int(diffTime.total_seconds()))) + '\r', end='')
        time.sleep(1)
        timeEnd = datetime.now()

msgPrepareBySec = ' seconds to prepare'
msgPrepareByMin = ' minutes to prepare'
msgDoTasks = ' hours to do the task'

os.system('cls')
# os.system('mode con: cols=35 lines=2')
hwnd = win32gui.GetForegroundWindow()
win32gui.MoveWindow(hwnd, 0, 0, 355, 75, True)
init()
print(Fore.GREEN + '\a');
printMsgMin(str(minForPrepare) + msgPrepareByMin, minForPrepare)
printMsgSec(str(secForPrepare) + msgPrepareBySec, secForPrepare)
printMsgMin(str(hoursForTask) + msgDoTasks, hoursForTask * 60)
print('Time Ended!')
for i in range(10):
    print('\a', end='')
print(Fore.RESET)