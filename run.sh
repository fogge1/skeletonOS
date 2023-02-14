#!/bin/bash

MAKE=0
DEBUG=0
DEBUGARG=""

while getopts "md:" opt; do
  case "$opt" in
    m)
      echo tets
      MAKE=1
      ;;
    d)
      DEBUG=1 
      DEBUGARG=$OPTARG
      ;;
  esac
done
shift $((OPTIND -1))

[ "$MAKE" -eq 1 ] && make iso


if [[ "$DEBUG" -eq 1 ]]; then 
  qemu-system-i386 -drive format=raw,file=skeletonOS.iso -S -s &
  gdb -x gdb/run.gdb -ex debug_$DEBUGARG
else
  qemu-system-i386 -drive format=raw,file=skeletonOS.iso
fi
