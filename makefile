CXX=g++
CXXFLAGS=-std=c++11 -g
TARGET=HuntTheWumpus
SRCS=main.cpp game.cpp wumpus.cpp bats.cpp stalactites.cpp gold.cpp room.cpp event.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
