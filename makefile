# Compiler
CC := clang++

# Compiler flags
CFLAGS := -std=c++17 -Wall -g
LDFLAGS := -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(SRC_DIR)/glad.c

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Executable
TARGET := $(BUILD_DIR)/app

# Libraries
LIBS := -lglfw.3.3

# Build rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) $(OBJS) $(LIBS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/glad.o: $(SRC_DIR)/glad.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
