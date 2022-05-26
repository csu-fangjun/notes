
.PHONY: all clean

all: hello.pb.cc hello.pb.h hello_pb2.py

hello.pb.cc hello.pb.h: hello.proto
	protoc -I=./ --cpp_out=./ ./hello.proto

hello_pb2.py: hello.proto
	protoc -I=./ --python_out=./ ./hello.proto

clean:
	$(RM) hello.pb.cc hello.pb.h hello_pb2.py
