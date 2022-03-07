// tianyi accelerator framework

#include "tianyi/common/retcode.h"
#include "pybind11/pybind11.h"

namespace tianyi { namespace common { namespace python {

void RegisterRetCode(pybind11::module* m) {
    m->attr("RC_SUCCESS") = (uint32_t)RC_SUCCESS;
    m->attr("RC_OTHER_ERROR") = (uint32_t)RC_OTHER_ERROR;
    m->attr("RC_UNSUPPORTED") = (uint32_t)RC_UNSUPPORTED;
    m->attr("RC_OUT_OF_MEMORY") = (uint32_t)RC_OUT_OF_MEMORY;
    m->attr("RC_INVALID_VALUE") = (uint32_t)RC_INVALID_VALUE;
    m->attr("RC_EXISTS") = (uint32_t)RC_EXISTS;
    m->attr("RC_NOT_FOUND") = (uint32_t)RC_NOT_FOUND;
    m->attr("RC_PERMISSION_DENIED") = (uint32_t)RC_PERMISSION_DENIED;
    m->attr("RC_HOST_MEMORY_ERROR") = (uint32_t)RC_HOST_MEMORY_ERROR;
    m->attr("RC_DEVICE_MEMORY_ERROR") = (uint32_t)RC_DEVICE_MEMORY_ERROR;
    m->attr("RC_DEVICE_RUNTIME_ERROR") = (uint32_t)RC_DEVICE_RUNTIME_ERROR;

    m->def("GetRetCodeStr", &GetRetCodeStr);
}

}}} // namespace tianyi::common::python
