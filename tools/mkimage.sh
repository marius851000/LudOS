 
#!/bin/bash


DISK=LudOS.img
SRCDIR=../isodir
BOOT=../isodir/boot

./mkinitrd.sh

# Create a 15Mio blank disk image.
dd if=/dev/zero of=$DISK bs=4096 count=15000

echo "Partitioning..."
# Partition it with fdisk.
cat fdisk.conf | fdisk $DISK

echo "Done partition."

# Here's where we need to be root.
losetup /dev/loop3 $DISK

IMAGE_SIZE=`wc -c < $DISK`
IMAGE_SIZE_SECTORS=`expr $IMAGE_SIZE / 512`
MAPPER_LINE="0 $IMAGE_SIZE_SECTORS linear 7:3 0"

echo "$MAPPER_LINE" | dmsetup create hdd

kpartx -a /dev/mapper/hdd

sleep 1

mkfs.ext2 -O ^dir_index /dev/mapper/hdd1

mount /dev/mapper/hdd1 /mnt

echo "Installing main files."
cp -r $SRCDIR/hdd/* /mnt/

echo "Installing boot files."
mkdir -p  /mnt/boot/grub
cat > /mnt/boot/grub/grub.cfg << EOF
insmod ext2
insmod iso9660
menuentry "LudOS" {
	multiboot /boot/LudOS.bin loglevel=info
    module    /boot/initrd.tar initrd
    module    /boot/stripped.bin kernel_binary
}
EOF

echo "Installing kernel."
cp -r ../build/bin/LudOS.bin /mnt/boot/
cp -r ../build/bin/stripped.bin /mnt/boot/
cp -r ../build/bin/initrd.tar /mnt/boot/

echo "Installing grub."
grub-install --boot-directory=/mnt/boot /dev/loop3

./mkimage-cleanup.sh

if [ -n "$SUDO_USER" ] ; then
    echo "Reassigning permissions on disk image to $SUDO_USER"
    chown $SUDO_USER:$SUDO_USER $DISK
fi

mv $DISK ../build/bin/$DISK

echo "Done. You can boot the disk image with qemu now."
