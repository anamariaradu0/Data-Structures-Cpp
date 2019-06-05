CC = g++
CFLAGS = -Wall -Wextra -Wno-unused-parameter -std=c++11

build: Graph.cpp Main.cpp
	$(CC) $(CFLAGS) Graph.cpp Main.cpp -o graph

set_dbg: CFLAGS += -DDEBUG

debug: set_dbg

set_dbg: build

run:
	./graph

clean:
	rm graph
