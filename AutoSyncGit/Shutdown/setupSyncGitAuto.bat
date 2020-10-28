@echo off
cls
for %%i in (/Shutdown/*.py) do python C:/Shutdown/%%i
exit