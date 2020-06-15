import os
import subprocess
import time
import win32com.client
import signal

wmi=win32com.client.GetObject('winmgmts:')


def getpid(process_name):
    import os
    return [item.split()[1] for item in os.popen('tasklist').read().splitlines()[4:] if process_name in item.split()]

def killFile(name):
    for p in wmi.InstancesOf('win32_process'):
        if p.Name == name:
            process_id = getpid(name)
            if len(process_id) > 1:
                for x in process_id:
                    pid = int(x)
                    os.kill(pid, signal.SIGTERM)

            else:
                pid = int("".join(getpid(name)))
                os.kill(pid, signal.SIGTERM)

if __name__ == "__main__":
    killFile('test.exe')
