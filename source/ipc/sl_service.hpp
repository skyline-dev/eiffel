#pragma once

#include <eiffel/sl.h>

#include <stratosphere.hpp>

#include "../logger/types.hpp"

namespace efl {
namespace ipc {

    class SlService final : public ams::sf::IServiceObject {
       protected:
        enum class CommandId {
            Log = EFL_SL_CMD_LOG,
        };

       public:
        explicit SlService();
        virtual ~SlService();

       private:
        ams::Result Log(const ams::sf::InBuffer&, efl::logger::LogLevel, const ams::sf::InBuffer&);

       public:
        DEFINE_SERVICE_DISPATCH_TABLE{
            MAKE_SERVICE_COMMAND_META(Log),
        };

        static constexpr auto SERVICE_NAME = ams::sm::ServiceName::Encode(EIFFEL_SKYLINE_SERVICE_NAME);
    };

};  // namespace ipc
};  // namespace efl
