# Connecting to a GPU cluster: a walkthrough

Connecting to a GPU cluster to perform calculations is becoming an everyday task we all have to measure ourselves with.
It is important to understand how to "ssh into a remote server" to perform computations, and, in the context of Deep Learning,
we are expected to run the experiments using CUDA or python3, perhaps with the aid of an interface that a jupyter notebook, other
than the terminal.

## The key that we'll use to connect to the server

When we want to connect to a remote supercomputer we are being issued a key. This key is a file with the extension ".pem".
Let's suppose we download, from the website of the cloud provider, this file onto the ~/Downloads directory. We have the
following workflow:

```bash
chmod 600 ~/Downloads/test-key-gpu.pem
```

which does the following:

- **`chmod 600`**: This changes the file permissions for `test-key-gpu.pem`. Specifically, it sets the file to be **readable and writable** by the owner (you) and removes all permissions for anyone else. The numeric mode `600` is broken down as follows:
  - The first digit (`6`) means the owner can **read** and **write** the file (`4 + 2 = 6`).
  - The other two digits (`0 0`) mean that no other users (group or others) have any permissions.

- **`~/Downloads/test-key-gpu.pem`**: This is the path to the private SSH key file (used to authenticate your SSH connection) that you've likely downloaded to access the cloud GPU instance. The `~` represents your home directory, so this file is stored in your `Downloads` folder.
  
(Optional) You can copy the private key to your `.ssh` directory with the following command:

```bash
cp ~/Downloads/test-key-gpu.pem ~/.ssh
```

## Connecting to the remote cluster

The command to do so is: `ssh -i ~/Downloads/test-key-gpu.pem ubuntu@96.76.203.50`

- **`-i ~/Downloads/test-key-gpu.pem`**: This flag specifies the **identity file** (private key) for SSH to use for authentication. In this case, `~/Downloads/test-key-gpu.pem` is the file path to the private key, stored in your `Downloads` folder.
  
- **`ubuntu@96.76.203.50`**:
  - **`ubuntu`**: The username to log into the remote server. It is common for cloud instances running Ubuntu to default to the `ubuntu` user.
  - **`96.76.203.50`**: This is the IP address of the remote server (likely your cloud GPU instance).

### What happens next?

This command connects you to the remote cloud GPU instance using SSH, authenticating with the private key specified, and logs you in as the `ubuntu` user. 

Once connected, the terminal prompt will change, indicating you are now controlling the remote server. At this point, you might want to use `tmux` (for terminal multiplexing) and `nvim` (for code editing). For example, you could split your `tmux` session into three panes—one to monitor GPU usage with `nvidia-smi`, another for system monitoring with `htop`, and a third for running Python.

## Copying Files Between Local Machine and Cloud Instance:

### Copying from Remote to Local:

To copy a file (`foo.py`) from the remote server to your local machine, use:

```bash
scp -i ~/Downloads/test-key-gpu.pem ubuntu@96.76.203.50:~/foo.py .
```

- **`scp`**: This command securely transfers files over SSH.
- **`-i ~/Downloads/test-key-gpu.pem`**: Specifies the identity file (private key) for authentication.
- **`ubuntu@96.76.203.50:~/foo.py`**: The remote user (`ubuntu`), the server (`96.76.203.50`), and the file path (`~/foo.py`) you want to copy from.
- **`.` (dot)**: This specifies the **current directory** on your local machine as the destination.

### Copying from Local to Remote:

To upload a file (`random.txt`) from your local machine to the remote instance:

```bash
scp -i ~/Downloads/test-key-gpu.pem random.txt ubuntu@96.76.203.50:~/
```

This copies the file `random.txt` to the home directory of the `ubuntu` user on the remote instance.

## Checking on the nvidia system:

To verify that CUDA has been installed successfully, run the following command:

```bash
nvcc --version
```

This should display the installed CUDA version. You can also check if the driver is working correctly with:

```bash
nvidia-smi
```

You can also install CUDA samples to verify that everything is working correctly. 
The samples can be found in the CUDA installation directory:

```bash
cd /usr/local/cuda/samples
sudo make
```

## Monitoring Python Processes:

It is important to monitor python processes in the remote machine.
To check for running Python processes on the remote server, you can use:

```bash
ps ax | grep python3
```

This will show any running instances of `python3`. To terminate a process, use:

```bash
kill -9 <process_id>
```

Replace `<process_id>` with the actual ID of the Python process you want to kill.
Note that <process_id> is discoverable through htop, or some other top-like program.

## Running a Jupyter Notebook on the Cloud:

You can set up a Python virtual environment and run a Jupyter Notebook on your cloud GPU instance:

1. Create a virtual environment:
   ```bash
   python3 -m venv jpr
   ```

2. Install Jupyter and TensorFlow (or PyTorch):
   ```bash
   pip install jupyter
   pip install tensorflow-gpu  # For TensorFlow
   # or
   pip install torch  # For PyTorch
   ```

3. If needed, uninstall packages:
   ```bash
   pip uninstall tensorflow-gpu
   ```

4. Check your CUDA version:
   ```bash
   nvcc --version
   ```

   If your CUDA version is 9.0, you may need to install a specific version of TensorFlow:
   ```bash
   pip install tensorflow-gpu==1.12.0
   ```

5. Run Jupyter Notebook, setting the IP to `0.0.0.0` so it can be accessed over the network:
   ```bash
   jupyter notebook --ip=0.0.0.0
   ```

## Terminating the Instance:

Terminating a cloud instance will result in a complete loss of all data on the instance. This is typically done through the cloud provider’s web interface. However, you should terminate the active SSH connection from your local machine by simply typing:

```bash
exit
```

or by closing the terminal.
