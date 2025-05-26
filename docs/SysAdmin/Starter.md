# Starting Shell Programming
Learning how to use sed, awk, grep, cat, fdisk and more

### Tools needed
- Shell: zsh, bash, ash, dash
- Any TUI text editor (Vim, Emacs, Nano ..)
- Any terminal emulator

# Adding to $PATH any folder of executable scripts

Open your ".zshrc" or ".bashrc". Ideally these two files are located in your ~/ folder.
To add the folder named "bin" to the $PATH variable, just add the following to your configuration file

```shell
export PATH="$PATH:/home/username/bin"
```

Now you can write your scripts in python, shell or other languages, making them executable and add
the folder where these scripts are located to your $PATH environment variable to use them everywhere while
browsing your filesystem with the shell

If you have a script that launches a specific application, you can use symlinking and adding to $PATH
to launch that application from anywhere in your file system

```shell
ln -s /home/username/programs/java/eclipse/eclipse /home/username/bin
```

# Getting the size of a directory on the command line

```shell
du -s, --summarize
        # display only a total for each argument

du -h, --human-readable
        # print sizes in human readable format (e.g., 1K 234M 2G)

du -hs
```

Adding a directory to the PATH environment variable in Linux is a useful way to ensure that the executables in that directory can be run from any location in the command line without specifying the full path. Here’s how to add a directory to your PATH in a few steps:

### Temporary Addition

If you want to add a directory to the PATH temporarily, meaning it will only last for the duration of the session or terminal window, you can use the following command in the terminal:

```bash
export PATH=$PATH:/path/to/directory
```

Replace `/path/to/directory` with the actual path of the directory you want to add. This change will last until the terminal is closed.

### Permanent Addition

To make the addition permanent, you will need to add the export command to a startup file like `.bashrc`, `.bash_profile`, or `.profile`, depending on the shell and setup you are using.

1. **Open your terminal**.
2. **Edit the startup file**:
   - If you are using Bash, you can add the directory to your PATH in your `.bashrc` or `.bash_profile` file. Open the file with a text editor, such as nano:
     ```bash
     nano ~/.bashrc
     ```
   - For other shells, like Zsh, you might edit `.zshrc`.

3. **Add the export command** to the end of the file:
   ```bash
   export PATH=$PATH:/path/to/directory
   ```
   Again, replace `/path/to/directory` with your specific directory.

4. **Save and close** the file. For nano, press `Ctrl + X`, then `Y` to confirm, and `Enter` to save.

5. **Source the file** to apply the changes immediately without needing to restart your terminal:
   ```bash
   source ~/.bashrc
   ```
   Replace `.bashrc` with the name of the file you edited, if different.

### Verify the Change

After adding the directory to your PATH, you can verify that it was added successfully by typing:
```bash
echo $PATH
```
This command will display the contents of your PATH variable, and you should see your directory listed there.

Adding directories to the PATH is a common practice for simplifying command executions and script runs, especially for custom scripts or software installed in non-standard locations.


The decision to install binaries in `/usr/bin` or `~/.local/bin` depends on several factors, including user permissions, system scope, and organizational practices. Here's a detailed comparison to help you make an informed choice:

### Installing Binaries in `/usr/bin`
**Pros:**
1. **System-Wide Availability:** Binaries installed in `/usr/bin` are accessible to all users on the system, making them ideal for software that needs to be available system-wide.
2. **Standard Practice:** It's a conventional location for executable binaries, ensuring consistency with many installation scripts and package managers.
3. **Path Inclusion:** By default, `/usr/bin` is included in the system PATH, meaning users can run these binaries without modifying their environment.

**Cons:**
1. **Requires Root Privileges:** Installing binaries in `/usr/bin` typically requires root or superuser privileges, which might not be desirable or possible in all situations.
2. **Risk of Overwriting:** There's a risk of overwriting existing binaries, leading to potential conflicts or system issues.

### Installing Binaries in `~/.local/bin`
**Pros:**
1. **User-Specific Installation:** Binaries installed in `~/.local/bin` are only accessible to the user who installed them, providing a personalized environment without affecting other users.
2. **No Root Required:** Installation in this directory does not require root privileges, making it a safer and more accessible option for users without administrative access.
3. **Conflict Avoidance:** Reduces the risk of overwriting system binaries and minimizes potential conflicts.

**Cons:**
1. **Manual PATH Management:** You might need to manually add `~/.local/bin` to your PATH if it’s not already included. This can be done by adding a line to your shell configuration file (e.g., `.bashrc`, `.zshrc`):

   ```sh
   export PATH="$HOME/.local/bin:$PATH"
   ```

2. **User-Specific:** Binaries are not available system-wide, which might be a limitation if you want other users to have access to the same tools.

### Recommendations
- **For Personal Use and Development:** If you are installing binaries for personal use or development purposes, `~/.local/bin` is generally the better choice. It avoids the need for root privileges and ensures you don’t interfere with system-wide binaries.
  
- **For System-Wide Tools:** If the binaries need to be available to all users or are part of system-wide software, `/usr/bin` is more appropriate, provided you have the necessary administrative rights and are cautious about potential conflicts.

### Practical Example:
Suppose you're installing a custom script or tool you've developed. If it's just for your use, you would:

1. Place the binary in `~/.local/bin`:
   ```sh
   cp my_script ~/.local/bin/
   ```
2. Ensure `~/.local/bin` is in your PATH (if not already):
   ```sh
   echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
   source ~/.bashrc
   ```

For system-wide tools, you would:
1. Use root privileges to place the binary in `/usr/bin`:
   ```sh
   sudo cp my_tool /usr/bin/
   ```

### Conclusion
Choose `~/.local/bin` for user-specific installations and `/usr/bin` for system-wide installations, taking into account permissions, scope, and potential conflicts. This approach ensures flexibility and maintains system integrity.


# My practice

Compiling binaries in a personal directory (like `~/bin`) and then creating symlinks in system-wide or user-specific directories
is indeed a good practice and is commonly followed by experienced users. This approach offers several advantages:

### Advantages of Compiling in `~/bin` and Creating Symlinks
1. **Organization:** Keeps your compiled binaries organized and separate from system-wide binaries, reducing clutter and potential conflicts.
2. **Safety:** Avoids the risk of overwriting system binaries or binaries managed by package managers.
3. **Flexibility:** Makes it easy to update or remove binaries without affecting system directories. You can manage your compiled binaries independently.
4. **Ease of Management:** Simplifies the process of maintaining and upgrading software. You can simply replace the binary in `~/bin` and the symlink remains unchanged.

### Steps to Follow

#### 1. Compile the Binary
First, download and compile the software in your personal directory, such as `~/bin`:

```sh
cd ~/bin
git clone https://github.com/your/repository.git
cd repository
make
# or the appropriate build command (e.g., cmake, ./configure && make, etc.)
```

#### 2. Create a Symlink in `/usr/bin` or `~/.local/bin`
After compiling the binary, create a symlink in either `/usr/bin` (for system-wide access) or `~/.local/bin` (for user-specific access):

- **For System-Wide Access:**

  ```sh
  sudo ln -s ~/bin/repository/compiled_binary /usr/bin/compiled_binary
  ```

- **For User-Specific Access:**

  ```sh
  ln -s ~/bin/repository/compiled_binary ~/.local/bin/compiled_binary
  ```

### Example
Let's take the example of compiling and installing Neovim:

1. **Compile Neovim:**

   ```sh
   cd ~/bin
   git clone https://github.com/neovim/neovim.git
   cd neovim
   make CMAKE_BUILD_TYPE=Release
   ```

2. **Create a Symlink:**

   - **For System-Wide Access:**

     ```sh
     sudo ln -s ~/bin/neovim/build/bin/nvim /usr/bin/nvim
     ```

   - **For User-Specific Access:**

     ```sh
     ln -s ~/bin/neovim/build/bin/nvim ~/.local/bin/nvim
     ```

### Best Practices
- **Permissions Management:** Ensure that your personal directory (`~/bin`) has the appropriate permissions to avoid unauthorized access.
- **PATH Configuration:** Make sure that `~/.local/bin` is included in your PATH. This is typically done by adding the following line to your shell configuration file (e.g., `.bashrc`, `.zshrc`):

  ```sh
  export PATH="$HOME/.local/bin:$PATH"
  ```

- **Version Management:** If you need to manage multiple versions of the same software, use versioned directories and symlinks to switch between them easily.

### Conclusion
Compiling software in `~/bin` and creating symlinks in `/usr/bin` or `~/.local/bin` is a well-regarded practice among expert users. It provides a clean, flexible, and safe way to manage custom-compiled binaries without interfering with system directories or package-managed files. This method enhances maintainability and minimizes the risk of conflicts.


### Installing `.deb` packages on debian-based systems with `dpkg -i`
To install a `.deb` package on a Linux system, you'll typically use the `dpkg` command. Here’s a step-by-step guide:

1. **Open a Terminal:** You can usually open the terminal from your applications menu or by pressing `Ctrl + Alt + T`.

2. **Navigate to the Directory Containing the `.deb` File:** Use the `cd` command to change to the directory where your `.deb` file is located. For example, if it's in your `Downloads` folder, you would type:
   ```bash
   cd ~/Downloads
   ```

3. **Install the Package with `dpkg`:** Use the `dpkg -i` command followed by the package name to install it. Replace `package_name.deb` with the actual name of your file:
   ```bash
   sudo dpkg -i package_name.deb
   ```
   You need to use `sudo` to gain the necessary permissions to install software.

4. **Resolve Dependencies:** Sometimes, a `.deb` file might require other packages that are not currently installed on your system. If `dpkg` reports missing dependencies, you can ask the package manager to fix these issues by running:
   ```bash
   sudo apt-get install -f
   ```
   This command will install any missing dependencies and complete the setup of your `.deb` package.

These steps should help you install most `.deb` files on your Linux system. If you encounter specific errors during the installation, they usually provide hints on what's wrong and how to fix it.