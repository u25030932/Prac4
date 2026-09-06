SRC_DIR = src
HEADER_DIR = $(SRC_DIR)/headers
CPP_DIR = $(SRC_DIR)/cpp
BUILD_DIR = build

CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11 -I$(HEADER_DIR)

TARGET = $(BUILD_DIR)/main

SOURCES = $(wildcard $(CPP_DIR)/*.cpp)
OBJECTS = $(patsubst $(CPP_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(CPP_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
