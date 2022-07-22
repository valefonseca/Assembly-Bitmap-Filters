all:
	mkdir -p build/
	g++ -c -o build/filtro.o src/filtro.cpp
	nasm -f elf64 -o build/negativo.o src/negativo.asm
	nasm -f elf64 -o build/blur.o src/blur.asm
	mkdir -p bin/
	g++ -no-pie -g -o bin/exe build/filtro.o build/negativo.o build/blur.o
run:
	bin/exe
solo:
	g++ -c -o build/filtro.o src/filtro.cpp
	g++ -g -o bin/exe build/filtro.o
	./exe
clean:
	rm -rf bin build doc
	
delete:
	rm -f *_blur.bmp
	rm -f *_neg.bmp

