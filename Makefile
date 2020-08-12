CC = g++

all:
	$(CC) -std=c++11 -o a.exe RadixSort.cpp

clean:
	rm -f a.exe

