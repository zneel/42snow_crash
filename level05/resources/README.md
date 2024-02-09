# Level 05

## Analysis

Using the command `find / -user flag05 -type f -exec ls -lahh {} \; 2> /dev/null`, we searched for files owned by `flag05`. This led us to discover a bash script that is executed at regular intervals within the `/opt/openarenaserver` directory. To exploit this, we implemented a simple script that we placed in /opt/openarenaserver and waited for the interval to pass.

```sh
getflag > /tmp/out
```

After waiting for the script's execution interval to pass, we checked `/tmp/out` and found the flag.