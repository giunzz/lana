#!/bin/bash
DATE=$(date +'%F %H:%M:%S')
DIR=~/Desktop/main/hoc
echo "Syncing: $DATE" > $DIR/autogit.log
cd ~/Desktop/main/hoc && git pull origin quang && git add . && git commit -m "sync" 
cd ~/Desktop/main/hoc && git push -u origin quang
cd ~/Desktop/main/hoc && git pull origin quang && git add . && git commit -m "sync" && git push -u origin quang