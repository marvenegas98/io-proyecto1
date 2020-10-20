# change application name here (executable output name)
TARGET=windows

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
	rm -f $(OBJ)\ $(TARGET)