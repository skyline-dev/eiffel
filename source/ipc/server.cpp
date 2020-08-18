#include "server.hpp"

#include "sl_service.hpp"
#include "user_service.hpp"

namespace efl::ipc {

    Server::Server() {
        R_ABORT_UNLESS(
            m_serverManager.RegisterServer<SlService>(SlService::SERVICE_NAME, EIFFEL_SERVICE_MAX_SESSIONS));
        R_ABORT_UNLESS(
            m_serverManager.RegisterServer<UserService>(UserService::SERVICE_NAME, EIFFEL_SERVICE_MAX_SESSIONS));
    }

};  // namespace efl::ipc
