## Pandoc

### 1. Install Pandoc:
Make sure you have Pandoc installed on your system. You can download it from the official website: [Pandoc Installation](https://pandoc.org/installing.html).

### 2. Convert .docx to Plain Text:
Use the following command to convert your .docx file to plain text (e.g., Markdown):

```bash
pandoc input.docx -o output.md
```

Replace "input.docx" with the name of your input file and "output.md" with the desired name for the plain text file. You can use Markdown as it is a plain text format that can be easily edited.

### 3. Edit the Plain Text File:
Open the generated plain text file with a text editor of your choice, make the necessary modifications, and save the changes.

### 4. Convert Plain Text Back to .docx:
Once you've made your edits, use the following command to convert the modified plain text file back to .docx:

```bash
pandoc input.md -o output.docx
```

Replace "input.md" with the name of your modified plain text file and "output.docx" with the desired name for the final .docx file.

### Note:
- Pandoc may not perfectly preserve all formatting details of complex .docx files, especially if they contain advanced features. Simple documents generally convert more successfully.
- Depending on your editing needs, you might want to choose a plain text format that best suits your document structure and content.

Please check the Pandoc documentation for any updates or changes in command options beyond my last knowledge update in January 2022. If there are new features or improvements, you may find them in the latest documentation or release notes on the Pandoc website.


2. **Prepare the RTF File**: Make sure your RTF file is accessible and that you know the path to the file.

3. **Open a Command Line Interface**: This could be Command Prompt on Windows, Terminal on macOS, or any terminal emulator on Linux.

4. **Use the Pandoc Command**: To convert the RTF file to Markdown, use the following command in the terminal:
   ```bash
   pandoc -s yourfile.rtf -o outputfile.md
   ```
   Here, replace `yourfile.rtf` with the path to your RTF file, and `outputfile.md` with the desired output Markdown file name.

5. **Check the Output**: After running the command, check the output Markdown file to ensure the conversion went as expected. Depending on the complexity and features used in your RTF file, you might need to make minor manual adjustments to the Markdown file.

Pandoc does a commendable job of converting between file formats, but it's worth noting that some formatting may not be perfectly translated due to differences in how formats handle styles and structures. This is particularly true with rich text formats like RTF, which can include a variety of formatting and embedded objects.

`rtorrent` is a command-line based BitTorrent client for Unix-like operating systems. It is designed to be lightweight and efficient. Here are some basic steps to use `rtorrent`:

### Installation:

First, make sure you have `rtorrent` installed on your system. You can install it using your package manager. For example, on Debian-based systems:

```bash
sudo apt-get update
sudo apt-get install rtorrent
```

### Configuration:

`rtorrent` uses a configuration file located at `~/.rtorrent.rc` by default. You can create or edit this file to customize your settings. Here's a simple example:

```bash
# ~/.rtorrent.rc

# Set the default download directory
directory = ~/Downloads

# Enable and set the port for incoming connections
port_range = 6881-6881
```

### Starting `rtorrent`:

You can start `rtorrent` by simply running the `rtorrent` command in the terminal:

```bash
rtorrent
```

### Basic Usage:

1. **Adding Torrents:**
   - Press `Ctrl + S` to open the prompt for adding a new torrent.
   - Enter the URL or path to the torrent file.

2. **Managing Torrents:**
   - Use `Ctrl + D` to start or stop a torrent.
   - Use `Ctrl + K` to remove a torrent.

3. **Viewing Information:**
   - Use `Ctrl + N` to toggle the view between different panels.

4. **Adjusting Settings:**
   - You can adjust various settings, including download/upload speed limits, by editing the configuration file.

5. **Exiting `rtorrent`:**
   - Use `Ctrl + Q` to exit `rtorrent`.

### Additional Tips:

- You can find more information about `rtorrent` and its keybindings in the [rtorrent User Guide](https://github.com/rakshasa/rtorrent/wiki/User-Guide).

- `rtorrent` has a rich set of features, and you may want to explore additional plugins and configurations based on your needs.

- For advanced users, you can also use the `rtorrent` XMLRPC interface to control `rtorrent` remotely or integrate it with other applications.

Keep in mind that `rtorrent` is a powerful tool, but it may have a steeper learning curve compared to some GUI-based BitTorrent clients. However, it provides a lot of flexibility and control once you get used to it.


To add a torrent to `rtorrent` using a magnet link, follow these steps:

1. **Open `rtorrent`:**
   - Open your terminal and run `rtorrent`.

2. **Adding a Magnet Link:**
   - Press `Ctrl + S` to open the prompt for adding a new torrent.
   - Enter the magnet link when prompted.

   Alternatively, you can start `rtorrent` with the magnet link as a command-line argument:

   ```bash
   rtorrent 'magnet:?xt=urn:btih:your_magnet_link_here'
   ```

   Replace `'magnet:?xt=urn:btih:your_magnet_link_here'` with the actual magnet link you want to use.

3. **Managing Torrents:**
   - Use `Ctrl + D` to start or stop a torrent.
   - Use `Ctrl + K` to remove a torrent.

Remember that some magnet links might require additional trackers or metadata, and `rtorrent` will automatically try to fetch the necessary information.

If you encounter any issues, make sure your `rtorrent` is properly configured and has access to the necessary network resources. Additionally, ensure that your system has the required dependencies for handling magnet links.

Note: Magnet links don't contain the file structure information like traditional torrent files, so `rtorrent` will create a folder with the torrent's hash as the name in your download directory. Inside this folder, it will download the files associated with the magnet link.




`rTorrent` is a text-based BitTorrent client for UNIX and UNIX-like systems, known for its efficiency and minimalist interface. It's highly customizable and often used in combination with a screen or tmux session to allow it to run continuously in the background. Here's a basic guide on how to use `rTorrent`:

### Installation

- **Linux**: `rTorrent` is usually available in the repositories of most Linux distributions. You can install it using your package manager. For example, on Debian-based systems like Ubuntu, you can use `sudo apt-get install rtorrent`.
- **macOS**: You can install `rTorrent` using Homebrew with the command `brew install rtorrent`.

### Starting rTorrent

- Open a terminal and type `rtorrent` to start the program.
- The interface is entirely text-based and navigated using the keyboard.

### Basic Commands

- **Adding a Torrent**: You can add a torrent by pressing `Backspace` and then entering the URL or file path to the .torrent file.
- **Starting/Stopping Downloads**: Use the arrow keys to navigate to the torrent you want to start or stop and press `Ctrl+S` to start or `Ctrl+D` to stop (pressing `Ctrl+D` twice will remove the torrent).
- **Viewing Torrent Details**: Select a torrent and press the right arrow key to view more details about it.
- **Changing Download Directories**: Before starting a torrent, you can change the download directory by pressing `*`, then entering the new path.

### Configuration

- `rTorrent` allows extensive configuration through its `.rtorrent.rc` file located in your home directory. You can set download directories, configure port forwarding, set up rate limits, etc.
- The configuration file uses a simple syntax and is well-documented online.

### Running in the Background

- To keep `rTorrent` running continuously, you can use `screen` or `tmux`. Start a new screen session with `screen`, run `rtorrent`, then detach from the screen with `Ctrl+A, D`.
- You can reattach to the session later with `screen -r`.

### Advanced Usage

- `rTorrent` supports scripting and can be integrated with various web interfaces for easier management.
- It also supports advanced features like RSS feed parsing, scheduling, and automation.

### Note

- Remember that while `rTorrent` is a powerful tool, you should always use it responsibly and legally. Ensure that you have the right to download and share the content you are using `rTorrent` for.

### Further Learning

- For more advanced configurations and usage scenarios, refer to the `rTorrent` user guide or community forums.

`rTorrent` has a learning curve, especially for users not familiar with terminal-based applications, but it's highly regarded for its performance and flexibility once mastered.


Using `rTorrent` directly from the shell involves a combination of command-line navigation and keyboard shortcuts specific to `rTorrent`. Here's a more detailed guide on how to operate `rTorrent` from the shell:

### Launching rTorrent

1. **Open your terminal**: This can be done by searching for “Terminal” in your applications menu or using a keyboard shortcut, often `Ctrl+Alt+T` on Linux.
2. **Start rTorrent**: Simply type `rtorrent` and press `Enter`. This will launch the `rTorrent` interface within your terminal.

### Navigating the Interface

- **Navigation**: Use the `Up` and `Down` arrow keys to navigate through the list of torrents.
- **Details View**: To view details of a selected torrent, press the `Right` arrow key. To return to the main view, press the `Left` arrow key.

### Managing Torrents

- **Adding a Torrent**: Press `Backspace`, then type the URL or path to the .torrent file and press `Enter`.
- **Starting a Torrent**: Select a torrent with the arrow keys and press `Ctrl+S` to start it.
- **Stopping a Torrent**: Select the torrent and press `Ctrl+D` to stop it. Pressing `Ctrl+D` again removes the torrent from the list.
- **Changing the Download Directory**: Before starting a torrent, select it, press `*`, then type the path to the desired download directory and press `Enter`.

### Monitoring and Adjusting Torrents

- **Checking Download/Upload Speed**: The bottom of the `rTorrent` interface shows the global download and upload rates.
- **Adjusting Speed Limits**: You can set



Torrenting is a method of downloading and sharing files through a peer-to-peer (P2P) network. `rTorrent` is a popular, command-line based torrent client for Linux and Unix systems. It uses the libTorrent library, which is known for its high performance and low resource usage. Here's a basic guide on how to use `rTorrent` for torrenting:

### Installation

First, you need to install `rTorrent`. This can vary based on your operating system, but for most Linux distributions, you can use the package manager. For example, on Debian-based systems, you can install it using:

```bash
sudo apt-get update
sudo apt-get install rtorrent
```

### Basic Usage

1. **Starting rTorrent**: Simply type `rtorrent` in your terminal and press Enter. This will open the `rTorrent` interface in your terminal.

2. **Adding a Torrent**: To download a file using a torrent, you need a torrent file or a magnet link. You can add a torrent in `rTorrent` by:
   - Hitting the `Enter` key to bring up the command line at the bottom of the interface.
   - Typing the path to the torrent file or pasting the magnet link, then pressing `Enter` again to start the download.

3. **Managing Torrents**: Once a torrent is added, you can see it in the main window. You can navigate through the list of torrents using the up and down arrow keys. Here are some basic commands:
   - `^S` (Ctrl+S): Start the download.
   - `^D` (Ctrl+D): Stop the download or remove the torrent if pressed twice.
   - `^K` (Ctrl+K): Stop and close the torrent (removes it from the list but doesn't delete the files).

4. **Monitoring Progress**: The main interface shows the progress of your downloads, including information like download and upload speed, file size, and completion percentage.

5. **Exiting rTorrent**: You can exit `rTorrent` by pressing `Ctrl+Q`. Ensure that your downloads are either paused or completed before exiting to avoid data loss.

### Configuration

`rTorrent` is highly customizable through its configuration file, usually located at `~/.rtorrent.rc`. You can edit this file to set default directories for downloads, configure port ranges, set up speed limits, and much more. Here are a few basic settings you might want to configure:

- **Download directory**: Set the default directory where your downloads will be stored.
  ```
  directory = ~/Downloads
  ```
- **Session directory**: Specify the directory where `rTorrent` will store its session data.
  ```
  session = ~/.rtorrent/session
  ```
- **Port range**: Define the range of ports `rTorrent` will use for incoming connections, which is crucial for optimizing download speeds.
  ```
  port_range = 50000-50000
  ```
- **DHT and Peer Exchange**: Enable DHT (Distributed Hash Table) and Peer Exchange for better peer discovery.
  ```
  dht = auto
  peer_exchange = yes
  ```

After editing the configuration file, restart `rTorrent` for the changes to take effect.

### Advanced Usage

`rTorrent` supports advanced features like watch directories (to automatically add torrents), scheduling, and scripting. These can be configured in the `.rtorrent.rc` file. For example, to set up a watch directory:

```
schedule = watch_directory,5,5,load.start=/path/to/watch/directory/*.torrent
```

This command tells `rTorrent` to check the specified directory every 5 seconds for new `.torrent` files and automatically start downloading them.

### Conclusion

`rTorrent` is a powerful and efficient CLI torrent client suitable for users who prefer a lightweight and configurable option. It might have a steeper learning curve due to its command-line nature, but it offers great flexibility and performance for managing torrents.


Downloading content via a magnet link using `rTorrent` or any other torrent client involves a simple process. Magnet links are a popular way to share and download torrents without the need for a physical `.torrent` file. They provide a method to directly connect to the torrent's content using a hash value.

Here's how you can download content using a magnet link in `rTorrent`:

### 1. Launch `rTorrent`
Open your terminal and start `rTorrent` by typing `rtorrent` and pressing Enter. This will bring up the `rTorrent` user interface in your terminal window.

### 2. Add the Magnet Link
To add a magnet link, you need to be in the `rTorrent` command line mode:
- Press `Backspace` or `Enter` to get to the bottom command line within the `rTorrent` interface.
- Type the following command (but don't press Enter yet):
  ```
  load.normal
  ```
- After typing `load.normal`, press `Space`, and then paste your magnet link right after it. The command should look something like this (with a much longer magnet link):
  ```
  load.normal magnet:?xt=urn:btih:EXAMPLE
  ```
- Press `Enter` to add the magnet link to `rTorrent`. The download should start automatically if the magnet link is valid and there are available peers.

### 3. Monitor the Download
Once the magnet link is added, you can see the download in the main `rTorrent` window. You can monitor its progress, including download speed, upload speed, and completion percentage.

### 4. Manage the Download
While the download is active, you can use various `rTorrent` commands to manage it:
- To pause or stop the download, highlight it using the arrow keys and press `Ctrl+S`.
- To resume a paused download, select it and press `Ctrl+S` again.
- To remove the torrent, select it and press `Ctrl+D`. Pressing `Ctrl+D` again will remove the torrent from the list but won't delete the downloaded files.

### 5. Exit `rTorrent`
Once your download is complete, or if you need to exit `rTorrent` for any reason, make sure to properly close it by pressing `Ctrl+Q`. This ensures that your session data is saved correctly.

### Note on Magnet Links
Magnet links start downloading metadata (including the list of files and their sizes) from peers in the swarm before the actual content download begins. This process might take a few moments depending on the number of available peers and the overall health of the torrent.

By following these steps, you can easily download files using magnet links in `rTorrent`. Remember that the speed and availability of your downloads depend on the torrent's health and the number of seeders and peers in the swarm.

The `nvidia-smi` (NVIDIA System Management Interface) command-line tool is a powerful utility for monitoring and managing NVIDIA GPU devices. It provides real-time information about GPU usage, memory usage, temperature, and more. Here’s how you can use it effectively:

### Basic Usage

1. **Open a Terminal**: On your Linux system, open a terminal window.

2. **Run `nvidia-smi`**: Type the following command and press Enter:

   ```bash
   nvidia-smi
   ```

   This command will display a summary of the GPU status, including:

   - GPU ID and name
   - Driver version
   - GPU memory usage (total, used, and free)
   - GPU utilization (percentage of GPU resources being used)
   - Temperature
   - Running processes using the GPU

### Example Output

Here’s an example of what the output might look like:

```
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 510.39.01    Driver Version: 510.39.01    CUDA Version: 11.6         |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  MemUsage | GPU Util  Compute M. | GPU Memory  | GPU-Util  |
| GPU  Power Draw  | GPU Memory Util  | Process Name  | PID  |
|===============================+======================+======================+
|   0  GeForce GTX 1080 Ti  On | 00000000:01:00.0 Off |                  N/A |
|  0%   36C    P8    22MiB / 11264MiB |      0%      Default |  0       |
|    0W |      0%  |                      |  N/A  |
+-------------------------------+----------------------+----------------------+
| Processes:                                                                  |
|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
|  ID   ID   ID      |   |       |                             |   Usage      |
|   0    N/A  N/A  N/A   N/A  N/A    N/A                    |      N/A     |
+-----------------------------------------------------------------------------+
```

### Useful Options

Here are some commonly used options with `nvidia-smi`:

1. **Monitor at Regular Intervals**:

   To continuously monitor your GPU every second, use the `-l` (loop) option:

   ```bash
   nvidia-smi -l 1
   ```

   This will refresh the output every second.

2. **Display in CSV Format**:

   To output the information in CSV format, which can be useful for logging or analysis:

   ```bash
   nvidia-smi --query-gpu=timestamp,name,index,utilization.gpu,memory.total,memory.used,memory.free,temperature.gpu --format=csv
   ```

3. **Query Specific Information**:

   You can use the `--query-gpu` option to get specific information about the GPU. For example:

   ```bash
   nvidia-smi --query-gpu=utilization.gpu,memory.used,memory.free --format=csv
   ```

4. **Display GPU Processes**:

   To see which processes are using the GPU:

   ```bash
   nvidia-smi pmon
   ```

5. **Kill a Process**:

   If you want to terminate a process that is using the GPU, you can use the `-p` option followed by the process ID (PID):

   ```bash
   nvidia-smi -i 0 -p <PID>
   ```

6. **Set Application Clocks** (advanced usage):

   You can set application clocks for a specific GPU to manage power and performance:

   ```bash
   nvidia-smi -i 0 -ac <mem_clock>,<graphics_clock>
   ```

### Monitoring Power and Performance

If you want to monitor power usage and performance, you can combine `nvidia-smi` with other monitoring tools. For example, you might want to create a bash script to log data at regular intervals.

### Example Bash Script

Here’s a simple example of a bash script that logs GPU usage every minute:

```bash
#!/bin/bash
while true; do
    echo "Logging GPU usage at $(date)" >> gpu_usage.log
    nvidia-smi --query-gpu=timestamp,name,index,utilization.gpu,memory.total,memory.used,memory.free,temperature.gpu --format=csv >> gpu_usage.log
    sleep 60
done
```

### Conclusion

The `nvidia-smi` command is a versatile tool for monitoring your NVIDIA GPUs. By using various options, you can tailor the information you receive to suit your needs, whether for performance tuning, troubleshooting, or resource management.