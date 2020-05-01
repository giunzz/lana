from threading import Thread
from datetime import datetime
import os, time

def test():
    print(1)


for i in range(2):
    thread1 = Thread(target=test)
    thread1.start()
    thread1.join()
    time.sleep(0.5)
