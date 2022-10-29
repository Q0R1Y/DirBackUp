CC=g++
CFLAG=-g -lpthread -I./include
OBJ=./build/datatrans.o ./build/scanfile.o ./build/main.o

run:main.o datatrans.o scanfile.o
	$(CC) $(OBJ) $(CFLAG) -o ./build/run

main.o:./src/main.cpp ./include/datatrans.h ./include/scanfile.h
	$(CC) ./src/main.cpp $(CFLAG) -c -o ./build/main.o

datatrans.o:./src/datatrans.cpp ./include/datatrans.h
	$(CC) ./src/datatrans.cpp $(CFLAG) -c -o ./build/datatrans.o 

scanfile.o:./src/scanfile.cpp ./include/scanfile.h
	$(CC) ./src/scanfile.cpp $(CFLAG) -c -o ./build/scanfile.o

.PHONY:clean

clean:
	rm -rf ./build&&mkdir build
