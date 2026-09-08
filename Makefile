SRC_DIR = src
HEADER_DIR = .
CPP_DIR = .
BUILD_DIR = .

CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11 -I$(HEADER_DIR) -Wno-unused-parameter

TARGET = $(BUILD_DIR)/main

SOURCES = $(wildcard $(CPP_DIR)/*.cpp)
OBJECTS = $(patsubst $(CPP_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(CPP_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
