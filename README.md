```
  ___  ____  ___  _  _       ____  __  __  _   _  _    _____  _______  _____  _____
 |  _||  __||  _|| || |     |  __||  \/  || | | || |  |  _  ||__   __||  _  ||  _  |
 | |  | |_  | |_ | || |     | |_  |      || | | || |  | |_| |   | |   | | | || |_| |
 | |  |  _| |_  || || |     |  _| | |\/| || | | || |  |  _  |   | |   | | | ||    _|
 | |_ | |__  _| || || |_    | |__ | |  | || |_| || |_ | | | |   | |   | |_| || |\ \
 |___||____||___||_||___|   |____||_|  |_||_____||___||_| |_|   |_|   |_____||_| \_|

```

# Introduction

This tool has been made to emulate completely a binary executable file, through ESIL and the Radare2 engine. Although ESIL emulation already exists, that usually doesn’t finish because of the following main reasons:
- Libraries and APIs loaded dynamically.
- Syscalls not executed, so its results not applied.

# Requirements

The following requirements must be covered to run this tool:
- C++
- Make
- Radare2

The following C/C++ packages are needed to run this tools:
- r_socket (radare2)
- jsoncpp

# Compiling

The following commands have to be executed in a Linux system to compile that tool and create the executable file *cesil_emulator*:

```
git clone https://github.com/xos30/cesil_emulator.git
cd cesil_emulator/
make
```

# Execution

The file to run that tool is *cesil_emulator*, which can be executed with the following format and arguments:

```
usage: cesil_emulator file

Emulate an executable binary with ESIL & Radare2
```

# Improvements

**THIS TOOL IS ALREADY IN A DEVELOPMENT PHASE**

There are some possible implementations which would improve the tool to achieve that more and more executable files could finish the emulation, without reach invalid memory addresses or keep in infinite loops.

However, the main way to improve this tool is implementing more API functionalities. It’s possible to just implement functions of one already existing API in the *api_implementations/* folder or create another API class and load this in the *main.cxx* file.

This tool will supports more architectures and files soon.