// tianyi accelerator framework

#include "tianyi/common/types.h"
#include "pybind11/pybind11.h"

namespace tianyi { namespace common { namespace python {

void RegisterTypes(pybind11::module* m) {
    m->attr("DATATYPE_UNKNOWN") = (uint32_t)DATATYPE_UNKNOWN;
    m->attr("DATATYPE_UINT8") = (uint32_t)DATATYPE_UINT8;
    m->attr("DATATYPE_UINT16") = (uint32_t)DATATYPE_UINT16;
    m->attr("DATATYPE_UINT32") = (uint32_t)DATATYPE_UINT32;
    m->attr("DATATYPE_UINT64") = (uint32_t)DATATYPE_UINT64;
    m->attr("DATATYPE_FLOAT16") = (uint32_t)DATATYPE_FLOAT16;
    m->attr("DATATYPE_FLOAT32") = (uint32_t)DATATYPE_FLOAT32;
    m->attr("DATATYPE_FLOAT64") = (uint32_t)DATATYPE_FLOAT64;
    m->attr("DATATYPE_BFLOAT16") = (uint32_t)DATATYPE_BFLOAT16;
    m->attr("DATATYPE_INT4B") = (uint32_t)DATATYPE_INT4B;
    m->attr("DATATYPE_INT8") = (uint32_t)DATATYPE_INT8;
    m->attr("DATATYPE_INT16") = (uint32_t)DATATYPE_INT16;
    m->attr("DATATYPE_INT32") = (uint32_t)DATATYPE_INT32;
    m->attr("DATATYPE_INT64") = (uint32_t)DATATYPE_INT64;
    m->attr("DATATYPE_BOOL") = (uint32_t)DATATYPE_BOOL;
    m->attr("DATATYPE_COMPLEX64") = (uint32_t)DATATYPE_COMPLEX64;
    m->attr("DATATYPE_COMPLEX128") = (uint32_t)DATATYPE_COMPLEX128;
    m->attr("DATATYPE_MAX") = (uint32_t)DATATYPE_MAX;

    m->attr("DATAFORMAT_UNKNOWN") = (uint32_t)DATAFORMAT_UNKNOWN;
    m->attr("DATAFORMAT_NDARRAY") = (uint32_t)DATAFORMAT_NDARRAY;
    m->attr("DATAFORMAT_NHWC8") = (uint32_t)DATAFORMAT_NHWC8;
    m->attr("DATAFORMAT_NHWC16") = (uint32_t)DATAFORMAT_NHWC16;
    m->attr("DATAFORMAT_N2CX") = (uint32_t)DATAFORMAT_N2CX;
    m->attr("DATAFORMAT_N4CX") = (uint32_t)DATAFORMAT_N4CX;
    m->attr("DATAFORMAT_N8CX") = (uint32_t)DATAFORMAT_N8CX;
    m->attr("DATAFORMAT_N16CX") = (uint32_t)DATAFORMAT_N16CX;
    m->attr("DATAFORMAT_N32CX") = (uint32_t)DATAFORMAT_N32CX;
    m->attr("DATAFORMAT_MAX") = (uint32_t)DATAFORMAT_MAX;

    m->def("GetDataTypeStr", &GetDataTypeStr);
    m->def("GetDataFormatStr", &GetDataFormatStr);
    m->def("GetSizeOfDataType", &GetSizeOfDataType);
}

}}} // namespace tianyi::common::python
