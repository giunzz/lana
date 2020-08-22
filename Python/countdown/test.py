from datetime import datetime
import time

timeStart = datetime.now()
print(timeStart)
timeStart += 10
print(timeStart)
time.sleep(1)
timeEnd = datetime.now()
# print(timeEnd - timeStart)
diffTime = timeEnd - timeStart
# print(time.strftime('%H:%M:%S', time.gmtime(int(diffTime.total_seconds()))))