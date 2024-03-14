#****************************************************************************
#
#	Makefile for c++ projects with multiple source files and headers
#
#	Commands:
#	  - make
#	  - make run
#	  - make clean
#
#****************************************************************************

CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main.exe
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)