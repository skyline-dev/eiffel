#include "sl_service.hpp"

#include "../util.hpp"

namespace efl::ipc {

    SlService::SlService() {}

    SlService::~SlService() {}

    ams::Result SlService::Log(const ams::sf::InBuffer& module_name, efl::logger::LogLevel level,
                               const ams::sf::InBuffer& buf) {
        LOG("[%s][%s] %s", module_name.GetPointer(), logger::GetLogLevelString(level), buf.GetPointer());
        return 0;
    };

    ams::Result SlService::RegisterPlugin(SlPluginMeta meta) {
        core::PluginHandler::SetPluginMeta(meta);
        LOG("registered plugin: %s", meta.name);
        return 0;
    };

    ams::Result SlService::RegisterSharedMem(core::PluginName name, SharedMemory sharedMem) {
        core::PluginHandler::SetPluginSharedMem(name, sharedMem);
        LOG("registered plugin shared mem: %s", name);
        return 0;
    };

};  // namespace efl::ipc
