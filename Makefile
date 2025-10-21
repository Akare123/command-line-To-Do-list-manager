# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable name
TARGET = todo

# Source files
SRC = main.c

# Default rule: build the target
all: $(TARGET)

# Rule to link the object file into the final executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule to clean up build files
clean:
	rm -f $(TARGET)

# Phony targets are not actual files
.PHONY: all clean
