CXXFLAGS := -I $(JAVA_HOME)/include
CXXFLAGS += -I $(JAVA_HOME)/include/linux

all: NativeSample.jar libhello.so

NativeSample.jar: NativeSample.kt Main.kt
	kotlinc-jvm -include-runtime -d NativeSample.jar NativeSample.kt Main.kt

libhello.so: hello.cc hello.h
	$(CXX) -o $@ -shared -fPIC $(CXXFLAGS) hello.cc

run: all
	java -jar NativeSample.jar

clean:
	$(RM) *.jar *.so
