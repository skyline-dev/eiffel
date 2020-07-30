#pragma once

#include <cstdint>

namespace efl {
namespace logger {

    enum class LogLevel : uint8_t {
        INFO = 0,
        WARNING = 1,
        ERROR = 2,
    };

    inline auto GetLogLevelString(LogLevel level) {
        switch (level) {
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::WARNING:
                return "WARNING";
            case LogLevel::ERROR:
                return "ERROR";
            default:
                return "unk";
        }
    }

}  // namespace logger
}  // namespace efl
