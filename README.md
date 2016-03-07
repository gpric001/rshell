# CS100 Winter 2016 Assignment 3

RSHELL is a custom Bash Shell Terminal. This program will execute commands
as if commands were entered one at a time into the terminal.
That is, one output per line.

##Installation:
```
$ git clone  https://github.com/yourusername/rshell.git
$ cd rshell
$ git checkout hw2
$ make
$ bin/rshell
```

##Features:
	
Runs executables from bash's /bin directory, such as "ls" and "pwd"

Built in "echo" command that echo's parameter

Built in "exit" command to close shell

Built in "test" command that tests files, given flag and path

test accepts flags:
```
	 "-e" tests for file existence

 	 "-d" tests if directory and for existence

	 "-f" tests if file is regular and for existence
```
test may be used in alternative format: [ -e /directory/file.ext ]

If no flag is specified for test, program will assume "-e"


Commands can but used with single connectors or connectors chained together

Connector "&&" will execute command after connector only if command before connector is successful

Connector "||" will execute command after connector only if command before connector fails

Connector ";" will simply execute next command following the semicolon

Anything after "#" symbol will be considered a comment

Parenthesis may also be used to group commands or to alter precedence of connectors


##Examples:
```
$ echo one && test -e /test/readme.text
one
(true)

$ asdfg || echo two
two

$ echo one; echo two
one
two

$ echo string #this is a comment
string

$ (echo one && echo two) || (echo three && echo four)
one
two
```

##Bugs:

There are files for the "Cd" command that changes directory but it is not implemented

If a failed command is run before the "||" connector, a failed execution message will be printed twice.

Warning: not using proper format for input may result in errors.

