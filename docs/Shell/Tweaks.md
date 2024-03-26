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