# MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)

A modular, multi-file C application developed as part of the **PAP521S - Programming in Practice** coursework at the Namibia University of Science and Technology (NUST). 

The system manages municipal operations including employee records, budget calculations, and report generation, featuring file-based data persistence.

---

## PROJECT ARCHITECTURE AND MODULES

Following separate compilation principles, the project is divided into distinct source (`.c`) and header (`.h`) files, each with a single, clear responsibility:

| Module | Files | What it does |
| :--- | :--- | :--- |
| **Main Coordinator** | `main.c` / `main.h` | Acts as the control center: runs the main menu loop and handles program flow. |
| **Employees** | `employees.c` / `employees.h` | Handles adding, listing, and searching employee records, plus saving/loading data via `employees.txt`. |
| **Budget** | `budget.c` / `budget.h` | Computes municipal revenue, expenses, and figures out if there is a surplus or deficit. |
| **Reports** | `reports.c` / `reports.h` | Generates summary reports across different municipal departments. |
| **Utilities** | `utilities.c` / `utilities.h` | Handy helper functions (like pausing the screen so outputs do not fly past too fast). |

---

## PREREQUISITES

To compile and test this project, you need:
* A standard C compiler (such as **GCC** or **Clang**) supporting the C99 standard.
* A terminal (Linux, macOS, or Git Bash / WSL on Windows).

---

## COMPILATION AND EXECUTION INSTRUCTIONS

### Option 1: Separate Compilation (Recommended for Week 9)
Compile each source file independently into object files (`.c` -> `.o`), then link them together into the final executable:

```bash
# 1. Compile each source file separately into object files
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c

# 2. Link all the object files together into the final executable
gcc main.o employees.o budget.o reports.o utilities.o -o MFMS

# 3. Run the application
./MFMS
