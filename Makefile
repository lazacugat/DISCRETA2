CC = gcc
CFLAGS =  -Wall -Wextra -O3 -std=c99
SOURCES = funcvertex.c funcgraph.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = mi_programa

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
