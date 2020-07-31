#pragma once

#include <eiffel.h>

#include <stratosphere.hpp>

#include "../logger/types.hpp"

namespace efl {
namespace ipc {

    class ServiceProvider final : public ams::sf::IServiceObject {
       protected:
        enum class CommandId {
            Log = EFL_CMD_LOG,
        };

       public:
        explicit ServiceProvider();
        virtual ~ServiceProvider();

       private:
        ams::Result Log(const ams::sf::InBuffer&, efl::logger::LogLevel, const ams::sf::InBuffer&);

       public:
        DEFINE_SERVICE_DISPATCH_TABLE{
            MAKE_SERVICE_COMMAND_META(Log),
        };
    };

};  // namespace ipc
};  // namespace efl
