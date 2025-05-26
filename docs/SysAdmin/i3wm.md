# Setting up i3wm on a Thinkpad computer (perhaps useful for other brands)
First, check out which GPU your computer has, if it is a Thinkpad, an older model,
then most likely it mounts an integrated graphics processor that we'll refer to as "intel graphics".
Neofetch is a quick way to check this out.
Then, it is time to 

## Brightness Control
### Checking `ls /sys/class/backlight` output

If `/sys/class/backlight` is empty on your ThinkPad T440p, it usually means that the kernel isn't detecting any backlight control interfaces. This is common with some older laptops or specific Linux setups, especially if the GPU or ACPI backlight settings aren’t fully compatible. Here are a few steps you can try to troubleshoot and hopefully resolve this issue:

#### 1. Check Kernel Boot Parameters
Some kernel parameters can help expose backlight controls. 
Try adding one of these parameters to your boot configuration:

1. Open your boot loader configuration file (usually `/etc/default/grub` for GRUB).
2. Edit the `GRUB_CMDLINE_LINUX_DEFAULT` line, adding one of the following options:
   - For Intel graphics: 
     ```
     acpi_backlight=video
     ```
   - Or:
     ```
     acpi_backlight=vendor
     ```
   - Alternatively:
     ```
     acpi_osi=Linux acpi_backlight=native
     ```

On my Thinkpad t440p, it is:
```shell
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash acpi_backlight=video"
```

3. Update GRUB with:
   ```bash
      sudo update-grub
   ```
4. Reboot your system and check if `/sys/class/backlight` now contains an entry.


### 2. Install `xbacklight` (If Not Already Installed)
If you have an Intel GPU, `xbacklight` can often control brightness at the software level, even if hardware backlight control isn’t available:
```bash
sudo apt install xbacklight
xbacklight -set 50  # Sets brightness to 50%
```

### 3. Test Intel or ACPI Video Drivers
If you’re using the Intel graphics driver, ensure it’s installed and loaded:
```bash
lsmod | grep i915
```
If `i915` isn’t loaded, add it manually:
```bash
sudo modprobe i915
```

### 4. Use `intel_backlight` (if Available)
On some systems, you might find backlight control under `/sys/class/backlight/intel_backlight`. If it’s there, you can adjust brightness directly by writing values to the `brightness` file inside:
```bash
echo [value] | sudo tee /sys/class/backlight/intel_backlight/brightness
```
Adjust `[value]` within the range found in `max_brightness`.

Let me know if any of these options work, or if you'd like more tailored troubleshooting!

https://wiki.archlinux.org/title/Backlight

### Then, by following `https://www.reddit.com/r/thinkpad/comments/e9b9ja/brightness_and_volume_buttons_on_linux/?rdt=42208`
You're going to need to have xf86-video-intel installed.

#### How to install xf86-video-intel

The `xf86-video-intel` driver is an open-source Intel graphics driver used for systems running X11 on Linux. This driver is commonly recommended for older Intel GPUs, while newer Intel graphics chips (since around the Skylake generation) are usually well-supported by the default `modesetting` driver. Here’s how to install `xf86-video-intel` on various Linux distributions:

##### 1. **Check if You Need the Intel Driver**
   - For most modern Intel GPUs (especially Skylake or newer), the `modesetting` driver works well, and `xf86-video-intel` may not provide additional benefits.
   - You can check your GPU generation by running:
     ```bash
     lspci | grep -i VGA
     ```
   - If your GPU is older (like Haswell or earlier), `xf86-video-intel` can be beneficial.

##### 2. **Installation by Distribution**

###### **On Ubuntu and Debian**
   - Update package repositories and install `xf86-video-intel`:
     ```bash
     sudo apt update
     sudo apt install xserver-xorg-video-intel
     ```
   - Once installed, restart your X session (log out and log back in, or restart the system) to apply the driver.

###### **On Arch Linux and Manjaro**
   - Arch and its derivatives typically use `modesetting` by default, but you can install `xf86-video-intel` if needed:
     ```bash
     sudo pacman -S xf86-video-intel
     ```
   - Restart your X session to start using the Intel driver.

###### **On Fedora**
   - Fedora doesn’t package `xf86-video-intel` by default because it prefers the `modesetting` driver. However, you can install it from the Fedora repositories:
     ```bash
     sudo dnf install xorg-x11-drv-intel
     ```
   - After installation, restart the X session.

###### **On openSUSE**
   - Install `xf86-video-intel` using the package manager:
     ```bash
     sudo zypper install xf86-video-intel
     ```

##### 3. **Confirm the Driver is Active**
   - After installing and restarting, verify that `xf86-video-intel` is being used by running:
     ```bash
     inxi -G
     ```
   - Alternatively, you can check your Xorg log:
     ```bash
     cat /var/log/Xorg.0.log | grep -i intel
     ```
   - This should show whether the Intel driver is active.

If you encounter issues or your system defaults to `modesetting`, consider removing `xf86-video-intel` since the newer modesetting driver is often more stable and compatible with modern hardware.

##### How to Switch to `xf86-video-intel`

If you’d still like to use `xf86-video-intel`, here’s what you can do:

1. **Create an Xorg Configuration File for Intel**:
   - Create a configuration file to specify the Intel driver:
     ```bash
     sudo mkdir -p /etc/X11/xorg.conf.d
     sudo nano /etc/X11/xorg.conf.d/20-intel.conf
     ```
   - Add the following configuration:
     ```plaintext
     Section "Device"
         Identifier "Intel Graphics"
         Driver "intel"
     EndSection
     ```
   - Save and close the file.

2. **Restart Your X Session**:
   - Log out and log back in, or restart your computer.

3. **Verify**:
   - After restarting, check if the Intel driver is now in use:
     ```bash
     inxi -G
     ```
   - You should see `driver: X: loaded: intel` instead of `modesetting`.

The `xf86-video-intel` driver can offer additional configuration options for certain older Intel GPUs, but `modesetting` is typically more stable. Let me know if you notice any differences in performance or display after switching!

##### Is this driver active?

```markdown
Graphics:
  Device-1: Intel 4th Gen Core Processor Integrated Graphics driver: i915
    v: kernel
  Display: x11 server: X.Org v: 1.21.1.4 driver: X: loaded: modesetting
    unloaded: fbdev,vesa gpu: i915 resolution: 1600x900~60Hz
  OpenGL: renderer: Mesa Intel HD Graphics 4600 (HSW GT2)
    v: 4.6 Mesa 23.2.1-1ubuntu3.1~22.04.2
```

From your output, it appears that the `xf86-video-intel` driver is **not active**. Instead, your system is using the **modesetting** driver (`driver: X: loaded: modesetting`), which is provided by default for Intel GPUs on many Linux distributions.

Here’s a breakdown of what each line in your output means:

- **Driver in Use**: The X server is using the `modesetting` driver for your display, which is common and often recommended for stability, especially with somewhat newer hardware.
- **Kernel Driver**: The `i915` driver is loaded by the Linux kernel to manage Intel graphics hardware. This driver interacts directly with the Intel GPU at the kernel level and is compatible with both the `modesetting` and `xf86-video-intel` X drivers.
- **OpenGL Renderer**: OpenGL is using the `Mesa Intel HD Graphics 4600` driver, which provides 3D rendering and hardware acceleration.

Whereas, if the output looks like this: 

```markdown
how about this Graphics:
  Device-1: Intel 4th Gen Core Processor Integrated Graphics driver: i915
    v: kernel
  Display: x11 server: X.Org v: 1.21.1.4 driver: X: loaded: intel gpu: i915
    resolution: 1600x900~60Hz
  OpenGL: renderer: Mesa Intel HD Graphics 4600 (HSW GT2)
    v: 4.6 Mesa 23.2.1-1ubuntu3.1~22.04.2
```

This output shows that the `xf86-video-intel` driver is now **active**. Here's how we can tell:

- **X Driver Loaded**: The line `driver: X: loaded: intel` indicates that the X server is now using the `intel` driver, which comes from the `xf86-video-intel` package.
- **Kernel Driver**: The `i915` kernel driver is still managing the Intel GPU at the kernel level, as expected. This is normal, as `i915` is the kernel module responsible for handling Intel graphics hardware.
- **OpenGL Renderer**: OpenGL continues to use the Mesa Intel driver for the HD Graphics 4600, which provides 3D rendering and hardware acceleration.

With the `xf86-video-intel` driver active, you may gain some additional configuration options specific to Intel hardware, like `TearFree` (for tear-free display) and power-saving features. However, if you encounter any performance issues, switching back to the `modesetting` driver is an option, as it tends to be more stable for some configurations. 

#### Install xbacklight

1. Check whether xbacklight works (xbacklight -inc 25, xbacklight -dec 25)

2. Find out what the brightness keys are called with xev (probably something like XF86MonBrightnessUp and XF86MonBrightnessDown)

3. Create hotkeys in your i3 configuration (e.g. bindsym XF86MonBrightnessDown exec xbacklight -dec 25)

That's for brightness, for volume you do the same but use amixer to set the volume 
(e.g. amixer set Master 4%+ and amixer set Master toggle).

xev got me this output: RRNotify event, serial 49, synthetic NO, window 0x2c00001,
    subtype XRROutputPropertyChangeNotifyEvent
    output eDP1, property Backlight, timestamp 739909, state NewValue

RRNotify event, serial 49, synthetic NO, window 0x2c00001,
    subtype XRROutputPropertyChangeNotifyEvent
    output eDP1, property BACKLIGHT, timestamp 739909, state NewValue
    The output from `xev` indicates that `RRNotify` events are being generated for the "Backlight" and "BACKLIGHT" properties on your laptop's internal display (`eDP1`). These events are triggered by changes in the backlight level, which suggests that you do have access to the backlight control through X11's `RandR` (Resize and Rotate) extension.

Here are a few steps to help you set up backlight control:

1. **Verify available backlight interfaces**:
   Run the following command to check which backlight interfaces are available:
   ```bash
   ls /sys/class/backlight/
   ```
   If you see entries like `intel_backlight` or `acpi_video0`, these are your backlight control interfaces. 

2. **Adjust the backlight level manually**:
   You can test setting the brightness by writing directly to the `brightness` file under the appropriate backlight interface. For instance, if `intel_backlight` is available:
   ```bash
   echo 1000 | sudo tee /sys/class/backlight/intel_backlight/brightness
   ```
   Note that `1000` here is an example; valid values range from `0` to the maximum value shown in `/sys/class/backlight/<interface>/max_brightness`.

3. **Automate with `xrandr`**:
   Since `xev` detected the `Backlight` property change events, you might be able to adjust brightness using `xrandr` commands. Try this to control brightness on `eDP1`:
   ```bash
   xrandr --output eDP1 --brightness 0.5  # Adjust the brightness level (0.0 to 1.0)
   ```
   This approach only simulates brightness changes through software and may not change the actual backlight level.

4. **Integrate with i3wm**:
   To set up keybindings in `i3wm`, you can edit your i3 config file (typically `~/.config/i3/config`) to include commands that adjust brightness. For example:
   ```bash
   bindsym XF86MonBrightnessUp exec --no-startup-id xbacklight -inc 10
   bindsym XF86MonBrightnessDown exec --no-startup-id xbacklight -dec 10
   ```
   Ensure `xbacklight` is installed (`sudo apt install xbacklight`).

This setup should give you backlight control in i3wm on your ThinkPad T440p using X11. Let me know if any specific part needs more detail.

## Keeping the laptop's display output up when the lid is closed

To ensure that your ThinkPad T440p continues to display output on the external monitor when you close the laptop lid, you'll need to modify the system settings related to lid close behavior. Here’s how you can do it on your i3-based Linux setup:

### 1. **Edit `logind.conf`**
The systemd `logind.conf` file controls what happens when you close the lid.

1. Open the `logind.conf` file with your preferred text editor. For example:
   ```bash
   sudo nano /etc/systemd/logind.conf
   ```

2. Look for the following lines (they might be commented out with `#`):
   ```
   #HandleLidSwitch=suspend
   #HandleLidSwitchExternalPower=suspend
   #HandleLidSwitchDocked=ignore
   ```

3. Modify them as follows:
   ```
   HandleLidSwitch=ignore
   HandleLidSwitchExternalPower=ignore
   HandleLidSwitchDocked=ignore
   ```

   - `ignore`: Prevents any action when the lid is closed.
   - These settings ensure that the external monitor remains active when the lid is closed.

4. Save and exit the file.

5. Restart the `systemd-logind` service to apply the changes:
   ```bash
   sudo systemctl restart systemd-logind
   ```

---

### 2. **Configure Display Settings**
You may need to adjust your display settings to ensure the external monitor remains active when the lid is closed.

- Use a tool like `xrandr` to configure your display setup. For example:
  ```bash
  xrandr --output <external-monitor> --primary --output <laptop-screen> --off
  ```
  Replace `<external-monitor>` and `<laptop-screen>` with the appropriate names for your displays (e.g., `HDMI1`, `eDP1`).

---

### 3. **Test the Setup**
1. Connect your external monitor.
2. Close the laptop lid.
3. Verify that the external monitor remains active and functional.

---

Let me know if you encounter any issues!