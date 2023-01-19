/* only for use in GDB */
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long long uint64_t;

struct disk_packet_t {
    uint8_t size, reserved;
    uint16_t num_blocks, offset, segment;
    uint64_t lba;
} _1 __attribute__((used));
