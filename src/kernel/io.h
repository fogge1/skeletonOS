static inline uint8_t inb(uint16_t port) {
    uint8_t out;
    asm("inb %1, %0" : "=a" (out) : "dN" (port));
    return out;
}

static inline void outb(uint16_t port, uint8_t data) {
  asm("outb %1, %0" : : "dN" (port), "a" (data));
}
