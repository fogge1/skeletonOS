CC=i686-elf-gcc
AS=nasm
LD=i686-elf-ld

CFLAGS=-m32 -std=c99 -O2 -g -fno-pie -fno-stack-protector
CFLAGS+=-nostdlib -nostdinc -ffreestanding
# Maybe bad for optimizations?
CFLAGS+=-fno-builtin-function -fno-builtin
ASFLAGS=-f elf32 -w+orphan-labels
LDFLAGS=

MBR=mbr.bin
MBR_SRC=src/boot/mbr.asm
#MBR_SRC=src/boot.asm
MBR_OBJ=$(MBR_SRC:.asm=.o)

KERNEL=kernel.bin
KERNEL_SRC_C=$(wildcard src/kernel/*.c)
KERNEL_SRC_ASM=$(wildcard src/kernel/*.asm)
KERNEL_OBJ=$(KERNEL_SRC_C:.c=.o) $(KERNEL_SRC_ASM:.asm=.o)

ISO=skeletonOS.iso

all: dirs mbr

clean:
	rm -f $(MBR_OBJ) $(KERNEL_OBJ) $(ISO)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

%.o: %.asm
	$(AS) -o $@ $< $(ASFLAGS)

dirs:
	mkdir -p bin

mbr: $(MBR_OBJ)
	# $(LD) -o ./bin/$(MBR) $^ $(LDFLAGS) -Ttext 0x0 --oformat=binary
	$(LD) -o ./bin/$(MBR) $^ $(LDFLAGS) -Ttext 0x7c00 --oformat=binary

# used for debugging
#	$(LD) -o ./bin/$(MBR:.bin=.elf) $^ $(LDFLAGS) -Ttext 0x600
	$(LD) -o ./bin/$(MBR:.bin=.elf) $^ $(LDFLAGS) -Ttext 0x7c00

kernel: $(KERNEL_OBJ)
	$(LD) -o ./bin/$(KERNEL) $^ $(LDFLAGS) -Tsrc/link.ld

# used for debugging
	$(LD) -o ./bin/$(KERNEL:.bin=.elf) $^ $(LDFLAGS) -Tsrc/link.ld --oformat=elf32-i386
# kernel here
iso: dirs mbr kernel 
	dd if=/dev/zero of=$(ISO) bs=512 count=2880
	dd if=bin/$(MBR) of=$(ISO) conv=notrunc bs=512 seek=0 count=1
	dd if=bin/$(KERNEL) of=$(ISO) conv=notrunc bs=512 seek=1 count=2048
