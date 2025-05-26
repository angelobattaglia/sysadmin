# SSH and GPG

SSH is a protocol that used to connect to servers. GPG (gnu privacy guard) is an
open source implementation of PGP.

## SSH

### Key generation

In order to provide a public key, each user in your system must generate one.
You should check to make sure you don’t already have a key.
By default, a user’s SSH keys are stored in that user’s ~/.ssh directory.
You’re looking for a pair of files named something like
id_dsa or id_rsa and a matching file with a .pub
extension. The .pub file is your public key, and the other file is your private key.
If you don't have these, go to the $HOME dir and:

```sh
cd $HOME/.ssh
ls
ssh-keygen
```

It will ask you for a location with a name. You choose $(HOME)/.ssh/id_rsa. Click return 2 times.

```shell
ls
id_rsa id_rsa.pub
```

So: id_rsa -> private key, id_rsa.pub -> public key. Never ever share the private key.
When on Windows, use git bash. On a UNIX sys do this:

```shell
ssh -T git@github.com
```

Say yes, and then try to download a repo with SSH. If you have problems:

- [Testing your SSH connection](https://docs.github.com/en/github/authenticating-to-github/testing-your-ssh-connection)

- [Generating Multiple keys for different remote servers to connect to](https://docs.gitlab.com/ee/ssh/)

### Multiple SSH keys for different servers

You have 3 accounts in 3 hosting services. You need a key for each of those. This Method works
also for n accounts. This guide is being taylored for Windows-based operating systems.

#### Powershell as Admin

In Windows PowerShell (run as admin):

- Check the current status of **ssh-agent**:

```shell
   Get-Service | ?{$_.Name -like '*ssh-agent*'} | select -Property Name, StartType, Status
```

- Enable the Service if it is disabled:

```shell
   Set-Service -Name ssh-agent -StartupType Manual
```

- Start the Service:

```shell
   Start-Service ssh-agent
```

- Add your key as before:

```shell
   ssh-add <path to the key>
```

#### Create SSH keys for all accounts

First make sure your current directory is your **.ssh** folder.

```sh
    cd ~/.ssh
```

Syntax for generating unique ssh key for ann account is:

```sh
     ssh-keygen -t rsa -C "your-email-address" -f "github-username"
```

here,

**-C** stands for comment to help identify your ssh key

**-f** stands for the file name where your ssh key get saved

#### Now generating SSH keys for my two accounts

```sh
     ssh-keygen -t rsa -C "first_email@gmail.com" -f "github-first-account"
     ssh-keygen -t rsa -C "second_email@gmail.com" -f "github-second-personal"
```

Notice here **first-account** and **second-account** are the username of my github accounts corresponding to **first-account<span></span>@gmail.com** and **second-account<span></span>@gmail.com** email ids respectively.

After entering the command the terminal will ask for passphrase, leave it empty and proceed.

#### Add SSH keys to SSH Agent

Now we have the keys but it cannot be used until we add them to the SSH Agent. Note:
the "-k" flag is lowercase on Windows and uppercase on UNIX shells (As it worked for me).

```shell
     ssh-add -k ~/.ssh/github-first-account
     ssh-add -k ~/.ssh/github-second-account
```

You can read more about adding keys to SSH Agent [here.](https://help.github.com/en/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

#### Add SSH public key to the Github

For the next step we need to add our public key (that we have generated in our previous step) and add it to corresponding github accounts.

For doing this we need to:

- Copy the public key to the clipboard

We can copy the public key by opening the github-rahul-office.pub file in nvim and then copying the content of it.

```sh
     nvim ~/.ssh/github-first-account.pub
     nvim ~/.ssh/github-second-account.pub
```

And then, paste the public key on Github.

1. Sign in to Github Account

2. Go to **Settings** > **SSH and GPG keys** > **New SSH Key**

3. Paste your copied public key and give it a Title of your choice.

#### Create a Config File and Make Host Entries

The **~/.ssh/config** file allows us specify many config options for SSH.

If **config** file not already exists then create one (make sure you are in **~/.ssh** directory)

```sh
     touch config
```

The commands below opens config in your default editor....Likely TextEdit, VS Code.

```shell
     open config
```

Now we need to add these lines to the file, each block corresponding to each account we created earlier.

```config
     #first-account
     Host github.com-first-account
          HostName github.com
          User git
          IdentityFile ~/.ssh/github-first-account

     #second-account
     Host github.com-second-account
          HostName github.com
          User git
          IdentityFile ~/.ssh/github-second-account
```

#### Handling Git

From now on, to ensure that our commits and pushes from each repository on the system uses the correct GitHub user — we will have to configure **user.email** and **user.name** in every repository freshly cloned or existing before.

To do this use the following commands.

```git
     git config user.email "first-account@gmail.com"
     git config user.name "first-account Name"
     
     git config user.email "second-account@gmail.com"
     git config user.name "second-account Name"
```

Pick the correct pair for your repository accordingly.

To push or pull to the correct account we need to add the remote origin to the project

```git
     git remote add origin git@github.com-first-account:first-account
     
     git remote add origin git@github.com-second-account:second-account
```

Now you can use:

```git
     git push
     
     git pull
```

##### References

- [(1)](https://gist.github.com/rahularity/86da20fe3858e6b311de068201d279e3)
- [(2)](https://unix.stackexchange.com/questions/464574/ssh-add-returns-with-error-connecting-to-agent-no-such-file-or-directory/475853#475853)
- [(3) [SSH tunnels]](https://robotmoon.com/ssh-tunnels/)

## GPG (GNU privacy guard)

First off, we need to generate a key pair. A key pair is composed by a private key and a
public key.

```shell
gpg --full-gen-key
```

It will generate a file, usually, in the $(HOME)/.gnupg directory.
