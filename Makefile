OBJ = main.o
INC = -I "./"

Rasterrain: main.o
	g++ main.o -o Rasterrain

main.o: main.cc *.h
	g++ -Wall -Wconversion -c main.cc

clean:
	rm -f *.o Rasterrain
