We found nothing in his home and it seems this user does have access to other home's user.
So we tried to found all files own by user flag00 to see if there is a directory where we can can find something

```
find / -user flag00
```

And we found many file that users own but on most of them we don't have read right except 2 files:
- /usr/sbin/john
- /rofs/usr/sbin/john

Both of them contain the same content: `cdiiddwpgswtgt`

We simply used an automatic tool to view different result output to see if one of the results seemed correct to us.

https://www.cachesleuth.com/multidecoder/

We found that Rot 15 was used to generate this string from `nottoohardhere`