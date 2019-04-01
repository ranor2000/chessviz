CC = g++
CFLAGS = -Wall -Werror
SOURCES = src/*.cpp
EXECUTABLE = chess.out
OBJECTS = $(SOURCES:.o=.cpp)
WORKFILES = output.txt output.html

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE) $(WORKFILES)