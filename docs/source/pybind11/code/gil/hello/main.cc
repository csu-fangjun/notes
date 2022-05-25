#include "pybind11/pybind11.h"
#include <iostream>
namespace py = pybind11;

int add(int i, int j) {
  std::cout << "PyGILState_Check(): " << PyGILState_Check() << "\n";
  py::gil_scoped_release no_gil;
  std::cout << "PyGILState_GetThisThreadState(): "
            << PyGILState_GetThisThreadState() << "\n";
  std::cout << "PyGILState_Check(): " << PyGILState_Check() << "\n";
  sleep(5);

  return i + j + 2;
}

PYBIND11_MODULE(main, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function that adds two numbers");
}
