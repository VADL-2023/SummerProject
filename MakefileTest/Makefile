SOURCES = $(wildcard ./driver/*.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SOURCES))

all: ./VectorNav/build/bin/libvncxx.a $(OBJS)
	gcc main.cpp -L ./VectorNav/build/bin -lvncxx -I./VectorNav/include

./VectorNav/build/bin/libvncxx.a:
	cd ./VectorNav && $(MAKE)
