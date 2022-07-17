# SummerProject

## Git Practice
We are going to use git for version control of this project. One of the benefits of git is the ability to branch, so everybody can work on their own copies of the code. The idea is that everybody works on their own copies of the code, and test it, and if the code works, we'll then merge it into the main branch via pull request and code review. Git works best with a command-line interface (terminal, command prompt, git bash, etc.) Here are some basic commands
###### General
```git clone <git url> # Clones the repository onto your local machine ```

```git status # Outputs your current git branch, changed files, and if your branch is up to date```

```git branch -a # Lists all local and remote branches```

###### Pushing
```git add -A # Add all changed files to the git commit ```
``` git commit -m "Message" # The change/addition you are adding to the code base. Make commit messages specific as possible addressing what problems you are solving and how you solved them ```
``` git push # Pushes your local branch to the remote repository branch ```
###### Branches/Pulling
```git checkout <branch_name> # Switch code to this branch```
```git checkout -b <new_branch> <original_branch> # Creates new branch identical to original branch```
```git pull # Pulls remote branch updates into your current branch ```
###### Merging/Rebasing (We will hash this out later)
1. Given: You made a feature branch and you want to merge into main
2. Checkout master branch and perform git pull to make sure it is up to date
3. Checkout feature branch and perform git pull to make sure it is up to date
4. Ensure your feature branch still works
``` git rebase main ```
5. Follow the instructions and fix all the merge conflicts (be very careful and make sure your stuff still works by the end of the rebase
6. Open pull request for merging feature branch into main branch and have at least 1 other person review your code before accepting the merge
