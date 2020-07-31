#include "service_provider.hpp"

#include "../util.hpp"

namespace efl {
namespace ipc {

    ServiceProvider::ServiceProvider() {}

    ServiceProvider::~ServiceProvider() {}

    ams::Result ServiceProvider::Log(const ams::sf::InBuffer& module_name, efl::logger::LogLevel level,
                                     const ams::sf::InBuffer& buf) {
        LOG("[%s][%s] %s", module_name.GetPointer(), logger::GetLogLevelString(level), buf.GetPointer());
        return 0;
    };

};  // namespace ipc
};  // namespace efl
