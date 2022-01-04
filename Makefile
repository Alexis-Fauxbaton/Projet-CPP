all:
	g++ -c *.cpp
	g++ *.o -o main

clean:
	rm *.o
	rm main