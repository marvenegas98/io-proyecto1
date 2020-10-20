CC=gcc
CFLAGS=-g -O0
SOURCES=src\proyecto1_Windows.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=windows

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
