#pragma once

#include <eiffel/sl.h>

#include <stratosphere.hpp>

#include "../core/plugin_handler.hpp"
#include "../logger/types.hpp"

namespace efl::ipc {

    class SlService final : public ams::sf::IServiceObject {
       protected:
        enum class CommandId {
            Log = EFL_SL_CMD_LOG,
            RegisterPlugin = EFL_SL_CMD_REGISTER_PLUGIN,
            RegisterSharedMem = EFL_SL_CMD_REGISTER_SHARED_MEM,
        };

       public:
        explicit SlService();
        virtual ~SlService();

       private:
        ams::Result Log(const ams::sf::InBuffer& module_name, efl::logger::LogLevel level,
                        const ams::sf::InBuffer& buf);
        ams::Result RegisterPlugin(SlPluginMeta meta);
        ams::Result RegisterSharedMem(core::PluginName name, SlPluginSharedMemInfo sharedMemInfo);

       public:
        DEFINE_SERVICE_DISPATCH_TABLE{
            MAKE_SERVICE_COMMAND_META(Log),
            MAKE_SERVICE_COMMAND_META(RegisterPlugin),
            MAKE_SERVICE_COMMAND_META(RegisterSharedMem),
        };

        static constexpr auto SERVICE_NAME = ams::sm::ServiceName::Encode(EIFFEL_SKYLINE_SERVICE_NAME);
    };

};  // namespace efl::ipc
