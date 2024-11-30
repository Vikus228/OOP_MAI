.PHONY: build run test clear

build: clear
    mkdir -p build
    cd build && cmake .. && make program && make tests

run: 
    ./build/program

test:
    ./build/tests

clear:
    @rm -rf ./build/
