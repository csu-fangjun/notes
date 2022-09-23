
main: main.cc
	$(CXX) -o main -mavx -std=c++11 main.cc

.PHONY: test clean

test: main
	./main

clean:
	$(RM) main
