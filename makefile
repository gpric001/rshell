CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic
SOURCES=
OBJECTS=And.o BinCmd.o Cd.o Echo.o Exit.o main.o Or.o Parser.o Rshell.o \
        Semicolon.o TreeCreator.o
VPATH=src
all : rshell
rshell : $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o rshell 
	mkdir bin
	mv $(OBJECTS) rshell bin
And.o : And.cpp And.h Connector.h
	$(CC) -c $(CFLAGS) $^
BinCmd.o : BinCmd.cpp BinCmd.h CommandComponent.h
	$(CC) -c $(CFLAGS) $^
Cd.o : Cd.cpp Cd.h CommandComponent.h
	$(CC) -c $(CFLAGS) $^
Echo.o : Echo.cpp Echo.h CommandComponent.h
	$(CC) -c $(CFLAGS) $^
Exit.o : Exit.cpp Exit.h CommandComponent.h
	$(CC) -c $(CFLAGS) $^
main.o : main.cpp Rshell.h Parser.h TreeCreator.h
	$(CC) -c $(CFLAGS) $^
Or.o : Or.cpp Or.h Connector.h
	$(CC) -c $(CFLAGS) $^
Parser.o : Parser.cpp Parser.h
	$(CC) -c $(CFLAGS) $^
Rshell.o : Rshell.cpp Rshell.h Parser.h TreeCreator.h
	$(CC) -c $(CFLAGS) $^
Semicolon.o : Semicolon.cpp Semicolon.h Connector.h
	$(CC) -c $(CFLAGS) $^
TreeCreator.o : TreeCreator.cpp TreeCreator.h CommandComponent.h \
                Or.h And.h Semicolon.h Exit.h Echo.h Cd.h BinCmd.h
	$(CC) -c $(CFLAGS) $^
clean :
	rm -R bin
	rm src/*.gch
