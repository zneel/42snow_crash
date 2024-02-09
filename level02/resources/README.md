# Level 02

## Analysis

In the home directory of the user, we discovered a file named `level02.pcap`.

> A PCAP (Packet Capture) file is a binary format used to store captured network packet data during communication over a computer network. Packet capture tools like Wireshark typically generate these files.

We installed `wireshark` to open the file. It contains packets from a user attempting to connect to an unknown service. Careful analysis of each packet, specifically keyboard keys pressed by the user during connection attempts, revealed the following data when following the TCP stream:

```
..%..%..&..... ..#..'..$..&..... ..#..'..$.. .....#.....'........... .38400,38400....#.SodaCan:0....'..DISPLAY.SodaCan:0......xterm.........."........!........"..".....b........b....  B.
..............................1.......!.."......"......!..........."........"..".............   ..
.....................
Linux 2.6.38-8-generic-pae (::ffff:10.1.1.2) (pts/10)

..wwwbugs login: l.le.ev.ve.el.lX.X
..
Password: ft_wandr...NDRel.L0L
.
..
Login incorrect
wwwbugs login:
```

The service responded with an unauthorized request, indicating the user failed to correctly enter their password. Further analysis led us to deduce that the user attempted to delete some characters by pressing the `7f` key (DEL). Thus, we inferred the correct password to be `ft_waNDReL0L`.

Using this password to log in as `flag02` successfully provided us with the flag.