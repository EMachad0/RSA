all:
	g++ main.cpp src/*.cpp -lgmpxx -lgmp -o rsa

clean:
	rm rsa