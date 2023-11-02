CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic -std=c++11
OBJECTS = PhotoMagic.o FibLFSR.o
LIBS = -l sfml-graphics -l sfml-window -l sfml-system

all: PhotoMagic

PhotoMagic: $(OBJECTS)
	$(CC) $(CFLAGS) -o PhotoMagic $(OBJECTS) $(LIBS)
PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o
FibLFSR.o: FibLFSR.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	rm PhotoMagic $(OBJECTS)