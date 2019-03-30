CC = g++
CFLAGS = -Wall -Werror
SOURCES = main.cpp output.cpp
EXECUTABLE = chess.out
OBJECTS = $(SOURCES:.o=.cpp)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)