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

Stay tuned, this stand up is coming soon...

### Week 4

My final stand up...
