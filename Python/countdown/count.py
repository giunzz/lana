from datetime import datetime
import time, os

secForPrepare = 2
minForPrepare = 0.5

def printMsgSec(msg, diff):
    while diff >= 0:
        print(msg)
        print(int(diff))
        print('\a')
        diff -= 0.2
        time.sleep(0.2)
        os.system('cls')

def printMsgMin(msg, diff):
    timeStart = timeEnd = datetime.now()
    while int((timeEnd - timeStart).total_seconds()) <= diff * 60:
        print(msg)
        diffTime = timeEnd - timeStart
        print(time.strftime('%H:%M:%S', time.gmtime(int(diffTime.total_seconds()))))
        time.sleep(0.5)
        os.system('cls')
        timeEnd = datetime.now()

msgPrepareBySec = ' seconds to prepare'
msgPrepareByMin = ' minutes to prepare'

# printMsgMin(str(minForPrepare) + msgPrepareByMin, minForPrepare)
# printMsgSec(str(secForPrepare) + msgPrepareBySec, secForPrepare)
print('\a')