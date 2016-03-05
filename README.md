# CS100 Winter 2016 Assignment 3

RSHELL is a custom Bash Shell Terminal
This program will execute commands as if commands were entered one
at a time into the bash terminal


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
test accepts flags "-e" which tests for file existence
		   "-d" which tests if directory and for existence
		   "-f" which tests if file is regular and for existence
test may be used in alternative format: [ -e /directory/file.ext ]
If no flag is specified for test, program will assume -e

Commmands can but used with single connectors or conenctors chained together
Connector "&&" will execute command after connector only if command before connector is successful
Connector "||" will execute command after connector only if command before connector fails
Connector ";" will simply execute next command following the semicolon

Anything after "#" symbol will be considered a comment


##Examples:
```
$ echo one && test -e /test/readme.test
one
(true)

$ asdfg || echo two
two

$ echo one; echo two
one
two

$ echo string #this is a comment
string
```

##Bugs:

There are files for the "Cd" command that changes directory but it is not implemented



