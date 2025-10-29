# Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = matrix_ops
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean