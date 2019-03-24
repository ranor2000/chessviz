CC = g++
CFLAGS = -Wall -Werror
SOURCES = main.cpp output.cpp
EXECUTABLE = chessviz
OBJECTS = $(SOURCES:.o=.cpp)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)