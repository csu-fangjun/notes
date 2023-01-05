all: libhello.a

libhello.a: hello.h hello.cc
	g++ -c hello.cc -o hello.o
	ar r libhello.a hello.o

clean:
	$(RM) libhello.a hello.o
