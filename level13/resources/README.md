# Level 13

## Analysis

In the home directory, we encountered a binary named `level13`. Attempting to execute this binary resulted in a message indicating a UID mismatch:

```sh
level13@SnowCrash:~$ ./level13
UID 2013 started us but we we expect 4242
```

This situation suggested a security mechanism within the binary that restricts execution based on the user's UID. Specifically, the binary is configured to proceed only when executed by a user with UID 4242.

To bypass this restriction, we employed the `LD_PRELOAD` environment variable, a technique for overriding library functions by specifying custom shared libraries to be loaded prior to the standard set. This method is particularly effective for manipulating the behavior of binaries without altering their code directly.

The strategy involves creating a shared library that overrides the `getuid` system call, which the binary likely uses to retrieve the UID of the executing user. By forcing `getuid` to return 4242, we can trick the binary into believing it is being executed by the intended user.

### Creating the Override Library

First, we wrote a C file designed to override `getuid`:

```c
// getuid.c
#include <unistd.h>
uid_t getuid(void)
{
    return 4242; // Return the expected UID
}
```

Next, we compiled this code into a shared library:

```sh
gcc -fPIC -shared -o libgetuid.so getuid.c
```

### Executing the Binary with the Override

With our shared library ready, we proceeded to execute the `level13` binary under `gdb`, setting `LD_PRELOAD` to our custom library to ensure our `getuid` is invoked instead of the standard library's:

```sh
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
(gdb) set environment LD_PRELOAD /tmp/libgetuid.so
(gdb) r
Starting program: /home/user/level13/level13
your token is 2A31L79asukciNyi8uppkEuSx
[Inferior 1 (process 26970) exited with code 050]
(gdb)
```

Through this method, we successfully bypassed the UID check implemented by the `level13` binary, allowing us to execute it as if we were the user with UID 4242 and retrieve the token: `2A31L79asukciNyi8uppkEuSx`.