# Variables
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./googletest/googletest/include # Include the local gtest headers
TARGET = binPackingTests  # Name of the test executable
SRC = main.cpp binPacking.cpp googletest/googletest/src/gtest-all.cc # Source files
OBJ = main.o binPacking.o googletest/googletest/src/gtest-all.o  # Object files generated from source files

# Default target to build the executable
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) -pthread

# Rule to compile .cpp files into .o files
%.o: %.cpp binPacking.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean target to remove object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# .PHONY makes sure that clean is not considered a file
.PHONY: clean all
