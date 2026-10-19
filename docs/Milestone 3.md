***Features Added***
- Robust input validation: Replaced the previous cin >> int pattern with a read-string-then-convert approach using std::stoi inside a try/catch. Invalid input (letters, empty strings, out-of-range values) no longer corrupts the cin stream or causes undefined behavior.
- Task reassignment guard: Added a check in the assignment logic so that a Task marked as completed can no longer be assigned to an Agent. Previously, the assignment method would overwrite the agent reference regardless of completion state.

***Updates to System Design***
- Centralized state access for save/load prep: Moved scattered state reads/writes (agent list, task list, assignment map) out of main() and into a single access point. This isolates the "source of truth" so that next week's saveToFile() / loadFromFile() functions only need to interact with one location rather than reaching into multiple functions
- GitHub Issues created for Milestones 3 & 4 to track: input validation fix (done), task reassignment bug (done), menu refactor (in progress), save/load feature (planned).

***Refactoring Improvements***
- Input handling extracted from menu loop: The old pattern repeated a while (!cin) / cin.clear() / cin.ignore() block in every menu function. Consolidated the read-validate-convert logic into a single helper (getIntInput) so each menu now calls one line instead of a 5-line validation block. This reduces duplication and makes it easier to change validation behavior in one place.
- Availability flag decoupled from assignment rejection: In the old code, a rejected assignment (e.g., task already completed) would fall through to the same code path that set agent.setAvailable(false). Separated the "accept" and "reject" branches so a rejection leaves the agent's availability flag untouched.
***What I Changed and Why***
- *Why switch to string-then-convert for input*: The old cin >> int left the stream in a fail state on bad input, which cascaded into subsequent reads and made the menu appear "frozen." Reading a std::string first and converting with std::stoi gives a clean error path via exception without touching the stream state.
- *Why the reassignment guard matters*: Without it, a user could assign a completed task to an agent, which would silently mark the agent as busy with work that's already done — corrupting the simulation state and making the availability tracking unreliable.
- *Why centralize state before adding file I/O*: If save/load code needs to read the agent vector, task vector, and assignment map from three different places in main, any future change to how state is stored breaks all three. A single access point means the file format can evolve independently of the menu logic.
***Carried into Milestone 4***
- Save/load: serialize Agents, Tasks, and assignment links to a text file; restore on startup.
- Agent specialty scoring: weight automatic assignment by matching agent specialty to task category.
- Finish menu refactor so all state mutations flow through the centralized access point.
![[HR_milestone3-run.png]]