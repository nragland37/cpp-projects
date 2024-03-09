#****************************************************************************
#
#	Makefile for a c++ projects with multiple source files and headers
#		Commands:
#			- make: compile the project
#			- make run: run the project
#			- make clean: remove the compiled files
#
#****************************************************************************
# compile

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

#****************************************************************************
# Default command: Make

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#****************************************************************************
# run 

run: $(TARGET)
	./$(TARGET)

#****************************************************************************
# clean up

clean:
	rm -f $(TARGET) $(OBJECTS)

#****************************************************************************