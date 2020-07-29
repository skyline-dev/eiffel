#pragma once

#include <switch.h>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)
#define _CONCATENATE(x1, x2) x1##x2
#define CONCATENATE(x1, x2) _CONCATENATE(x1, x2)

#define R_FATAL_FAIL(x)                      \
    ({                                       \
        if (Result rc = (x); R_FAILED(rc)) { \
            fatalThrow(rc);                  \
        }                                    \
    })

// debug logging
// #define DEBUG_LOG_FILE
// #define DEBUG_NXLINK
// #define DEBUG_NXLINK_FORCED_IP 0x4500a8c0  // example: c0.a8.00.45 = 192.168.0.69

#ifdef NDEBUG
#define LOG(...) ({})
#else
void debugLogFormat(const char* prettyFunction, const char* fmt, ...);
#define LOG(fmt, ...) debugLogFormat(__PRETTY_FUNCTION__, fmt "\n" __VA_OPT__(, ) __VA_ARGS__)
#endif

void debugInit();
void debugExit();
