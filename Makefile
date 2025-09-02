CXX = g++
CXXFLAGS = -std=c++17 -Iheaders -Wall -Wextra
BIN = main.exe

SRCS := $(wildcard classes/*.cpp classes/roles/*.cpp classes/weapons/*.cpp classes/abilities/*.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q classes\*.o classes\roles\*.o classes\weapons\*.o classes\abilities\*.o $(BIN)

.PHONY: all clean