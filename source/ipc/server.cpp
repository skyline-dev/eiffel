#include "server.hpp"

#include "service_provider.hpp"

namespace efl {
namespace ipc {

    Server::Server() {
        R_ABORT_UNLESS(
            m_serverManager.RegisterServer<ServiceProvider>(EIFFEL_SERVICE_NAME, EIFFEL_SERVICE_MAX_SESSIONS));
    }

};  // namespace ipc
};  // namespace efl
