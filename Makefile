# Simple Makefile for PastTheTrench

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I.

# Target executable name
TARGET := PastTheTrench

# Source and object files
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

# Phony targets
.PHONY: all run clean distclean

# Default target: build everything
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Remove object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# Full cleanup (if there were other artifacts)
distclean: clean
	# Add commands to remove additional generated files if needed
