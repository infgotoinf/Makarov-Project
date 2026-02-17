RAYLIB ?= ./external/raylib-5.5/src/

all: build run


build: mkdir
	gcc ./main/main.c -o ./build/main -I $(RAYLIB) -L $(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	
run:
	./build/main

mkdir:
	mkdir -p build


clean:
	rm -rf build
