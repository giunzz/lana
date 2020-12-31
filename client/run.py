import os

__location__ = os.path.dirname(os.path.realpath(__file__))
global locationGit

def joinPath(name1, name2):
    return os.path.join(name1, name2)

def getLocationGit():
    global locationGit
    listLoca = __location__.split('\\')
    listLoca.pop(len(listLoca) - 1)
    listLoca[0] = listLoca[0] + '\\'
    locationGit = os.path.join(*listLoca)

if __name__ == "__main__":
    getLocationGit()
    print(locationGit)
