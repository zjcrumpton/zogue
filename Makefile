SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = zogue
INCLUDE_PATHS = -Iinclude -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g

all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
	make run

run:
	./$(BUILD_DIR)/$(OBJ_NAME)
