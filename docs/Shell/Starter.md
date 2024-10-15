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
