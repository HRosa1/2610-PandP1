# Project & Portfolio 1

### Hermelinda Rosales

Hello my name is Hermelinda. I am a student from Texas. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

This week I set up my repo, created my Project board with Issues and Iterations, and planned out my Library System classes. I'm currently working on writing the class skeletons and getting the menu loop started.

Figuring out the file structure for separating headers and source files took longer than expected. I'm addressing it by keeping each class in its own .h/.cpp pair and not overthinking it until the code is actually working.

I got comfortable with adding GitHub items — creating Issues, organizing the board, and using the dev branch. It's a small thing but it's the foundation for everything else this month.

Get the menu loop compiling, implement "Add Book" and "List Books," and make sure I have 4+ meaningful commits before Milestone 1 is due.

### Week 2

For this week I focused on building out the core loan system for Book Track. I implemented the full checkout flow (search book → confirm availability → select member → create Loan with due date → mark book unavailable) and the matching return flow. I added the Loan class with a 14-day due date that handles month and year rollover, plus an `isOverdue` check. I also added input validation across all menu options using `readInt` and `readString` helper functions.

The main obstacle was keeping three separate data stores consistent: the Book's `available` flag, the Member's `loans` vector, and the Loan record itself. During checkout, all three need to update in the correct order or the system falls out of sync (e.g., a book shows as available but the member still has it listed as a loan). I addressed this by handling all state changes within a single menu option block so the updates happen together, and by adding explicit checks (is the book already checked out? does the member actually have this book?) before making any changes.

I've been getting comfortable working with references and pointers in a multi-class project. Using `Book& getBook(int index)` to return a reference so I can modify availability without copying the object, and using `Member* findMember(int id)` to look up a member and then call methods on the result with `->`, were both new patterns for me. I also learned how `cin.clear()` and `cin.ignore()` work together to recover the input stream after bad input, which was the key to making the validation loop actually function.

Before Week 3 I plan to add fine calculation on return (displaying the total owed when an overdue book comes back), add a "View all overdue" option to the main menu so you can see every late loan at a glance, and run through a full test pass of invalid input on every menu option to make sure nothing crashes. After that I'll start thinking about how to persist data to a file so the catalog doesn't reset when the program closes. I also plan on replacing the manual member ID entry with an automatic 5-digit ID generation. I will also be adding suggestions from my peers to make sure I am taking their feedback into consideration.
### Week 3

### Overview

This week I addressed feedback from Milestone 2 and organized my remaining work into GitHub Issues to keep development tracked. I focused on fixing input handling, correcting a Task assignment bug, and starting a refactor of the main menu to prepare the codebase for file-based persistence.

###  Improvements

- Replaced the old `cin >> int` input validation with proper string reading, integer conversion via `std::stoi`, and `try/catch` exception handling. Invalid input no longer corrupts the stream or freezes the menu.
- Fixed a bug where completed Tasks could still be reassigned to an Agent. Added a guard so the assignment method rejects completed tasks before mutating any state.
- Began refactoring the main menu to isolate state access in a single location rather than scattering reads/writes through `main()`. This lays the groundwork for save/load.
- Created four GitHub Issues to track this week's work: input validation (done), task reassignment bug (done), menu refactor (in progress), save/load (planned).

###  Challenges

- **Input handling vs. existing menu:** Changing the validation approach without breaking the menu system that depended on the old `cin >> int` behavior. Solved by reading a `std::string` first, then converting, so the stream never enters a fail state.
- **Availability flag on rejection:** A rejected Task assignment was accidentally falling through to the same code path that set the Agent's `available` flag to `false`. Separated the accept/reject branches so a rejection leaves the flag untouched. Tested both paths with valid and invalid inputs.

###  Accomplishments

- Learned how to use `std::stoi` with `try/catch` as a clean alternative to stream-based validation — no more `cin.clear()` / `cin.ignore()` boilerplate repeated across every menu.
- Improved my approach to state management by recognizing that centralizing access before adding file I/O prevents the save/load code from becoming tightly coupled to the menu logic.
- Started thinking about code in terms of "what will the next feature need" rather than just "what does this feature need."

###  Next Steps

- Add save/load functionality so simulation state (Agents, Tasks, and their assignments) persists to a file and restores on the next run.
- Finish the main menu refactor so all state mutations flow through the centralized access point.
- Improve automatic Agent selection to consider Agent specialties when matching to Tasks.

### Week 4

My final stand up...
