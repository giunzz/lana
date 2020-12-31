import os, subprocess, filecmp

__location__ = os.path.dirname(os.path.realpath(__file__))

location = 'C:\\Users\\tienp\\Desktop\\Hoc'

# subprocess.Popen([os.path.join(__location__, '00_10Tin_BTTH_Tonghop.pdf')], shell=True)
# subprocess.Popen(['fc', os.path.join(__location__, 'test.txt', os.path.join(__location__, 'test1.txt'), '/w')], shell=True)

import time

# time.sleep(10)

tmp = filecmp.dircmp(os.path.join(__location__, 'tasks'), os.path.join(__location__, 'temp'))

print(len(tmp.left_only))

# with open(os.path.join(__location__, 'test.txt'), 'w') as wlog:
#     wlog.write('testttttttt')