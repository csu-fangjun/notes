CXXFLAGS := -std=c++14
CXXFLAGS += -I /Users/fangjun/open-source/sherpa-onnx/onnxruntime-osx-x86_64-1.12.1/include
LDFLAGS := -L /Users/fangjun/open-source/sherpa-onnx/onnxruntime-osx-x86_64-1.12.1/lib
LDFLAGS += -l onnxruntime
LDFLAGS += -Wl,-rpath,/Users/fangjun/open-source/sherpa-onnx/onnxruntime-osx-x86_64-1.12.1/lib

main: main.cc
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
