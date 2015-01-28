## Building

Setup emscripten sdk.
Compile boost, leveldb and cryptopp in directories parallel to cpp-ethereum.
Run:
```
emcmake cmake -DETH_STATIC=1 -DSOLIDITY=ON -DGUI=0
emmake make soljs
```
