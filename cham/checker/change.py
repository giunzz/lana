import os

for i in os.listdir():
    lists = i.split('.')
    if lists[0] == 'input':
        # os.system('mkdir test' + lists[1] + ' && rename ' + i + ' test' + lists[1] + '/ruou.inp')
        os.system('mkdir test' + lists[1])
        os.replace(i, 'test' + lists[1] + '/power3.inp')
        print(i)
    elif lists[0] == 'output':
        print(i)
        os.replace(i, 'test' + lists[1] + '/power3.out')