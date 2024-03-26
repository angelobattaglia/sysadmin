# Arch linux

References:

- [Gentoo AMD 64 handbook](https://wiki.gentoo.org/wiki/Handbook:AMD64)
- [Archwiki](archwiki.org)

The best guide to follow is the Archwiki, as it is always up to date. This guide, however, will give more explanations throughout
the process, by spending more words for each step.

## Setting the keymap

When in "root@archiso", list all of the available keymaps:

```shell
ls /usr/share/kbd/keymaps/**/*.map.gz
```

loadkeys: it-latin1

## Internet through the Smartphone tethering

- [Setting up the internet](https://wiki.archlinux.org/title/iwd)

We enter the deamon called "iwd" which then appears as a prompt where we input commands

```shell
iwctl
```

This command prompts out the list of wi-fi devices through which we can connect to a given network

```shell
device list
```

Let's call the device that we're using "wlan0", SSID is the name of the chosen network we want to connect, it then asks for a passphrase. More details about this [on this link](https://wiki.archlinux.org/title/iwd).

```shell
station wlan0 scan
station wlan0 get-networks
# SSID is the name of the Wi-Fi
station wlan0 connect SSID
```

### Checking Network connection

After connecting, type "exit" while on the iwd daemon to quit the program, then, as root user, type the following to check out if the connection was successful.

```shell
ping google.com
```

## Making sure our system clock is accurate

```shell
timedatectl set-ntp true
```

```shell
timedatectl set-timezone Europe/Rome
```

Verify it with

```shell
timedatectl status
```

## Disk partitioning with fdisk

/dev/sda is the name of the drive we want to partition, where it will be mounted
the various parts of the system, among which "/mnt", where the OS will be mounted.

```shell
fdisk -l # listing all of our drives
fdisk /dev/sda #the name of the Disk where I want to install Arch
```

Creating a new Label

```shell
g # to create a GPT partition table, for EFI
```

### Using fdisk to create three partitions

### Partitioning the EFI system (the modern BIOS substitute)

```shell
n
# input number "1"
# press the enter key (default 2048)
+550M # megabytes for the EFI partition # Don't input "n" again, there's a question .. answer "yes"
```

### Swap partition

```shell
n
2
# enter (default 2048)
+2G # two gigabytes for the swap partition
```

### Linux file system partition

```shell
n
3
# enter (dafault 2048)
# enter allocates the remaining storage for the linux file system
```

#### If any mistakes are being made

Se sbaglio ad assegnare il tipo di partizione delle prime due, posso
sempre premere t e il numero della partizione alla quale devo cambiare
il tipo:

esempio:
t
1
L per listare i tipi di partizione disponibili
1 per EFI System
e cambia da linux file system a EFI System

t
2
L per listare i tipi di partizione disponibili
19 per Linux swap
e cambia da linux file system a Linux swap

Alla fine premi w per scrivere sul disco le nostre impostazioni

## File System

Ora dobbiamo creare i diversi tipi di File System rispettivamente per
ogni partizione che abbiamo creato:

Creating the file system Fat 32 in sda1
```shell
mkfs.fat -F32 /dev/sda1
```

Create the SWAP partition in sda2
```shell
mkswap /dev/sda2
```

Activate the SWAP partition
```shell
swapon /dev/sda2
```

Creating the File System in sda3
```shell
mkfs.ext4 /dev/sda3
```

Mount the file system
```shell
mount /dev/sda3 /mnt
```

Installing the base system with pacstrap
```shell
pacstrap /mnt base linux linux-firmware
```

### Generating system tabular file fstab which gives infos on our partitioning:

```shell
genfstab -U /mnt >> /mnt/etc/fstab
```

Ora diventiamo root della nostra installazione, ovvero passiamo dalla pendrive alla partizione /dev/sda3:
arch-chroot /mnt

Ora il prompt dovrebbe essere cambiato, perché siamo nel nostro sistema operativo di base nella nostra partizione
/dev/sda3 dentro il nostro file system

## Locale

Setting the time-zone

```shell
ln -sf /usr/share/zoneinfo/Europe/Rome /etc/localtime
```

If I had to list them all

```shell
ls /usr/share/zoneinfo
```

System clock settings:

```shell
hwclock --systohc
```

### Install neovim

```shell
pacman -Sy neovim
```

### Install iwd

```shell
pacman -Sy iwd
```

### Setting up the Locale

```shell
vim /etc/locale.gen
en_US.UTF-8 UTF-8
```

Now activate the locale.gen 

```shell
locale-gen
```

Creating a config file on /etc/hostname

```shell
vim /etc/hostname
# I could write, for example:
t440p
```

## Modifichiamo il file hosts

```shell
vim /etc/hosts
  ```

And I write on it the following..

```shell
127.0.0.1 localhost
::1 localhost
127.0.1.1 t440p.localdomain t440p
```

## Creating the Users with their relative passwords

The default user is the root user. To create other users
Ora devo creare diversi utenti e una password, altrimenti ci sarà solo 1 utente, ovvero il root
Per la password root basta passwd senza nessun parametro da linea di comando:
passwd
3394
Per l'utente:
useradd -m angelo
Creo password utente:
passwd angelo
3394

Checkpoint 21:20

Su Unix ci sono vari gruppi ai quali gli utenti possono partecipare.
usermod è il comando in questione. Aggiungo l'utente angelo ai seguenti
gruppi:
usermod -aG wheel,audio,video,optical,storage angelo
Edito il file sudoers dove sudo attribuisce i privilegi, e io voglio dare all'utente angelo il privilegio di usare sudo:
visudo
Tolgo il commento da:

```shell
# %wheel ALL=(ALL) ALL // Da rivedere bene ..
```

### Install sudo

```shell
pacman -S sudo
```

### Install grub

```shell
pacman -S grub
```

### Installing other useful packages

```shell
pacman -S efibootmgr dosfstools os-prober mtools
```

### Mounting the EFI partition
mkdir /boot/EFI
mount /dev/sda1 /boot/EFI
This doesn't work (don't know why):
grub-install --target=x86_64-efi --bootloader-id=grub_uefi --recheck

Heads up for those with MSI boards, apparently for some MSI bios versions it doesn't 
recognize the standard grub installation path so it would boot to the bios, bypassing grub completely. 
Luckily it's a simple fix you have to add --removable so the right command be 
"grub-install --target=x86_64-efi --removeable --bootloader-id=grub_uefi --recheck". 
Credit goes to Ryan in the comments of the Open 
Source Home's tutorial of how to install arch that video is also here on Youtube.
This works:
grub-install --target=x86_64-efi --bootloader-id=GRUB --efi-directory=/boot/EFI --removable
Creo il file delle configurazioni di grub:
grub-mkconfig -o /boot/grub/grub.cfg

Install iwd onto the machine before leaving the live installation process
https://bbs.archlinux.org/viewtopic.php?id=187798

Install network manager:
pacman -S networkmanager vim xorg

Enable networkmanager with systemd:
systemctl enable NetworkManager
systemctl enable iwd

exit the chroot
exit

Unmount
umount -l /mnt

Ora ci sono due strade:
1) reboot se sei con un vero pc

2) shutdown now se sei in una VM
vai su storage
clicca sulla iso
e rimuove lo storage e restart

Linux Drive and Partition Config (dd, fdisk, resize2fs, lsblk, tune2fs and more)
Sed, Awk, Grep, Cat, gpg, ssh, git, make, zsh
