# program executable 
EXE = chessviz.out

# compiler settings
CXX = g++
FLAGS = -Wall -Werror -std=c++14

# folders of project
BIN = bin
BUILD = build
SOURCE = src

#
# TODO: remake all files to var's
#

# all prog is 
all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(BUILD)/board.o $(BUILD)/board_print_console.o $(BUILD)/board_print_html.o $(BUILD)/board_print_text.o $(BUILD)/main.o
	$(CXX) $(FLAGS) -o $(BIN)/$(EXE) $(BUILD)/board.o $(BUILD)/board_print_console.o $(BUILD)/board_print_html.o $(BUILD)/board_print_text.o $(BUILD)/main.o


$(BUILD)/main.o: $(SOURCE)/main.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD)/board_print_console.o: $(SOURCE)/board_print_console.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD)/board_print_html.o: $(SOURCE)/board_print_html.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD)/board_print_text.o: $(SOURCE)/board_print_text.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD)/board.o: $(SOURCE)/board.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

# cleaning of workfiles
clean:
	rm -rf $(BIN)/* $(BUILD)/*

# creating folders
dir:
	mkdir $(BIN) $(BUILD)

.PHONY: all clean dir