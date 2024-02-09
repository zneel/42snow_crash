# Level 09

## Analysis

In the user's home directory, we found two files:

```bash
level09@SnowCrash:~$ ll
total 24
dr-x------ 1 level09 level09  140 Mar  5  2016 ./
d--x--x--x 1 root    users    340 Aug 30  2015 ../
-r-x------ 1 level09 level09  220 Apr  3  2012 .bash_logout*
-r-x------ 1 level09 level09 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x 1 flag09  level09 7640 Mar  5  2016 level09*
-r-x------ 1 level09 level09  675 Apr  3  2012 .profile*
----r--r-- 1 flag09  level09   26 Mar  5  2016 token
```

The first file is a binary, which requires an argument to execute:

```bash
level09@SnowCrash:~$ ./level09
You need to provide only one arg.
```

The second file is a `token` file containing a string with unknown characters:

```bash
level09@SnowCrash:~$ cat token
f4kmm6p|=�p�n��DB�Du{��
```

We deduced that the binary transforms the argument given into a string using an unknown algorithm. We managed to create a C script to brute-force the input to the binary, checking that the output matches the content of the `token` file.

**Note**: "Don't judge a book by its cover."
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fptr = fopen("/home/user/level09/token", "r");
  char token[256];
  fgets(token, 256, fptr);
  char res[2048] = "a";
  int i = 0;
  while (res[i] < 127) {
    FILE *fp;
    char path[1035];
    char commandwitharg[2048];
    bzero(commandwitharg, 2048);
    sprintf(commandwitharg, "/home/user/level09/level09 '%s'", res);
    fp = popen(commandwitharg, "r");
    if (fp == NULL) {
      printf("Failed to run command\n");
    }
    fgets(path, sizeof(path), fp);
    if (token[i] == path[i]) {
      res[++i] = 33;
    } else
      res[i]++;
    printf("res=%s\n", res);
    pclose(fp);
  }
  return 0;
}
```
The C script provided attempts to reverse-engineer or guess the transformation applied by the binary. After extensive trial and error, the correct input that matches the `token` file content was determined to be `f3iji1ju5yuevaus41q1afiuq`. This input, presumably, is the password or a key that can be used to authenticate as `flag09` and then execute `getflag` to retrieve the flag.

**Type of Exploit**: Binary Analysis / Reverse Engineering