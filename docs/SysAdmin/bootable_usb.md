## Using `woeusb` for Windows

Let's check the path of the USB drive we connected to the computer
```shell
sudo fdisk -l
```

If it is mounted already, you want to unmount it, check it with `lsblk`:
if there's a path on the file system that is related to the USB drive, then
it's mounted, it is possible to unmount it this way
```shell
sudo umount /dev/sdb1
sudo umount /dev/sdb2
```
of course this formatting depends on your specific naming.

Then, finally, in my case, the path to the windows .iso file is in the `~/Desktop/` folder
and the one to the usb drive is `/dev/sdb/`
```shell
sudo ./woeusb-5.2.4.bash --device ~/Desktop/Win11_24H2_English_x64.iso /dev/sdb --tgt-fs NTFS
```

## Bootable USB for linux
Creating a bootable USB drive with a Linux distribution from within a Linux environment can be straightforward and is a common task for those who wish to install Linux on another machine or use a portable version of the operating system. There are several tools available for this purpose, but two of the most popular and reliable ones are **dd** and **Balena Etcher**.

### Using dd Command
The `dd` command is a powerful Unix utility for low-level copying of raw data. It is pre-installed in most Linux distributions and is very efficient, though it requires careful handling due to its potential to overwrite any disk if used incorrectly.

#### Steps to Create a Bootable USB Using dd:
1. **Download the ISO File**: Download the .iso file of the Linux distribution you want to install from its official website.

2. **Identify Your USB Device**:
   - Insert your USB drive.
   - Open a terminal and run `lsblk` or `fdisk -l` to list all disk partitions and identify your USB drive (usually `/dev/sdb`, `/dev/sdc`, etc.).

3. **Write the ISO to the USB**:
   - **Warning**: This step will erase all existing data on the USB drive.
   - Use the `dd` command:
     ```bash
     sudo dd if=path_to_your_iso.iso of=/dev/sdx bs=4M status=progress oflag=sync
     ```
   - Replace `path_to_your_iso.iso` with the path to your ISO file and `/dev/sdx` with the correct device identifier for your USB drive (not a partition like `/dev/sdx1`).

4. **Wait for the Process to Complete**: The `status=progress` option will show you the write progress.

5. **Safely Eject the USB Drive**: Once done, you can eject the USB drive:
   ```bash
   sync
   sudo eject /dev/sdx
   ```

### Using Balena Etcher
Balena Etcher is a graphical USB image writer that simplifies the process of creating bootable USB drives. It is user-friendly and reduces the risk of accidentally writing to the wrong disk.
