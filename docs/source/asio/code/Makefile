CXXFLAGS := -I /ceph-fj/fangjun/software/asio/include -pthread

srcs := $(shell find . -type f -name "*.cc" -printf "%f ")
targets :=$(srcs:%.cc=%)

all: $(targets)

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<


.PHONY: clean
clean:
	$(RM) $(targets)
