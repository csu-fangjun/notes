
USE_CXX11_ABI := $(shell python3 -c 'import torch; print(int(torch.compiled_with_cxx11_abi()))')
TORCH_INSTALL_DIR := $(shell python3 -c 'import os; import torch; print(os.path.dirname(torch.__file__))')

$(info USE_CXX11_ABI $(USE_CXX11_ABI))
$(info TORCH_INSTALL_DIR $(TORCH_INSTALL_DIR))

CXXFLAGS := -I$(TORCH_INSTALL_DIR)/include
CXXFLAGS += -I$(TORCH_INSTALL_DIR)/include/torch/csrc/api/include
CXXFLAGS += -I$(TORCH_INSTALL_DIR)/include/TH
CXXFLAGS += -I$(TORCH_INSTALL_DIR)/include/THC
CXXFLAGS += -std=c++14
CXXFLAGS += -D_GLIBCXX_USE_CXX11_ABI=$(USE_CXX11_ABI)

CXXFLAGS += -Wno-unknown-pragmas # disable omp warnings

LDFLAGS := -L$(TORCH_INSTALL_DIR)/lib
LDFLAGS += -lc10 -ltorch -ltorch_cpu
# LDFLAGS += -lc10 -ltorch
LDFLAGS += -Wl,-rpath,$(TORCH_INSTALL_DIR)/lib

HAS_CUDA := $(shell python3 -c 'import torch; print("yes" if torch.cuda.is_available() else "no")')
$(info has cuda $(HAS_CUDA))

ifeq ($(HAS_CUDA),yes)
CUDA_HOME := $(shell which nvcc | xargs dirname | xargs dirname)
CXXFLAGS += -I$(CUDA_HOME)/include
LDFLAGS += -L$(CUDA_HOME)/lib64
LDFLAGS += -lcudart -lc10_cuda -ltorch_cuda
LDFLAGS += -Wl,-rpath,$(CUDA_HOME)/lib64
endif

.PHONY: clean

main: main.o
	$(CXX) -o $@ $< $(LDFLAGS)

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) main.o main
