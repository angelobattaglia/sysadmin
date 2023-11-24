# Git

Add new remotes:

``` 
git remote add gitlab git@gitlab.com:Username/Repo.git
git remote add github git@github.com:Username/Repo.git
``` 

To push over gitlab/github master:

``` 
git push gitlab master
git push github master
``` 

To list all of the remotes for a repository:

``` 
git remote -v 
``` 

Listing branches:

``` 
git branch #To see local branches 
git branch -r #To see  branches 
git branch -a #To see both local and remote branches 
``` 

The easiest way to switch branch on Git is to use the “git checkout”
command and specify the name of the branch you want to switch to. 
If the destination branch does not exist, you have to append the “-b” option, 
otherwise you won’t be able to switch to that branch.

``` 
git checkout <existing_branch>
``` 

Create new branch:

``` 
git checkout -b "<new_branch>"

``` 

```
to add : https://stackoverflow.com/questions/37937984/git-refusing-to-merge-unrelated-histories-on-rebase
TODOs: Git worktree, git bare repository, git submodules
```

### git basic configuration
When you install git for the first time on the new machine. Set the default command line editor as vim.

``` 
    git config --global core.editor vim
    git config --global user.name "John Doe"
    git config --global user.email "john@doe.net"
    git config --global color.ui "auto"
``` 

To list all of the configs:

``` 
    git config --list
``` 

### git starter
To start a new git project on github:

``` 
    git init
    add .gitignore for the files you don't want to commit
    git remote add 'name of the remote' www.github.com/angelobattaglia/progetto
    git remote set-url 'name of the remote' git@github.com:angelobattaglia/progetto.git
    git add -A or git add .
    git commit -a (-m "first commit")
    git push 'name of the remote' master
``` 

If you want remove some file that you added to the .gitignore later:
``` 
    git rm --cached filetoremovefromthecache
``` 

If you want to show all of the graph of commits just type:
``` 
    git log --all --graph --decorate (--oneline)
``` 

Updating local repository from remote. Let's say your local branch is out of date, and you
need to fetch changes from the same branch but from remote. In order to do this, we need to fetch
from remote and then merge our local branch with the remote branch. So a git pull is a shortcut to 
perform a git fetch followed up by a git merge.
``` 
    git pull
``` 

#### Working with Remote
To see how many remote for a git repository:
``` 
git remote -v
``` 

To add a remote to a git repository with https:
``` 
    git remote add "Remote 1" www.github.com/angelo/progetto
    git remote add "Remote 2" www.gitlab.com/angelo/progetto
``` 

In my case:
``` 
    git remote add origin www.github...
``` 
            
Push:
``` 
    git push "remote name" "branch name"
    git push all
``` 

#### Branching
``` 
    git branch 'new-branch-name' 'from-branch'
``` 
To change from the current branch, for example, to another one use the argument "checkout":
``` 
    git checkout 'branchname'
``` 
List all the branches of a given project:
``` 
    git branch -a
``` 
``` 
    git branch -r   # list remote branches
``` 
``` 
    git branch      # list local branches
``` 

Local branches: colored white. Remote branches: colored red "remotes/origin"
If you want to abort all current changes that aren't committed:
``` 
    git reset --hard
``` 
If you just want to restore one file:
``` 
    git checkout filetorestore.txt
``` 
Branch pointed as "HEAD" is the latest committed among all the branches

#### How to merge
You can merge one or more branches. In the current branch, run:
``` 
    git merge "branch-one"
    git merge "branch-one" "branch-two"
``` 

#### How to make a pull request
- Find a project you want to contribute to
- Fork it
- Clone it to your local system
- Make a new branch
- Make your changes
- Push it back to your repo
- Click the Compare & pull request button
- Click Create pull request to open a new pull request

#### Tagging a particular commit

``` 
    git tag "tag name" # Will tag the commit HEAD (the latest) if not specified otherwise
    git tag "hash of the commit" "tag name" # Will tag the specific commit tagged with that hash
``` 

List all the tags:
``` 
    git tag
``` 