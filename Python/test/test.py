from threading import Thread
from datetime import datetime
import os, time

# def openfile():
#     os.system("D:/quang/c++/giun/test/test.exe")

# def pr():
#     print(1)

# try:
#     #t1 = threading.Thread(target=openfile)
#     t2 = Thread(target=pr)
#     #t1.start()
#     t2.start()
#     #t1.join()
#     t2.join()
# except:
#     print("error")

i = datetime.now()
while float((datetime.now() - i).seconds) <= 5.0:
    pass
print(float((datetime.now() - i).seconds))