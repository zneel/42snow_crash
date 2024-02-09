# Level 01

## Analysis

We followed the same process as for Level 00. We listed the files in the user's home directory and found nothing of interest. The same result occurred with the `find` command.

We explored numerous files until we opened `/etc/passwd`. One particular line caught our attention: `flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`.

The traditional crypt algorithm used by Linux to encrypt passwords is DES (see `man crypt`). To solve the hash, we used [hashcat](https://hashcat.net/wiki/doku.php?id=example_hashes):

```bash
hashcat -a 3 -m 1500 42hDRfypTqqnw --show
```

This command returned the string `abcdefg`, which was used to log in as `flag01`.

Executing the `getflag` command provided us with the flag: `f2av5il02puano7naaf6adaaf`.