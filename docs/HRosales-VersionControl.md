# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ # Project and Portfolio I: Computer Science - Online ]

- **[ Hermelinda Rosales ]**
- **[ October 4, 2026]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ CMD ]: Clear the Screen
- [ CMD ]: Print the "Working Directory"
- [ CMD ]: List files and folders
- [ CMD ]: List files and folders, including invisible files
- [ CMD ]: List all files and folders, in human readable form
- [ CMD ]: Change directory
- [ CMD ]: Change directory, go to root directory
- [ CMD ]: Change directory and go to user home directory
- [ CMD ]: Change directory, go up one folder level
- [ CMD ]: Change directory, go up two folder levels
- [ CMD ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

When I typed `cd` and dragged a folder from Finder into the Terminal window, the full path to that folder was automatically inserted after the command. When I pressed return, my working directory changed to that folder. I confirmed this by typing `pwd`, which showed the new path. This is a quick way to navigate to a folder without typing the full path manually.

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

 - **Local Version Control** – Tracks changes to files on a single computer. Only you can see the history. No collaboration. Example: SimpleCVS.
    
- **Centralized Version Control (CVCS)** – All developers connect to a single central server that holds the full history. If the server goes down, everyone is blocked. Example: SVN, CVS.
    
- **Distributed Version Control (DVCS)** – Every developer has a complete copy of the repository, including full history. You can work offline and push/pull when connected. Example: Git, Mercurial, Bazaar.

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ CMD ]: Clone a repository
- [ CMD ]: Set-up a global user name
- [ CMD ]: Set-up a global email address (to match my GitHub account email)
- [ CMD ]: Shows the current state of your directory and staging area
- [ CMD ]: Add modified files to the next commit
- [ CMD ]: Make a commit with a new message
- [ CMD ]: Show my commit history
- [ CMD ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

1. I go to my repository on GitHub and copy the HTTPS clone URL (e.g., `https://github.com/username/repo.git`).
    
2. In Terminal, I type `git clone https://github.com/username/repo.git` to make a local copy.
    
3. When I push changes with `git push`, Terminal prompts me for my GitHub username and password (or Personal Access Token).
    
4. After authenticating, I can push and pull from that repository using HTTPS without needing SSH keys.]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
 The `.gitignore` file tells Git which files and folders to skip when tracking changes. Anything listed in it will not be added to the repository, keeping the repo clean and focused on actual project code.

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  `.DS_Store` is a hidden file that macOS creates in every folder to store custom view settings like icon positions and window size. It's not part of your project code, it changes constantly, and it causes unnecessary clutter in your commit history.

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  - I would add the `x64/` and `Debug/` folders (or `Release/`) because they contain Visual Studio build output — compiled binaries, intermediate files, and debug symbols. These files are large, change every time you build, and can be regenerated at any time, so they don't belong in version control. I'd also add `*.sdf`, `*.user`, and `.vs/` for the same reason.
<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

The Git documentation site and the GitHub documentation were the most helpful this week because they provided clear, concise command references that I could test directly in Terminal. The "Folder Drop" tip from the course materials was also useful as a practical shortcut I hadn't tried before

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)
