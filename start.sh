# Compile
emcc main.cpp -s WASM=1 -s USE_SDL=2 -O3 -o index.js

# Run
python -m SimpleHTTPServer 8080
