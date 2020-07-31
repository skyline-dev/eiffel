#include "sl_service.hpp"

#include "../util.hpp"

namespace efl {
namespace ipc {

    SlService::SlService() {}

    SlService::~SlService() {}

    ams::Result SlService::Log(const ams::sf::InBuffer& module_name, efl::logger::LogLevel level,
                               const ams::sf::InBuffer& buf) {
        LOG("[%s][%s] %s", module_name.GetPointer(), logger::GetLogLevelString(level), buf.GetPointer());
        return 0;
    };

};  // namespace ipc
};  // namespace efl
