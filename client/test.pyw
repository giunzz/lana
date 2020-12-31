import os, subprocess, filecmp

__location__ = os.path.dirname(os.path.realpath(__file__))

location = 'C:\\Users\\tienp\\Desktop\\Hoc'

# subprocess.Popen([os.path.join(__location__, '00_10Tin_BTTH_Tonghop.pdf')], shell=True)
# subprocess.Popen(['fc', os.path.join(__location__, 'test.txt', os.path.join(__location__, 'test1.txt'), '/w')], shell=True)

import time

# time.sleep(10)


os.system('git add . && git commit -m "sync" && git push -u origin quang')

# with open(os.path.join(__location__, 'test.txt'), 'w') as wlog:
#     wlog.write('testttttttt')