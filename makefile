main: index.js
    emcc main.cpp -s WASM=1 USE_SDL=2 -03 -o index.js
