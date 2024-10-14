# Tweaking the System

## Chaning resolution of the screen with xrandr

Listing all possible resolution settings

```shell
xrandr
```

Listing the names of the active monitors

```shell
xrandr --listactivemonitors
```

Give an active monitor named "eDP-1", this sets the resolution at 1024x768

```shell
xrandr --output eDP-1 --mode 1024x768
```

## Symlinking

### Usefulness of symbolic linking

After installing telegram on my machine, in some location, I could
just create a symbolic link to allow dmenu to find the program
among the /usr/bin/ (and possibly even /usr/local/bin/) executables. 
dmenu actively finds its own executables from that directory. 
The implications are that since that directory is also part of
the $PATH environment variable, at least for ZSH and Bash, we can invoke these
executables also from the commandline itself, no matter the path
we're in while navigating the file system with out shell.

```shell
sudo ln -s /home/angelo/AppImages/Telegram/Telegram /usr/bin/telegram
```
