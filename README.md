# Machine Problems (MP) Repository

Goated Monster Machine Project

---

## Table of Contents
1. [MP1: First Machine Problem](#mp1-first-machine-problem)
   - [Makefile Commands](#makefile-commands)
   - [Challenges in MP1](#challenges-in-mp1)
2. [MP2: Second Machine Problem](#mp2-second-machine-problem)
   - [Makefile Commands](#makefile-commands-1)
   - [Challenges in MP2](#challenges-in-mp2)
3. [Conventional Commit Types](#conventional-commit-types)

---

## 📌 MP1: First Machine Problem

### 🔧 Makefile Commands
```sh
make compile   # Compile C2
make run       # Run and I/O redirect C2
```

### 💺 Challenges in MP1

#### **C1 - TL;DR**
Download the stock market data from the web.

#### **C2 - TL;DR**
Use I/O redirection to take input data, format the data, then print output.

---

## 📌 MP2: Second Machine Problem

### 🔧 Makefile Commands
```sh
make compile   # Compile everything
make c3        # Compile C3 only
make c4        # Compile C4 only
make c5        # Compile C5 only
make r3        # Run C3
make r4        # Run C4
make r5        # Run C5
make t3        # Run BBTest for C3
make t4        # Run BBTest for C4
make t5        # Run BBTest for C5
make clean     # Remove compiled files & outputs
```

### 💺 Challenges in MP2

#### **C3 - TL;DR**
Processes stock price data and finds min/max average OHLC values.

---

## 🐟 Conventional Commit Types

| **Type**       | **Purpose** |
|----------------|-------------|
| **`feat`**     | Add a new feature (functions, logic) |
| **`fix`**      | Fix a bug (incorrect output, logic errors) |
| **`refactor`** | Improve code without changing behavior |
| **`perf`**     | Optimize performance (faster loops, better memory usage) |
| **`style`**    | Formatting changes (indentation, comments) |
| **`test`**     | Add or update test cases |
| **`build`**    | Modify Makefile or compilation setup |
| **`docs`**     | Update README, specs, or comments |
| **`chore`**    | Non-code maintenance (renaming files, updating `.gitignore`) |

---