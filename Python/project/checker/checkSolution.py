import os

def checkSol(directoryAns, fileAns, fileOut):
    fileTask = open(os.path.join(directoryAns, fileOut), 'r')
    fileSol = open(os.path.join(directoryAns, fileAns), 'r')
    lineAllTask = fileTask.readlines()
    numLine = 0
    for line in fileSol:
        if(numLine + 1 > len(lineAllTask)):
            return 'Wrong Ans at line %d' % (numLine + 1)
        lineTask = lineAllTask[numLine].split()
        lineSol = line.split()
        numLine += 1
        if(lineSol != lineTask):
            return 'Wrong Ans at line %d' % numLine
    if(numLine < len(lineAllTask)):
        return 'Wrong Ans at line %d' % (numLine + 1)
    return 'Accept'

if __name__ == "__main__":
    directoryAns = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'test0')
    fileAns = 'ans.out'
    fileOut = 'test.out'
    print(checkSol(directoryAns, fileAns, fileOut))