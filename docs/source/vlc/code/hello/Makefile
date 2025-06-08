CXX_FLAGS := -I /Applications/VLC.app/Contents/MacOS/include
LDFLAGS := -L /Applications/VLC.app/Contents/MacOS/lib
LDFLAGS += -lvlc
LDFLAGS += -Wl,-rpath,/Applications/VLC.app/Contents/MacOS/lib

hello: hello.cc
	g++ -o ./hello  $(CXX_FLAGS) ./hello.cc $(LDFLAGS)
