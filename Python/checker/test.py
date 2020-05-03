from datetime import datetime
import time

startTime = datetime.now()
time.sleep(0.5)
endTime = datetime.now()
delta = endTime - startTime
print(delta.total_seconds())