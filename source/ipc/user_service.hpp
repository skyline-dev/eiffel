#pragma once

#include <eiffel/user.h>

#include <stratosphere.hpp>

#include "../core/plugin_handler.hpp"

namespace efl::ipc {

    class UserService final : public ams::sf::IServiceObject {
       protected:
        enum class CommandId {
            GetPluginMeta = EFL_U_CMD_GET_PLUGIN_META,
            GetPluginSharedMemInfo = EFL_U_CMD_GET_PLUGIN_SHARED_MEM_INFO,
        };

       public:
        explicit UserService();
        virtual ~UserService();

       private:
        ams::Result GetPluginMeta(ams::sf::Out<SlPluginMeta> out, core::PluginName name);
        ams::Result GetPluginSharedMemInfo(ams::sf::Out<SlPluginSharedMemInfo> out, core::PluginName name);

       public:
        DEFINE_SERVICE_DISPATCH_TABLE{
            MAKE_SERVICE_COMMAND_META(GetPluginMeta),
            MAKE_SERVICE_COMMAND_META(GetPluginSharedMemInfo),
        };

        static constexpr auto SERVICE_NAME = ams::sm::ServiceName::Encode(EIFFEL_USER_SERVICE_NAME);
    };

};  // namespace efl::ipc
