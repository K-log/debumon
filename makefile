# IMPORTANT your links should look like this: #include <SDL2/SDL.h> and #include <SDL2/SDL_image.h>
# And this will work.
# To K-log: If it doesn't I can make you another make file and you would just run make nameofuniquemake
# Also, "Meow".

CXXFLAGS = -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' 
CXX = emcc
FLAGS = -c -w -std=c++11 -l sdl2_image -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' 

all: main.o singleCard.o debumon clean

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp

game.o: game.cpp game.h
	$(CXX) $(FLAGS) game.cpp

singleCard.o: singleCard.cpp singleCard.h
	$(CXX) $(FLAGS) singleCard.cpp

debumon: main.o game.o singleCard.o
	$(CXX) main.o game.o singleCard.o $(CXXFLAGS) -o index.js

game: main.o game.o
	$(CXX) main.o game.o $(CXXFLAGS) -o index.js

clean:
	rm -f *.o
