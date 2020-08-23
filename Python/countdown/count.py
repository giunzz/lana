from datetime import datetime
from colorama import Fore, Back, init
import time, os

# test
# secForPrepare = 5
# minForPrepare = 0.2
# hoursForTask = 0.005

secForPrepare = 5
minForPrepare = 10
hoursForTask = 2

def printMsgSec(msg, diff):
    while diff > 0:
        print(msg)
        print(int(diff))
        print('\a', end='')
        diff -= 1
        time.sleep(1)
        os.system('cls')

def printMsgMin(msg, diff):
    timeStart = timeEnd = datetime.now()
    while int((timeEnd - timeStart).total_seconds()) <= diff * 60:
        print(msg, end=' ')
        print(time.strftime('%H:%M:%S', (time.gmtime(diff * 60))))
        diffTime = timeEnd - timeStart
        print(time.strftime('%H:%M:%S', time.gmtime(int(diffTime.total_seconds()))))
        time.sleep(0.5)
        os.system('cls')
        timeEnd = datetime.now()

msgPrepareBySec = ' seconds to prepare'
msgPrepareByMin = ' minutes to prepare'
msgDoTasks = ' hours to do the task'

os.system('cls')
init()
print(Fore.GREEN + '\a');
printMsgMin(str(minForPrepare) + msgPrepareByMin, minForPrepare)
printMsgSec(str(secForPrepare) + msgPrepareBySec, secForPrepare)
printMsgMin(str(hoursForTask) + msgDoTasks, hoursForTask * 60)
print('Time Ended!')
for i in range(10):
    print('\a', end='')
print(Fore.RESET)