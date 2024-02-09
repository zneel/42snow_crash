# Level 00

## Analysis

After loggued on VM with login passord level00:00, we listed file in home's user.

`ls -la`

We didn't find any clue in theses files.

We tried to get all file owned by flag00 by searching them with `find` command

```sh
find / -user flag00 2>/dev/null
...
find / -group flag00 2>/dev/null
```
We noticed that 2 files output from there command `/usr/sbin/john` and `/rofs/usr/sbin/john` and the content of them is `cdiiddwpgswtgt`

We supposed that it is a weak password using simple algo, so we tried to decrypt it on `https://www.cachesleuth.com/multidecoder/`
It seems rot15 on this string give english words `nottoohardhere`.

Then we attempt to login on flag00 with this password and it worked. The last step was to execute `getflag`
