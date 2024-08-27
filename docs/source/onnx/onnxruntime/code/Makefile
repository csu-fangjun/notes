CXXFLAGS := -std=c++17
CXXFLAGS += -I /Users/fangjun/Downloads/onnxruntime-osx-x86_64-1.18.0/include
LDFLAGS := -L /Users/fangjun/Downloads/onnxruntime-osx-x86_64-1.18.0/lib
LDFLAGS += -l onnxruntime
LDFLAGS += -Wl,-rpath,/Users/fangjun/Downloads/onnxruntime-osx-x86_64-1.18.0/lib

main: main.cc c-api-test.cc cpp-api-test.cc ./custom-op.cc ./custom-op-2.cc ./custom-op-3.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
