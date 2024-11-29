# Define compiler and flags
CXX = g++
CXXFLAGS = -I/opt/homebrew/include -I./ -Wno-deprecated-declarations  # Include the current directory and other paths
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lglut -framework OpenGL

# Define source files and target output
SRC = InitialParameters.cpp ColorMap.cpp Fractals.cpp main.cpp
OBJ = InitialParameters.o ColorMap.o Fractals.o main.o
TARGET = main

# Default target to compile and link
all: $(TARGET)

# Compile step: Create object files from source
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $^

# Link step: Create executable from object files
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Clean step: Remove object files and executable
clean:
	rm -f $(OBJ) $(TARGET)
