// tianyi accelerator framework

#include "tianyi/common/types.h"
#include "luacpp/luacpp.h"
#include <memory>
using namespace std;
using namespace luacpp;

namespace tianyi { namespace common { namespace lua {

void RegisterTypes(const shared_ptr<LuaState>& lstate, const shared_ptr<LuaTable>& lmodule) {
    lmodule->SetInteger("DATATYPE_UNKNOWN", DATATYPE_UNKNOWN);
    lmodule->SetInteger("DATATYPE_UINT8", DATATYPE_UINT8);
    lmodule->SetInteger("DATATYPE_UINT16", DATATYPE_UINT16);
    lmodule->SetInteger("DATATYPE_UINT32", DATATYPE_UINT32);
    lmodule->SetInteger("DATATYPE_UINT64", DATATYPE_UINT64);
    lmodule->SetInteger("DATATYPE_FLOAT16", DATATYPE_FLOAT16);
    lmodule->SetInteger("DATATYPE_FLOAT32", DATATYPE_FLOAT32);
    lmodule->SetInteger("DATATYPE_FLOAT64", DATATYPE_FLOAT64);
    lmodule->SetInteger("DATATYPE_BFLOAT16", DATATYPE_BFLOAT16);
    lmodule->SetInteger("DATATYPE_INT4B", DATATYPE_INT4B);
    lmodule->SetInteger("DATATYPE_INT8", DATATYPE_INT8);
    lmodule->SetInteger("DATATYPE_INT16", DATATYPE_INT16);
    lmodule->SetInteger("DATATYPE_INT32", DATATYPE_INT32);
    lmodule->SetInteger("DATATYPE_INT64", DATATYPE_INT64);
    lmodule->SetInteger("DATATYPE_BOOL", DATATYPE_BOOL);
    lmodule->SetInteger("DATATYPE_COMPLEX64", DATATYPE_COMPLEX64);
    lmodule->SetInteger("DATATYPE_COMPLEX128", DATATYPE_COMPLEX128);
    lmodule->SetInteger("DATATYPE_MAX", DATATYPE_MAX);

    lmodule->SetInteger("DATAFORMAT_UNKNOWN", DATAFORMAT_UNKNOWN);
    lmodule->SetInteger("DATAFORMAT_NDARRAY", DATAFORMAT_NDARRAY);
    lmodule->SetInteger("DATAFORMAT_NHWC8", DATAFORMAT_NHWC8);
    lmodule->SetInteger("DATAFORMAT_NHWC16", DATAFORMAT_NHWC16);
    lmodule->SetInteger("DATAFORMAT_N2CX", DATAFORMAT_N2CX);
    lmodule->SetInteger("DATAFORMAT_N4CX", DATAFORMAT_N4CX);
    lmodule->SetInteger("DATAFORMAT_N8CX", DATAFORMAT_N8CX);
    lmodule->SetInteger("DATAFORMAT_N16CX", DATAFORMAT_N16CX);
    lmodule->SetInteger("DATAFORMAT_N32CX", DATAFORMAT_N32CX);
    lmodule->SetInteger("DATAFORMAT_MAX", DATAFORMAT_MAX);

    lmodule->Set("GetDataTypeStr", lstate->CreateFunction(&GetDataTypeStr));
    lmodule->Set("GetDataFormatStr", lstate->CreateFunction(&GetDataFormatStr));
    lmodule->Set("GetSizeOfDataType", lstate->CreateFunction(&GetSizeOfDataType));
}

}}} // namespace tianyi::common::lua
