// tianyi accelerator framework

#include "luacpp/luacpp.h"
#include "tianyi/common/common.h"
#include <memory>
using namespace std;
using namespace luacpp;

namespace tianyi { namespace common { namespace lua {

void RegisterLog(const shared_ptr<LuaState>&, const shared_ptr<LuaTable>&);
void RegisterRetCode(const shared_ptr<LuaState>&, const shared_ptr<LuaTable>&);
void RegisterTypes(const shared_ptr<LuaState>&, const shared_ptr<LuaTable>&);

}}} // namespace tianyi::common::lua

using namespace tianyi::common::lua;

extern "C" {

int TIANYICOMMON_PUBLIC luaopen_luatianyi_common(lua_State* l) {
    // may be used by module functions outside this function scope
    auto lstate = make_shared<LuaState>(l, false);
    auto lmodule = make_shared<LuaTable>(lstate->CreateTable());

    RegisterLog(lstate, lmodule);
    RegisterRetCode(lstate, lmodule);
    RegisterTypes(lstate, lmodule);

    lstate->Push(*lmodule);
    return 1;
}

}
