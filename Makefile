prog_name = yapl

.PHONY: all

all: compile run

compile:
	@mkdir -p build
	@gcc -o build/${prog_name} *.c -I ./

run:
	@./build/${prog_name}

clean:
	@rm -rf ./build
