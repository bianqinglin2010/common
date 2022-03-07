// tianyi accelerator framework

#include "pybind11/pybind11.h"
#include "tianyi/common/log.h"

namespace tianyi { namespace common { namespace python {

void RegisterLog(pybind11::module* m) {
    m->attr("LOG_LEVEL_DEBUG") = (uint32_t)LOG_LEVEL_DEBUG;
    m->attr("LOG_LEVEL_INFO") = (uint32_t)LOG_LEVEL_INFO;
    m->attr("LOG_LEVEL_WARNING") = (uint32_t)LOG_LEVEL_WARNING;
    m->attr("LOG_LEVEL_ERROR") = (uint32_t)LOG_LEVEL_ERROR;
    m->attr("LOG_LEVEL_FATAL") = (uint32_t)LOG_LEVEL_FATAL;
    m->attr("LOG_LEVEL_MAX") = (uint32_t)LOG_LEVEL_MAX;

    m->def("SetLoggingLevel", [](uint32_t level) -> void {
        GetCurrentLogger()->SetLogLevel(level);
    });
    m->def("GetLoggingLevel", []() -> uint32_t {
        return GetCurrentLogger()->GetLogLevel();
    });
}

}}} // namespace tianyi::common::python
