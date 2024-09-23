.PHONY: build run test clear


build: clear
	mkdir -p build
	git submodule init
	git submodule update
	cd build && cmake .. && make lab2 && make lab2_test

run: 
	./build/lab2

test:
	./build/lab2_test

clear:
	@rm -rf ./build/