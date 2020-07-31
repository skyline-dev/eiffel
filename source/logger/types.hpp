#pragma once

#include <eiffel/sl.h>

#include <cstdint>

namespace efl {
namespace logger {

    using LogLevel = EiffelLogLevel;

    inline auto GetLogLevelString(LogLevel level) {
        switch (level) {
            case EFL_LOG_LEVEL_INFO:
                return "INFO";
            case EFL_LOG_LEVEL_WARNING:
                return "WARNING";
            case EFL_LOG_LEVEL_ERROR:
                return "ERROR";
            default:
                return "unk";
        }
    }

}  // namespace logger
}  // namespace efl
