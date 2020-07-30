#pragma once

#include <stratosphere.hpp>

namespace efl {
namespace ipc {

    class Server {
       private:
        static constexpr auto NUM_SERVERS = 1;
        static constexpr auto EIFFEL_SERVICE_NAME = ams::sm::ServiceName::Encode("efl");
        static constexpr auto EIFFEL_SERVICE_MAX_SESSIONS = 5;

        Server();
        Server(const Server&) = delete;
        static inline Server& GetInstance() {
            static Server s_instance;
            return s_instance;
        }

        ams::sf::hipc::ServerManager<NUM_SERVERS> m_serverManager;

       public:
        static inline void Loop() { GetInstance().m_serverManager.LoopProcess(); }
    };

}  // namespace ipc
}  // namespace efl
