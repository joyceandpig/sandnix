
AS = as
CC = gcc
CFLAGS = -g -Wall
INCFLAGS = 
LDFLAGS = 
LIBS = 

all: sanlo_x86

sandnix: $(OBJECTS)
	$(CC) -o sandnix $(OBJECTS) $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES:	.c .cc .C .cpp .o

.c.o :
	$(CC) -o $@ -c $(CFLAGS) $< $(INCFLAGS)

clean:
	rm -r ./obj

.PHONY: all
.PHONY: sanlo_x86
.PHONY: clean
