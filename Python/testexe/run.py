import checker as cK
import createFile as cF
import os

# exec(open("os").read())

timeLimit = 1.0
# timeLimit = float(input('Set time limit: ')) #set time

cK.Checker(cF.createExe(), timeLimit)