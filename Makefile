.PHONY: build run test clear


build: clear
	mkdir -p build
	git submodule init
	git submodule update
	cd build && cmake .. && make run && make test

run: ./build/main

test: ./build/test

clear:
	@rm -rf ./build/
