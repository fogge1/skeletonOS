# SkeletonOS

Bare bones kernel and bootloader

## Getting started

### Installing
```bash
git clone https://github.com/fogge1/skeletonOS.git
cd skeletonOS
```
### Running
```bash
make iso
qemu-system-i386 -drive format=raw,file=skeletonOS.iso
```

## License
SkeletonOS is licensed under a GPL-2.0 license.

