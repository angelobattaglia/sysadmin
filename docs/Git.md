# Git

```
to add : https://stackoverflow.com/questions/37937984/git-refusing-to-merge-unrelated-histories-on-rebase
TODOs: Git worktree, git bare repository, git submodules
```

### git basic configuration
When you install git for the first time on the new machine. Set the default command line editor as vim.

```shell
    git config --global core.editor vim
    git config --global user.name "John Doe"
    git config --global user.email "john@doe.net"
    git config --global color.ui "auto"
``` 

To list all of the configs:

```shell
    git config --list
``` 

### git starter
To start a new git project on github:

```shell
    git init
    add .gitignore # for the files you don't want to commit
    git remote add 'name of the remote' www.github.com/angelobattaglia/progetto
    git remote set-url 'name of the remote' git@github.com:angelobattaglia/progetto.git
    git add -A or git add .
    git commit -a (-m "first commit")
    git push 'name of the remote' master
``` 

If you want remove some file that you added to the .gitignore later:
```shell
    git rm --cached filetoremovefromthecache
``` 

If you want to show all of the graph of commits just type:
```shell
    git log --all --graph --decorate (--oneline)
``` 

Updating local repository from remote. Let's say your local branch is out of date, and you
need to fetch changes from the same branch but from remote. In order to do this, we need to fetch
from remote and then merge our local branch with the remote branch. So a git pull is a shortcut to 
perform a git fetch followed up by a git merge.
```shell
    git pull
``` 

#### Working with Remote
To see how many remote for a git repository:
```shell
    git remote -v
``` 

To add a remote to a git repository with https:
```shell
    git remote add "Remote 1" www.github.com/angelo/progetto
    git remote add "Remote 2" www.gitlab.com/angelo/progetto
``` 

To remove a remote of an already initialized git repository:
```shell
    git remote remove "Remote 1"
    git remote remove "Remote 2"
``` 

Push to remote(s):
```shell
    git push "remote name" "branch name"
    git push all
``` 

#### Branching
Listing branches:

List all the branches of a given project
```shell
    git branch -a
``` 
```shell
    git branch -r   # list remote branches
``` 
```shell
    git branch      # list local branches
``` 

To change from the current branch, for example, to another one use the argument "checkout":
```shell
    git checkout 'branchname'
``` 

Local branches: colored white. Remote branches: colored red "remotes/origin"
If you want to abort all current changes that aren't committed:
```shell
    git reset --hard
``` 
If you just want to restore one file:
```shell
    git checkout filetorestore.txt
``` 
Branch pointed as "HEAD" is the latest committed among all the branches

#### Git Checkout (moving between branches in git)
The easiest way to switch branch on Git is to use the “git checkout”
command and specify the name of the branch you want to switch to. 
If the destination branch does not exist, you have to append the “-b” option, 
otherwise you won’t be able to switch to that branch.

```shell
git checkout <existing_branch>
``` 

#### How to merge
Merging in Git, especially when working with GitHub, is a common task that integrates changes from one branch into another. Here's a comprehensive guide on how to merge changes using Git with GitHub, and subsequently update your local repository to reflect these changes.

##### Merging in GitHub

1. **Open a Pull Request (PR):** A Pull Request in GitHub is essentially a request to merge one branch into another. Navigate to the repository where you're contributing, and click on "Pull Requests" > "New pull request". Choose the base branch that you want to merge into and the compare branch that you want to merge from.

2. **Review the Changes:** Before merging, it's a good practice to review the changes. GitHub provides a diff view that shows the added, modified, or removed lines.

3. **Resolve Conflicts (if any):** If there are any conflicts, GitHub will alert you. You must resolve these conflicts before proceeding. This can often be done directly in the GitHub interface or by checking out the branch locally and resolving the conflicts manually.

4. **Merge the Pull Request:** Once any conflicts are resolved and you're ready to integrate the changes, click the "Merge pull request" button. Optionally, you can add a merge commit message to document the merge.

###### Updating Your Local Repository After Merging

After merging changes on GitHub, you'll want to update your local repository to reflect the merged state of the remote repository.

1. **Switch to the Relevant Branch:** Make sure you're on the branch into which you merged the changes. You can switch branches with the `git checkout` command.
   ```bash
   git checkout main
   ```
   Replace `main` with the name of the branch you merged the changes into.

2. **Fetch the Latest Changes:** Fetch the changes from the remote repository without merging them into your local repository.
   ```bash
   git fetch origin
   ```
   `origin` is the default name for the remote repository. If you've named it differently, replace `origin` with the name you've given.

3. **Merge the Changes:** Now, merge the fetched changes into your local branch.
   ```bash
   git merge origin/main
   ```
   Replace `main` with the name of your branch. This command merges the remote changes into your current branch, synchronizing it with the remote repository.

4. **Push Local Changes (if any):** If you've made any local changes that need to be synchronized with the remote repository, push them using:
   ```bash
   git push origin main
   ```
   Again, replace `main` with the appropriate branch name.

###### Best Practices

- **Regularly Pull Changes:** To minimize merge conflicts, regularly pull changes from the remote repository to your local branches, especially before starting new work.
- **Use Feature Branches:** When working on new features or fixes, create separate branches for each task. This makes managing and merging changes easier.
- **Communicate with Your Team:** If you're working in a team, communicate about branch merges to avoid conflicts and duplicative work.

Merging and updating your repository in Git can initially seem complex, but with practice, it becomes a routine part of managing code changes. By following these steps and best practices, you'll ensure that your project remains current and organized.


If you've merged changes on GitHub and your local repository isn't up to date with those changes, you can update your local repository by pulling the changes from GitHub. This process involves fetching the changes made on the remote and merging them into your local branch. Here's how you can do it:

1. **Open your terminal or command prompt.**

2. **Navigate to your local repository's directory:**
   Use the `cd` command to change directories to your local repository if you're not already there.
   ```bash
   cd /path/to/your/repository
   ```

3. **Switch to the branch you want to update:**
   Ensure you're on the correct branch that you wish to update with the changes from GitHub. Typically, this is the main branch or the branch into which you've merged changes on GitHub.
   ```bash
   git checkout main
   ```
   Replace `main` with the name of the branch you're updating if it's different.

4. **Pull the changes from GitHub:**
   Use the `git pull` command to fetch the changes from the remote repository and merge them into your local branch.
   ```bash
   git pull origin main
   ```
   This command tells Git to fetch the changes from the `main` branch of the remote repository named `origin` and then merge those changes into your current branch. Again, replace `main` with your branch name if it's different.

The `git pull` command is essentially a combination of `git fetch` followed by `git merge`, where Git first fetches the changes from the specified remote branch and then merges those changes into the current branch of your local repository. This updates your local repository to reflect the state of the repository on GitHub.

If you encounter any merge conflicts during this process, Git will alert you and ask you to resolve them. You'll need to manually edit the files with conflicts, choose which changes to keep, and then commit those resolutions before proceeding.

Following these steps ensures that your local repository is synchronized with the changes made on GitHub, keeping your project files up to date.

You can merge one or more branches. In the current branch, run:
```shell
    git merge "branch-one"
    git merge "branch-one" "branch-two"
``` 

###### How to update your local repository after merges made on GitHub

If you've merged changes on GitHub and your local repository isn't up to date with those changes, you can update your local repository by pulling the changes from GitHub. This process involves fetching the changes made on the remote and merging them into your local branch. Here's how you can do it:

1. **Open your terminal or command prompt.**

2. **Navigate to your local repository's directory:**
Use the `cd` command to change directories to your local repository if you're not already there.
```shell
cd /path/to/your/repository
```

3. **Switch to the branch you want to update:**
Ensure you're on the correct branch that you wish to update with the changes from GitHub. Typically, this is the main branch or the branch into which you've merged changes on GitHub.
```shell
git checkout main
```
Replace `main` with the name of the branch you're updating if it's different.

4. **Pull the changes from GitHub:**
Use the `git pull` command to fetch the changes from the remote repository and merge them into your local branch.
```shell
git pull origin main
```
This command tells Git to fetch the changes from the `main` branch of the remote repository named `origin` and then merge those changes into your current branch. Again, replace `main` with your branch name if it's different.

The `git pull` command is essentially a combination of `git fetch` followed by `git merge`, where Git first fetches the changes from the specified remote branch and then merges those changes into the current branch of your local repository. This updates your local repository to reflect the state of the repository on GitHub.

If you encounter any merge conflicts during this process, Git will alert you and ask you to resolve them. You'll need to manually edit the files with conflicts, choose which changes to keep, and then commit those resolutions before proceeding.

Following these steps ensures that your local repository is synchronized with the changes made on GitHub, keeping your project files up to date.

#### How to make a pull request on GitHub
- Find a project you want to contribute to
- Fork it
- Clone it to your local system
- Create a new branch
- Write your changes
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
## Reset and Rebase


To delete a commit with a typo in the commit message on your GitHub project, you can follow these steps:

### Step 1: Identify the Commit
First, determine the hash (SHA-1) of the commit you want to delete. You can use `git log` to see the commit history and identify the offending commit.

```bash
git log
```

### Step 2: Revert to the Previous Commit
If the mistaken commit is the latest one, you can reset your branch to the previous commit. If it's not the latest commit, you can use an interactive rebase to modify your commit history.

#### If the mistaken commit is the latest:
1. Use `git reset` to revert to the previous commit:

```bash
git reset --hard HEAD~1
```

2. Force-push the changes to your remote repository:

```bash
git push origin +HEAD
```

### Step 3: Interactive Rebase (if the commit is not the latest)
If the commit is not the latest one, you can use an interactive rebase to remove or edit the commit.

1. Start an interactive rebase from a point before the mistaken commit:

```bash
git rebase -i HEAD~n
```

Replace `n` with the number of commits back you want to rebase, which should include the mistaken commit.

2. In the interactive rebase editor, you will see a list of commits. Find the line with the mistaken commit message. You can either remove that line to delete the commit or change the word `pick` to `edit` to modify the commit.

3. If you chose to edit the commit, after closing the editor, you can change the commit message:

```bash
git commit --amend
```

4. Continue the rebase process:

```bash
git rebase --continue
```

5. Finally, force-push the changes to your remote repository:

```bash
git push origin +HEAD
```

### Step 4: Verify
Ensure your repository's commit history looks correct:

```bash
git log
```

This should remove the commit with the typo from your project's history on GitHub. Remember, force-pushing changes the commit history and can affect other collaborators' work, so proceed with caution and communicate with your team if necessary.

Sure, let's go over Step 3 in more detail. This step involves using interactive rebase to modify your commit history, which is particularly useful if the mistaken commit is not the latest one.

### Step 3: Interactive Rebase

1. **Start Interactive Rebase:**

   Begin by starting an interactive rebase from a point before the mistaken commit. You need to specify the number of commits back you want to rebase. For example, if you need to go back 3 commits:

   ```bash
   git rebase -i HEAD~3
   ```

   This will open an editor with a list of the last 3 commits.

2. **Modify the Commit List:**

   In the interactive rebase editor, you'll see a list of commits, each preceded by the word `pick`. It will look something like this:

   ```
   pick a1b2c3d Commit message before the mistake
   pick b2c3d4e Mistaken commit explaination
   pick c3d4e5f Commit message after the mistake
   ```

   Find the line with the mistaken commit message. You have two main options here:

   - **Remove the Commit (if you want to delete it):** Simply delete the line with the mistaken commit.

   - **Edit the Commit Message (if you want to correct it):** Change the word `pick` to `edit` on the line with the mistaken commit:

     ```
     pick a1b2c3d Commit message before the mistake
     edit b2c3d4e Mistaken commit explaination
     pick c3d4e5f Commit message after the mistake
     ```

3. **Save and Exit the Editor:**

   Save the changes and exit the editor. The rebase process will pause at the commit you marked for editing.

4. **Edit the Commit:**

   If you chose to edit the commit, you'll now be prompted to amend the commit. Change the commit message:

   ```bash
   git commit --amend
   ```

   This will open an editor where you can correct the commit message. Change "explaination" to "explanation" and save the changes.

5. **Continue the Rebase:**

   After amending the commit, continue the rebase process:

   ```bash
   git rebase --continue
   ```

   If there are more commits to edit or resolve conflicts, Git will guide you through the process. Otherwise, the rebase will complete.

6. **Force Push the Changes:**

   Since you've rewritten the commit history, you need to force-push the changes to your remote repository:

   ```bash
   git push origin +HEAD
   ```

### Summary

In this step, you've used an interactive rebase to either remove or edit a specific commit. This is a powerful way to clean up your commit history, but it should be used carefully, especially when collaborating with others, as it rewrites the commit history.