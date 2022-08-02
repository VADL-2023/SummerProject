CXX = g++
INCLUDES = -I./VectorNav/include
CPPFLAGS = -Wall
CFLAGS = $(INCLUDES) # Need CFLAGS AND CXX FLAGS FOR INCLUDES
CXXFLAGS = $(INCLUDES)
SOURCES = $(wildcard ./driver/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))

all: ./VectorNav/build/bin/libvncxx.a $(OBJS) # SPECIFIES ALL OBJECT FILES
	g++ lowLevelSerial.cpp -L ./VectorNav/build/bin -lvncxx -I./VectorNav/include

./VectorNav/build/bin/libvncxx.a:
	cd ./VectorNav && $(MAKE)
