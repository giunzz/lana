import checker as cK
import createFile as cF
import os

# timeLimit = 10.0
timeLimit = float(input('Set time limit: ')) #set time

cK.Checker(cF.createExe(), timeLimit)