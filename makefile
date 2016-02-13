all:
	mkdir bin
	g++ *.h *.cpp -Wall -Werror -ansi -pedantic
rshell:
	g++ *.h *.cpp -Wall -Werror -ansi -pedantic
