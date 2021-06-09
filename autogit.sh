#!/bin/sh
DATE=$(date +'%F %H:%M:%S')
DIR=/home/quang/Desktop/main/hoc
echo "Syncing: $DATE" > $DIR/autogit.log
cd /home/quang/Desktop/main/hoc && git pull origin quang && git add . && git commit -m "sync" 
cd /home/quang/Desktop/main/hoc && git push -u origin quang
cd /home/quang/Desktop/main/hoc && git pull origin quang && git add . && git commit -m "sync" && git push -u origin quang