from datetime import datetime
from colorama import Fore, Back, Style, init
import time, os, win32gui
from ctypes import windll, byref

# print('0.00005 hours to do the task')
# print('a')
# os.system('mode 0,29')

hwnd = win32gui.GetForegroundWindow()
# win32gui.MoveWindow(hwnd, 1367, 0, 300, 90, True)

# print()


win32gui.SetScrollInfo(hwnd, 3,0, 0)
# flags, hcursor, (x,y) = win32gui.GetCursorInfo()

# print(x, y)