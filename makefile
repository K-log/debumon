CXXFLAGS = -s WASM=1 -s USE_SDL=2 -03
CXX = emcc
FLAGS = -c -w 

all: main.o debumon clean

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp

debumon: main.o
	$(CXX) main.o $(CXXFLAGS) -o index.js

clean:
	rm -f *.o
