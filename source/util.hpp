#pragma once

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

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
