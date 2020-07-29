#include <switch.h>

#include "util.hpp"

extern "C" {
u32 __nx_applet_type = AppletType_None;
u32 __nx_fs_num_sessions = 1;

#define INNER_HEAP_SIZE 0x1000000
size_t nx_inner_heap_size = INNER_HEAP_SIZE;
char nx_inner_heap[INNER_HEAP_SIZE];

void __libnx_initheap(void) {
    extern char* fake_heap_start;
    extern char* fake_heap_end;
    fake_heap_start = nx_inner_heap;
    fake_heap_end = nx_inner_heap + sizeof(nx_inner_heap);
}

void __attribute__((weak)) __appInit(void) {
    R_FATAL_FAIL(smInitialize());
    R_FATAL_FAIL(fsInitialize());

    fsdevMountSdmc();

    auto socketConfig = SocketInitConfig{.bsdsockets_version = 1,
                                         .tcp_tx_buf_size = 0x800,
                                         .tcp_rx_buf_size = 0x1000,
                                         .tcp_tx_buf_max_size = 0,
                                         .tcp_rx_buf_max_size = 0,
                                         .udp_tx_buf_size = 0x2400,
                                         .udp_rx_buf_size = 0xA500,
                                         .sb_efficiency = 1};
    R_FATAL_FAIL(socketInitialize(&socketConfig));

    debugInit();
}

void __attribute__((weak)) __appExit(void) {
    debugExit();
    fsdevUnmountAll();
    fsExit();
    socketExit();
    smExit();
}
}  // extern "C"

int main(int argc, char* argv[]) {
    LOG("bruh");
    return 0;
}
