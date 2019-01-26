build: ass1.cpp
	clang++ -o ass1 ass1.cpp -w
run: 
	make build && ./ass1
