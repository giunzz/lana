import os
from subprocess import check_output

def getpid(process_name):
    pid = [int(i) for i in check_output(['pgrep', '-n', process_name]).split() if i.isdigit()]
    return str(pid[0])

def killFile(name):
    os.system('kill -9 ' + getpid(name))

if __name__ == "__main__":
    killFile('test1')
