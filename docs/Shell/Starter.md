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