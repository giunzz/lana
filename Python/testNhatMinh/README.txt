kit discription: create a kit for cp-ers
kit function: 
    make: create a folder ar a directory with some files
    update: update a problem to jud-server
    jud: check the problem
    jud-update: update a checker for a problem to jud-server

* make:
template: python3 cp.py make <directory>

* update:
template: python3 cp.py update <directory> <username>

* jud-update:
template: python3: cp.py jud-update <directory>

* jud:
template: python3 cp.py jud <directory> <username>

How to use?
- push file cp.py in your cpp-source codes
- create a jud-server folder contain 2 sub-folder: users and checkers
- push jud-system in jud-server folder
- in your terminal (using bash or LINUX/UNIX) type command