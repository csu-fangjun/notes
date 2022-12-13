SHERPA_NCNN_INSTALL_DIR := /ceph-fj/fangjun/open-source/sherpa-ncnn/build/install

CXXFLAGS := -I $(JAVA_HOME)/include
CXXFLAGS += -I $(JAVA_HOME)/include/linux
CXXFLAGS += -I $(SHERPA_NCNN_INSTALL_DIR)/include
CXXFLAGS += -I $(SHERPA_NCNN_INSTALL_DIR)/include/ncnn
CXXFLAGS += -Wall

LDFLAGS := -L $(SHERPA_NCNN_INSTALL_DIR)/lib -lkaldi-native-fbank-core -lsherpa-ncnn-core -lncnn
LDFLAGS += -Wl,-rpath,$(SHERPA_NCNN_INSTALL_DIR)/lib

all: libsherpa-ncnn.so main.jar

main.jar: Main.kt WaveReader.kt SherpaNcnn.kt
	kotlinc-jvm -include-runtime -d main.jar Main.kt WaveReader.kt SherpaNcnn.kt

libsherpa-ncnn.so: sherpa-ncnn.cc wave-reader.cc sherpa-ncnn.h wave-reader.h
	$(CXX) -o $@ -shared -fPIC $(CXXFLAGS) sherpa-ncnn.cc wave-reader.cc $(LDFLAGS)

run: all
	java -jar main.jar

clean:
	$(RM) main.jar libsherpa-ncnn.so
