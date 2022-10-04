
CXXFLAGS := -DASIO_STANDALONE
CXXFLAGS += -I/ceph-fj/fangjun/software/asio/include
CXXFLAGS += -I/ceph-fj/fangjun/software/websocketpp/include
CXXFLAGS += -std=c++14
LDFLAGS += -pthread

main: main.o uri.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	$(RM) *.o main

