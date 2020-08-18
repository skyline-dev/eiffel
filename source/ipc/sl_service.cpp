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
        LOG("%s", meta.name);
        return 0;
    };

    ams::Result SlService::RegisterSharedMem(core::PluginName name, SlPluginSharedMemInfo sharedMemInfo) {
        core::PluginHandler::SetPluginSharedMem(name, sharedMemInfo);
        LOG("%s - handle %d  size 0x%lx  perm: %x", name.data(), sharedMemInfo.handle, sharedMemInfo.size,
            sharedMemInfo.perm);
        return 0;
    };

};  // namespace efl::ipc
