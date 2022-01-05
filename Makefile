all:
	g++ -g -Wall -c *.cpp
	g++ *.o -o main

valgrind:
	g++ -g -Wall -c *.cpp
	g++ *.o -o main
	valgrind --leak-check=full --show-reachable=yes ./main

clean:
	rm *.o
	rm main