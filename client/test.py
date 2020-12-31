import os, subprocess, filecmp

__location__ = os.path.dirname(os.path.realpath(__file__))

locationGit = 'C:\\Users\\tienp\\Desktop\\Quang\Hoc\\client'

# subprocess.Popen([os.path.join(__location__, '00_10Tin_BTTH_Tonghop.pdf')], shell=True)
# subprocess.Popen(['fc', os.path.join(__location__, 'test.txt', os.path.join(__location__, 'test1.txt'), '/w')], shell=True)

import time

# time.sleep(10)

def joinPath(name1, name2):
    return os.path.join(name1, name2)

# os.system('git add . && git commit -m "sync" && git push -u origin quang')
# subprocess.run(["cd",  "&& git add . && git commit -m \"sync\" && git push -u origin quang" % location], shell=True)



tmp = subprocess.run(['fc', joinPath(locationGit, 'ping.txt'), joinPath(locationGit, 'test.txt'), '/w'], shell=True)
print(tmp.returncode)


# with open(os.path.join(__location__, 'test.txt'), 'w') as wlog:
#     wlog.write('testttttttt')