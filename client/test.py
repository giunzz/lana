import os, subprocess, filecmp

__location__ = os.path.dirname(os.path.realpath(__file__))

locationGit = 'C:\\Users\\tienp\\Desktop\\Hoc'

# subprocess.Popen([os.path.join(__location__, '00_10Tin_BTTH_Tonghop.pdf')], shell=True)
# subprocess.Popen(['fc', os.path.join(__location__, 'test.txt', os.path.join(__location__, 'test1.txt'), '/w')], shell=True)

import time

# time.sleep(10)

def joinPath(name1, name2):
    return os.path.join(name1, name2)

# os.system('git add . && git commit -m "sync" && git push -u origin quang')
# subprocess.run(["cd",  "&& git add . && git commit -m \"sync\" && git push -u origin quang" % location], shell=True)

temp = filecmp.cmp(os.path.join(__location__, 'log\\temp.log'), os.path.join(__location__, 'log\\examPull.log'), shallow=False)
print(temp)


with open(joinPath(__location__, 'log\\temp.log'), 'w') as wlog:
    subprocess.run(["cd", locationGit, "&&", "git", "pull", "origin", "quang"], stdout=wlog, stderr=wlog, shell=True)
    # wlog.close()



# with open(os.path.join(__location__, 'test.txt'), 'w') as wlog:
#     wlog.write('testttttttt')