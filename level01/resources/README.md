# Level 01

## Analysis

Same process as level 00. We listed file in his home and we found nothing, and this is same result with find command.

We explored many file until we opened `/etc/passwd`. One line got our attention: `flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`

The traditional crypt algorithm used by linux to crypt password is DES (man crypt). So we used [hashcat](https://hashcat.net/wiki/doku.php?id=example_hashes) to solve the hash.

```bash
hashcat -a 3 -m 1500 42hDRfypTqqnw --show
42hDRfypTqqnw:abcdefg
```
It returned `abcdefg` string, that used to login on `flag01`.

The getflag command gives us the flag: `f2av5il02puano7naaf6adaaf`
