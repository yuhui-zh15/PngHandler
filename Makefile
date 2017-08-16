all: main_oop.o lodepng.o Picture.o PictureHandler.o
	g++ -std=c++11 main_oop.o lodepng.o Picture.o PictureHandler.o -o main.out
lodepng.o: lodepng.h lodepng.cpp
	g++ -c -std=c++11 lodepng.cpp -o lodepng.o -O3
Picture.o: Picture.h Picture.cpp
	g++ -c -std=c++11 Picture.cpp -o Picture.o -O3
PictureHandler.o: PictureHandler.h PictureHandler.cpp
	g++ -c -std=c++11 PictureHandler.cpp -o PictureHandler.o -O3
main_oop.o: main_oop.cpp
	g++ -c -std=c++11 main_oop.cpp -o main_oop.o -O3