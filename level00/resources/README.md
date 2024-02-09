# Level 00

## Analysis

After logging onto the VM with the login credentials `level00:level00`, we listed the files in the home directory of the user using the command:

```sh
ls -la
```

We did not find any clues in these files.

Next, we attempted to identify all files owned by `flag00` by using the `find` command:

```sh
find / -user flag00 2>/dev/null
find / -group flag00 2>/dev/null
```

We observed that two files were output from these commands: `/usr/sbin/john` and `/rofs/usr/sbin/john`, both containing the text `cdiiddwpgswtgt`.

We hypothesized that this string represents a weak password encoded with a simple algorithm. Therefore, we attempted to decrypt it using the website `https://www.cachesleuth.com/multidecoder/`. It appears that applying ROT15 to this string yields the English words `nottoohardhere`.

Subsequently, we tried to log in as `flag00` using this password, and it was successful. The final step involved executing the command `getflag`.
