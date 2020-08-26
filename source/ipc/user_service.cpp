#include "user_service.hpp"

#include "../util.hpp"

namespace efl::ipc {

    UserService::UserService() {}

    UserService::~UserService() {}

    ams::Result UserService::GetPluginMeta(ams::sf::Out<SlPluginMeta> out, core::PluginName name) {
        LOG("%s", name.data());
        return core::PluginHandler::GetPluginMeta(out.GetPointer(), name);
    };

    // TODO: use copy handle instead when cleaning up handles is implemented
    ams::Result UserService::GetPluginSharedMem(ams::sf::OutMoveHandle out_handle,
                                                ams::sf::Out<SlPluginSharedMemInfo> out, core::PluginName name) {
        LOG("%s", name.data());
        auto rc = core::PluginHandler::GetPluginSharedMemInfo(out.GetPointer(), name);
        if (R_SUCCEEDED(rc)) {
            *(out_handle.GetHandlePointer()) = out.GetPointer()->handle;
        }
        out.GetPointer()->handle = INVALID_HANDLE;  // for libeiffel to fill in
        return rc;
    };

};  // namespace efl::ipc
