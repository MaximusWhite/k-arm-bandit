build: ass1.cpp
	clang++ -std=c++11 -o ass1 ass1.cpp -w
run: 
	make build && ./ass1
