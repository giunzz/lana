import checker as cK
import createFile as cF
import os

timeLimit = 2.0
# timeLimit = float(input('Set time limit: ')) #set time

cK.Checker(cF.createExe(), timeLimit)