KFBANK_INSTALL_DIR := /ceph-fj/fangjun/open-source/kaldi-native-fbank/build/install/
CXXFLAGS := -I $(JAVA_HOME)/include
CXXFLAGS += -I $(JAVA_HOME)/include/linux
CXXFLAGS += -I $(KFBANK_INSTALL_DIR)/include

LDFLAGS := -L $(KFBANK_INSTALL_DIR)/lib -lkaldi-native-fbank-core
LDFLAGS += -Wl,-rpath,$(KFBANK_INSTALL_DIR)/lib

all: main.jar libonline-feature.so

main.jar: Main.kt OnlineFeature.kt
	kotlinc-jvm -include-runtime -d main.jar Main.kt OnlineFeature.kt

libonline-feature.so: online-feature.cc online-feature.h
	$(CXX) -o $@ -shared -fPIC $(CXXFLAGS) online-feature.cc $(LDFLAGS)

run: all
	java -jar main.jar

clean:
	$(RM) main.jar libonline-feature.so
