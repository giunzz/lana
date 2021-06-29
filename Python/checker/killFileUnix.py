import os

def getpid(process_name):
    return os.system('pgrep -n ' + process_name)

def killFile(name):
    print('kill -9 ' + str(getpid(name)))
    os.system('kill -9 ' + str(getpid(name)))

if __name__ == "__main__":
    killFile('test1')
