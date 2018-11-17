# IMPORTANT your links should look like this: #include <SDL2/SDL.h> and #include <SDL2/SDL_image.h>
# And this will work.
# To K-log: If it doesn't I can make you another make file and you would just run make nameofuniquemake
# Also, "Meow".

CXFLAGS = -s WASM=1
CXX = emcc
<<<<<<< HEAD
FLAGS = -c -w -std=c++11 -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' 
=======
FLAGS = -c -w 
>>>>>>> f0b3551444a41fc6f52a15a39bc4858652643a45

all: main.o singleCard.o debumon clean

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp

singleCard.o: singleCard.cpp singleCard.h
	$(CXX) $(FLAGS) singleCard.cpp

debumon: main.o singleCard.o
	$(CXX) main.o singleCard.o $(CXXFLAGS) -o index.js

clean:
	rm -f *.o
