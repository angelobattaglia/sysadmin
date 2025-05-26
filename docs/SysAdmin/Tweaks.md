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

## Uninstalling Software
To completely remove a piece of software along with its configuration files in Ubuntu, you can use the `purge` option with the `apt-get` command. This is particularly useful when you want to ensure that all settings are reset if you plan to reinstall the software later. Here’s how you can do it:

1. **Open the Terminal**: You can open the Terminal by pressing `Ctrl+Alt+T` or by searching for it in the dashboard.

2. **Update your package list** (optional but recommended):
   ```bash
   sudo apt update
   ```

3. **Purge the software**: Replace `package_name` with the actual name of the software package you want to remove. You can also list multiple packages separated by spaces.
   ```bash
   sudo apt purge package_name
   ```

4. **Remove dependencies** that are no longer required (optional):
   ```bash
   sudo apt autoremove
   ```

This process will remove the software and its configuration files, as well as any unused dependencies if you run the `autoremove` command. This helps keep your system clean. If you're unsure of the package name, you can search for it using:
```bash
apt search keyword
```
Replace `keyword` with a term related to the software you're trying to find. This will list all packages related to the keyword, helping you pinpoint the exact package name to purge.

## Managing the $PATH environment variable
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


It looks like you've correctly formulated the command to add `/home/angelo/AppImages` to your PATH in the `.zshrc` file for Zsh shell. However, the double quotes are broken into segments which might cause a syntax error. Here’s how to properly format it:

### Correct Syntax

You should ensure the entire `export` command is within a single set of quotes if needed, or better yet, avoid extra quotes around the whole command, like this:

```bash
export PATH=$PATH:/home/angelo/AppImages
```

Here’s how you can make this correction:

1. **Open your `.zshrc` file**:
   Open a terminal and edit the `.zshrc` using a text editor like nano or vim:

   ```bash
   nano ~/.zshrc
   ```

2. **Modify the PATH line**:
   Find the line where you tried to add the directory to the PATH. It might look like your example with broken quotes. Change it to the correct format shown above.

3. **Save and close the editor**:
   - For nano, press `Ctrl + X`, then `Y` to confirm, and `Enter` to save.
   - For vim, press `:wq` and then `Enter`.

4. **Apply the changes**:
   To make sure your current terminal session recognizes the change, source the `.zshrc` file:

   ```bash
   source ~/.zshrc
   ```

5. **Verify the PATH**:
   Check that your directory was added successfully:

   ```bash
   echo $PATH
   ```

This should show the `/home/angelo/AppImages` directory appended to the existing PATH. If you see it there, you've successfully added it to your PATH permanently for all future terminal sessions that use the Zsh shell.



Creating an alias in Unix-like operating systems is a common way to simplify command sequences or customize your shell experience. Aliases are typically set up in your shell’s configuration file, such as `.bashrc` for Bash or `.zshrc` for Zsh. Here’s how to create an alias:

### For Bash

1. **Open your `.bashrc` file**:
   Open a terminal and edit the `.bashrc` using a text editor. For example, you can use `nano`:
   ```bash
   nano ~/.bashrc
   ```

2. **Add the alias**:
   At the end of the file, you can add your alias command. For example, if you want to create an alias called `ll` that runs `ls -l`, you would write:
   ```bash
   alias ll='ls -l'
   ```

3. **Save and close the file**:
   If you’re using `nano`, press `Ctrl + X`, then `Y` to confirm, and `Enter` to save.

4. **Activate the alias**:
   Source your `.bashrc` to make the alias available in your current session:
   ```bash
   source ~/.bashrc
   ```

### For Zsh

1. **Open your `.zshrc` file**:
   Similarly, use a text editor to open your `.zshrc`:
   ```bash
   nano ~/.zshrc
   ```

2. **Add the alias**:
   Add your desired alias to the end of the file. For instance, if you want to simplify the `grep` command to always include color:
   ```bash
   alias grep='grep --color=auto'
   ```

3. **Save and close the file**:
   Save your changes and exit the text editor.

4. **Activate the alias**:
   Source your `.zshrc` file:
   ```bash
   source ~/.zshrc
   ```

### Verification and Use

After setting up your alias and sourcing the respective configuration file, you can verify that the alias is working by simply typing the alias in the terminal:
```bash
ll
```
This should execute the `ls -l` command, showing a detailed listing of files and directories.

### General Tips

- Aliases are only available for interactive shell sessions (not in scripts, unless explicitly sourced).
- You can use aliases to shorten complex commands, add default options to commonly used programs, or correct frequent typos.
- For temporary aliases that only last for the duration of a terminal session, you can type the alias command directly into the terminal without adding it to a `.bashrc` or `.zshrc` file.

By leveraging aliases, you can greatly enhance your productivity and streamline your command line operations.
