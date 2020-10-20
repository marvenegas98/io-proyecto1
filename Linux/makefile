# change application name here (executable output name)
TARGET=linux

# folders
SRC=src
OBJ=obj
SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall


LIBS=-L/usr/lib -lcgraph -lgvc -lgraph



# linker
LD=gcc

all: $(OBJECTS)
	$(LD) -o $(TARGET) $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@

echo:
	echo $(SOURCES)
	ls $(OBJ)

clean:
	rm -f $(OBJ)/* $(TARGET)
