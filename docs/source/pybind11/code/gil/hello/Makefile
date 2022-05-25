
CXX_FLAGS := $(shell python3 -m pybind11 --includes)
CXX_FLAGS += $(shell python3-config --includes)
CXX_FLAGS += -Wall
CXX_FLAGS += -std=c++11
CXX_FLAGS += -shared -fPIC

SUFFIX := $(shell python3-config --extension-suffix)


main$(SUFFIX): main.cc
	$(CXX) $(CXX_FLAGS) -o $@ $<

clean:
	$(RM) main$(SUFFIX)
