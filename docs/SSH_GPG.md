# Introduction

SSH is a protocol that used to connect to servers. GPG (gnu privacy guard) is an
open source implementation of PGP.

## SSH

### Key generation

In order to provide a public key, each user in your system must generate one.
You should check to make sure you don’t already have a key.
By default, a user’s SSH keys are stored in that user’s ~/.ssh directory.

```shell
cd $HOME/.ssh
ls
``` 

You’re looking for a pair of files named something like 
id_dsa or id_rsa and a matching file with a .pub
extension. The .pub file is your public key, and the other file is your private key.
If you don't have these, go to the $HOME dir and:

```shell
ssh-keygen
```

It will ask you for a location with a name. You choose $(HOME)/.ssh/id_rsa. Click return 2 times.

```shell
$ ls
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

## Multiple SSH keys for different servers

You have 3 accounts in 3 hosting services. You need a key for each of those.

```shell
ssh-keygen
```

You can use the -t option to specify the type of key to create.

```shell
ssh-keygen -t rsa
```

You can use the -t option to specify the type of key to create.

```shell
ssh-keygen -b 2048 -t rsa
```

## GPG
