#include "user_service.hpp"

#include "../util.hpp"

namespace efl::ipc {

    UserService::UserService() {}

    UserService::~UserService() {}

    ams::Result UserService::GetPluginMeta(ams::sf::Out<SlPluginMeta> out, core::PluginName name) {
        LOG("%s", name.data());
        return core::PluginHandler::GetPluginMeta(out.GetPointer(), name);
    };

    ams::Result UserService::GetPluginSharedMemInfo(ams::sf::Out<SlPluginSharedMemInfo> out, core::PluginName name) {
        LOG("%s", name.data());
        return core::PluginHandler::GetPluginSharedMemInfo(out.GetPointer(), name);
    };

};  // namespace efl::ipc
