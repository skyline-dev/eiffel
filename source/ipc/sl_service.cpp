#include "sl_service.hpp"

#include "../util.hpp"

namespace efl::ipc {

    SlService::SlService() {}

    SlService::~SlService() {}

    ams::Result SlService::Log(const ams::sf::InBuffer& module_name, efl::logger::LogLevel level,
                               const ams::sf::InBuffer& buf) {
        // TODO: impl proper handling of logs
        printf("LOG: [%s][%s] %s", module_name.GetPointer(), logger::GetLogLevelString(level),
               buf.GetPointer());  // this is just for debug
        return 0;
    };

    ams::Result SlService::RegisterPlugin(SlPluginMeta meta) {
        core::PluginHandler::SetPluginMeta(meta);
        LOG("%s", meta.name);
        return 0;
    };

    ams::Result SlService::RegisterSharedMem(EiffelSlRegisterSharedMemIn in, ams::sf::CopyHandle handle) {
        auto sharedMemInfo = SlPluginSharedMemInfo{handle.GetValue(), in.size, in.perm};
        core::PluginHandler::SetPluginSharedMem(in.name, sharedMemInfo);
        LOG("%s - size 0x%lx  perm: %x", in.name, in.size, in.perm);
        return 0;
    };

};  // namespace efl::ipc
