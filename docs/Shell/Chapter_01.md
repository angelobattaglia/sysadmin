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