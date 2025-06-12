CXX_FLAGS := -I /Applications/VLC.app/Contents/MacOS/include
LDFLAGS := -L /Applications/VLC.app/Contents/MacOS/lib
LDFLAGS += -lvlc
LDFLAGS += -Wl,-rpath,/Applications/VLC.app/Contents/MacOS/lib

meta: meta.cc
	g++ -o ./meta  $(CXX_FLAGS) ./meta.cc $(LDFLAGS)
