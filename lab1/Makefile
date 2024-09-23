.PHONY: build run test clear


build: clear
	mkdir -p build
	git submodule init
	git submodule update
	cd build && cmake .. && make lab1 && make lab1_test

run: 
	./build/lab1

test:
	./build/lab1_test

clear:
	@rm -rf ./build/