> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
Book Track
  
**What does your program currently do? (1–3 sentences)**   
A text-based library management system where users can add books to a catalog, search by title or author, register members, check books out, return them, and view a member's current loans with overdue status.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
Main menu loop, add/display/search/remove books, register members, checkout and return flow with availability tracking, input validation (readInt/readString), and overdue detection via the Loan class.
  
**What is NOT working or incomplete?**   
Random member ID generation (still asking user to input an ID), fine calculation display on return, and a "view all overdue" option from the main menu.
  
**What feels confusing or messy in your code?**   
Keeping Book availability, Member loan list, and Loan records in sync during checkout/return — it's spread across three classes and easy to forget one update.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
Random Member ID Generation
  
**What does this feature do?**   
When registering a new member, the program automatically assigns a unique 5-digit ID instead of asking the user to enter one.
  
**Why is this feature important?**   
Removes a source of user error (duplicate or invalid IDs) and makes registration faster.
  
---
### Feature 2  
**Name:**   
Fine Calculation on Return  
  
**What does this feature do?**   
When a book is returned and it's past the due date, the program calculates and displays the fine (e.g., $0.50/day overdue).  
  
**Why is this feature important?**   
Completes the loan lifecycle — currently overdue is detected but no monetary consequence is shown.
  
---
  
### Feature 3 (optional)  
**Name:**   
View All Overdue Items   
  
**What does this feature do?**   
A new main menu option that iterates through all members and displays every overdue loan across the entire system.
  
**Why is this feature important?**   
Gives the "librarian" a quick way to see who owes what without checking each member individually.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
No new classes needed  
  
**Will you modify any existing classes? How?**   
- `Member` — add a `calculateTotalFine(int day, int month, int year)` method

- `Menu` — add `generateId()` helper and a new option 10 for "View all overdue"

- `Catalog` — add a `displayAllOverdue(int day, int month, int year)` method that iterates members  
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
`std::vector<Book>` in Catalog, `std::vector<Member>` in Menu, `std::vector<Loan>` in Member. No new structures needed.   
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   main menu displays
2. User chooses →   option number entered (validated via readInt)
3. Program responds →   performs action, shows confirmation or error
4. Loop/next step →   returns to main menu until user selects 0 (exit)
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
Each prompt now includes context (e.g., "Book number to remove: " instead of just a bare `cin >>`)
  
- Better error handling:   
`readInt` and `readString` re-prompt on invalid/empty input instead of corrupting the stream; "Member not found" and "Invalid book number" messages for checkout/return 
  
- Improved menu/navigation:   
Every option returns cleanly to the main menu with no dead ends; checkout/return give specific feedback for each failure case
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
Keeping all three data stores (Book availability, Member loans, Loan records) consistent during checkout and return without missing an update.
  
**What is your plan if you get stuck?**   
Step through the checkout/return flow with a debugger, trace which class is out of sync, and centralize the state change in one method rather than updating each class separately.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
Debugging with the IDE (setting breakpoints, stepping through, watching variable values).
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
Set breakpoints in `checkOut` and `returnBook`, step through line by line, and watch the `available` flag and `loans` vector change. Practice for at least 2 sessions this week.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Add random 5-digit ID generation for new members
- [ ]   Add fine calculation and display on book return
- [ ]   Add "View all overdue" option to main menu
- [ ]   Test invalid input across all menu options
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.