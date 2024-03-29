CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

SRC_EXT = cpp
OBJ_EXT = o

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))

OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT)))

TARGET = $(BIN_DIR)/your_executable_name

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $(TARGET)

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	$(TARGET)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(OBJECTS:.o=.d)

