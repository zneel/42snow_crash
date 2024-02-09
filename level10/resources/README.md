# Level 10

## Analysis

The user's home directory contains two files: a binary and a file named `token` that we are unable to read.

```bash
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

Attempting to execute the binary reveals it requires a file and a host to operate:

```bash
level10@SnowCrash:~$ ./level10
./level10 file host
        sends file to host if you have access to it
```

Investigating the binary with `strings`, we found indications it attempts to connect to a server on port `6969`:

```bash
level10@SnowCrash:~$ strings level10
..
%s file host
    sends file to host if you have access to it
Connecting to %s:6969 ..
Unable to connect to host %s
.*( )*.
Unable to write banner to host %s
Connected!
Sending file ..
Damn. Unable to open file
Unable to read from file: %s
wrote file!
You don't have access to %s
..
```

The binary checks if the user has access to a file before sending it. We created a script to exploit a race condition using a symlink. Initially, the binary verifies access to the symlink pointing to a file we own, then we switch the symlink to point to the `token` file.

The exploitation involves three scripts:
1. A script to continuously send a file using the binary.
2. A script to listen on port 6969.
3. A script to continuously switch the symlink target between a fake token and the real `token` file.

Logging in as `flag10` with the flag `woupa2yuojeeaaed06riuj63c` allowed us to retrieve the final flag.

**Type of Exploit**: Race Condition Exploitation

## Documentation

- [How is using `access()` opening a security hole?](https://security.stackexchange.com/questions/42659/how-is-using-acces-opening-a-security-hole) - Discusses the security implications of using the `access()` function.
- [Race Condition Vulnerability Lab](https://repository.root-me.org/Exploitation%20-%20Système/EN%20-%20Race%20Condition%20Vulnerability%20Lab.pdf) - Provides a detailed explanation of race condition vulnerabilities and how they can be exploited.