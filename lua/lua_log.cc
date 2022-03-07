// tianyi accelerator framework

#include "luacpp/luacpp.h"
#include "tianyi/common/log.h"
#include <memory>
using namespace std;
using namespace luacpp;

namespace tianyi { namespace common { namespace lua {

void RegisterLog(const shared_ptr<LuaState>& lstate, const shared_ptr<LuaTable>& lmodule) {
    lmodule->SetInteger("LOG_LEVEL_DEBUG", LOG_LEVEL_DEBUG);
    lmodule->SetInteger("LOG_LEVEL_INFO", LOG_LEVEL_INFO);
    lmodule->SetInteger("LOG_LEVEL_WARNING", LOG_LEVEL_WARNING);
    lmodule->SetInteger("LOG_LEVEL_ERROR", LOG_LEVEL_ERROR);
    lmodule->SetInteger("LOG_LEVEL_FATAL", LOG_LEVEL_FATAL);
    lmodule->SetInteger("LOG_LEVEL_MAX", LOG_LEVEL_MAX);

    lmodule->Set("SetLoggingLevel", lstate->CreateFunction([](uint32_t level) -> void {
        GetCurrentLogger()->SetLogLevel(level);
    }));
    lmodule->Set("GetLoggingLevel", lstate->CreateFunction([]() -> uint32_t {
        return GetCurrentLogger()->GetLogLevel();
    }));
}

}}} // namespace tianyi::common::lua
