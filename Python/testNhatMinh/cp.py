import os
import sys

def getCommand():
    return (sys.argv)

def getFuncion(command):
    return (command[1])

def getProblemName(command):
    problem = ""
    for i in range(len(command[2])):
        n = len(command[2])
        id = n - i - 1
        if (command[2][id] == "/"):
            break
        else:
            problem = command[2][id] + problem
    return (problem)

def makeFunction(command):
    directory = os.getcwd() + "/" + command[2]
    isExist = os.path.exists(directory)

    if (isExist):
        print("Directory exist")
    else:
        os.system("mkdir -p " + directory)

    templates = os.listdir("templates")
    for file in templates:
        name = ""
        ext = ""
        id = 0
        for i in range(len(file)):
            if (file[i] == "."):
                id = i;
                break
            else:
                name += file[i]
        for i in range(id, len(file)):
            ext = ext + file[i]
        if (name == "task"):
            os.system("cp templates/" + file + " " + directory + "/" + getProblemName(command) + ext)
        else:
            os.system("cp templates/" + file + " " + directory)

def updateFunction(command):
    user = command[3]
    directory = os.getcwd() + "/jud-server/users/" + user
    isExist = os.path.exists(directory)
    if (isExist):
        print("user exist")
    else:
        os.system("mkdir " + directory)
    taskDir = os.getcwd() + "/" + command[2] + "/" + getProblemName(command) + ".cpp"
    os.system("cp " + taskDir + " " + directory)

def judFunction(command):
    user = command[3]
    problems = os.getcwd() + "/jud-server/users/" + user + "/" + getProblemName(command) + ".cpp"
    checkers = os.getcwd() + "/jud-server/checkers/" + getProblemName(command) + ".cpp"
    problemsExist = os.path.exists(problems)
    checkersExist = os.path.exists(checkers)
    if (problemsExist == False):
        print("Problems are not exist in jud-server! You may need to update your solution!")
    if (checkersExist == False):
        print("Checkers are not exist in jud-server! Wait for update checkers.")
    if (problemsExist == True and checkersExist == True):
        judSystem = os.getcwd() + "/jud-server/jud-system.py"
        os.system("python3 " + judSystem)

def judUpdateFunction(command):
    directory = os.getcwd() + "/" + command[2] + "/checker.cpp"
    target = os.getcwd() + "/jud-server/checkers/" + getProblemName(command) + ".cpp"
    os.system("cp " + directory + " " + target)

command = getCommand()
function = getFuncion(command)

if (function == "make"):
    makeFunction(command)
elif (function == "update"):
    updateFunction(command)
elif (function == "jud"):
    judFunction(command)
elif (function == "jud-update"):
    judUpdateFunction(command)
else:
    print("error")
