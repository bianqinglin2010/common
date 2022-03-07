// tianyi accelerator framework

#include "tianyi/common/retcode.h"
#include "luacpp/luacpp.h"
#include <memory>
using namespace std;
using namespace luacpp;

namespace tianyi { namespace common { namespace lua {

void RegisterRetCode(const shared_ptr<LuaState>& lstate, const shared_ptr<LuaTable>& lmodule) {
    lmodule->SetInteger("RC_SUCCESS", RC_SUCCESS);
    lmodule->SetInteger("RC_OTHER_ERROR", RC_OTHER_ERROR);
    lmodule->SetInteger("RC_UNSUPPORTED", RC_UNSUPPORTED);
    lmodule->SetInteger("RC_OUT_OF_MEMORY", RC_OUT_OF_MEMORY);
    lmodule->SetInteger("RC_INVALID_VALUE", RC_INVALID_VALUE);
    lmodule->SetInteger("RC_EXISTS", RC_EXISTS);
    lmodule->SetInteger("RC_NOT_FOUND", RC_NOT_FOUND);
    lmodule->SetInteger("RC_PERMISSION_DENIED", RC_PERMISSION_DENIED);
    lmodule->SetInteger("RC_HOST_MEMORY_ERROR", RC_HOST_MEMORY_ERROR);
    lmodule->SetInteger("RC_DEVICE_MEMORY_ERROR", RC_DEVICE_MEMORY_ERROR);
    lmodule->SetInteger("RC_DEVICE_RUNTIME_ERROR", RC_DEVICE_RUNTIME_ERROR);

    lmodule->Set("GetRetCodeStr", lstate->CreateFunction(&GetRetCodeStr));
}

}}} // namespace tianyi::common::lua
