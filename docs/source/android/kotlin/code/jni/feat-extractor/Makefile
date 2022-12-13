SHERPA_NCNN_INSTALL_DIR := /ceph-fj/fangjun/open-source/sherpa-ncnn/build/install

CXXFLAGS := -I $(JAVA_HOME)/include
CXXFLAGS += -I $(JAVA_HOME)/include/linux
CXXFLAGS += -I $(SHERPA_NCNN_INSTALL_DIR)/include
CXXFLAGS += -I $(SHERPA_NCNN_INSTALL_DIR)/include/ncnn
CXXFLAGS += -Wall

LDFLAGS := -L $(SHERPA_NCNN_INSTALL_DIR)/lib -lkaldi-native-fbank-core -lsherpa-ncnn-core -lncnn
LDFLAGS += -Wl,-rpath,$(SHERPA_NCNN_INSTALL_DIR)/lib

all: main.jar libsherpa-ncnn.so

main.jar: Main.kt OnlineFeature.kt WaveReader.kt Model.kt
	kotlinc-jvm -include-runtime -d main.jar Main.kt OnlineFeature.kt WaveReader.kt Model.kt

libsherpa-ncnn.so: online-feature.cc sherpa-ncnn.cc online-feature.h sherpa-ncnn.h
	$(CXX) -o $@ -shared -fPIC $(CXXFLAGS) online-feature.cc sherpa-ncnn.cc $(LDFLAGS)

run: all
	java -jar main.jar

clean:
	$(RM) main.jar libsherpa-ncnn.so
