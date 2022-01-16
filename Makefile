all:
	g++ -g -Wall -c *.cpp
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

valgrind:
	g++ -g -Wall -c *.cpp
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	valgrind ./main

clean:
	rm *.o
	rm main