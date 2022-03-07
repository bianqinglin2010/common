// tianyi accelerator framework

#include "pybind11/pybind11.h"

namespace tianyi { namespace common { namespace python {

void RegisterLog(pybind11::module*);
void RegisterRetCode(pybind11::module*);
void RegisterTypes(pybind11::module*);

PYBIND11_MODULE(common, m) {
    RegisterLog(&m);
    RegisterRetCode(&m);
    RegisterTypes(&m);
}

}}} // namespace tianyi::common::python
