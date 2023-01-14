# Arch linux

References:

- [Gentoo AMD 64 handbook](https://wiki.gentoo.org/wiki/Handbook:AMD64)
- [Archwiki](archwiki.org)

Linux Drive and Partition Config (dd, fdisk, resize2fs, lsblk, tune2fs and more)
Sed, Awk, Grep, Cat, gpg, ssh, git, make, zsh

## Setting the keymap

List all of the available keymaps: root@archiso $ ls /usr/share/kbd/keymaps/**/*.map.gz
loadkeys: it-latin1

## Internet through the Smartphone tethering

- [Setting up the internet](https://wiki.archlinux.org/title/iwd)

```shell
iwctl
device list
station device scan
station device get-networks
station device connect SSID
```

### Checking Network connection

```shell
ping google.com
```

## Making sure our system clock is accurate

```shell
timedatectl set-ntp true
```

Verify it with

```shell
timedatectl status
```

## Partitioning our disk with fdisk or cfdisk

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

Partitioning the EFI system (the modern BIOS substitute)
```shell
n
# input number "1"
# press the enter key (default 2048)
+550M # megabytes for the EFI partition # Don't input "n" again, there's a question .. answer "yes"
```

Creo la partizione swap:
n
2
enter (default 2048)
+2G due gigabytes per la partizione swap

Creo la partizione per il mio sistema, concedo il resto della memoria:
n
3
enter (dafault 2048)
enter e da' lo spazio rimanente
deve essere di tipo linux file system

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

Ora dobbiamo creare i diversi tipi di File System rispettivamente per
ogni partizione che abbiamo creato:

Ora si deve creare il file system Fat 32 su sda1:
mkfs.fat -F32 /dev/sda1

Ora si deve creare lo swap nella partizione dedita allo swap:
mkswap /dev/sda2
attivo la partizione swap:
swapon /dev/sda2

Creo il file system nella 3 partizione:
mkfs.ext4 /dev/sda3

Mount the file system:
mount /dev/sda3 /mnt

Ora che è montato, installo il sistema di base con pacstrap:
pacstrap /mnt base linux linux-firmware

Ora generiamo il nostro file system tabular fstab (informazioni sulla partizione):
genfstab -U /mnt >> /mnt/etc/fstab

Ora diventiamo root della nostra installazione, ovvero passiamo dalla pendrive alla partizione /dev/sda3:
arch-chroot /mnt

Ora il prompt dovrebbe essere cambiato, perché siamo nel nostro sistema operativo di base nella nostra partizione
/dev/sda3 dentro il nostro file system

Ora devo settare la time zone:
ln -sf /usr/share/zoneinfo/Europe/Rome /etc/localtime
(se devo listare allora: ls /usr/share/zoneinfo)

System clock settings:
hwclock --systohc

installa vim per editare dei files:
pacman -Sy neovim

vim /etc/locale.gen, ogni linea di codice è commentata, devo togliere il commento seguente, per arch americano:
en_US.UTF-8 UTF-8

Minuto 18:10 (checkpoint)

Ora entra questo comando, per attivare il locale.gen 
locale-gen

Ora dobbiamo creare un config file su /etc/hostname
vim /etc/hostname
scrivo ad esempio: t440p

## Modifichiamo il file hosts

vim /etc/hosts
E riporto le seguenti..
127.0.0.1 localhost
::1 localhost
127.0.1.1 t440p.localdomain t440p

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

Installo sudo:
pacman -S sudo
Installo grub:
pacman -S grub
Installo altri pacchetti utili:
pacman -S efibootmgr dosfstools os-prober mtools

Mounting the EFI partition: 
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

Install network manager:
pacman -S networkmanager vim xorg

Enable networkmanager with systemd:
systemctl enable NetworkManager

exit the chroot
exit

Unmount
umount -l /mnt

Ora ci sono due strade:
1) reboot se sei con un vero pc

2) shutdown now se sei in una VM
vai su storage
clicca sulla iso
ed rimuove lo storage e restart
