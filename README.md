# Stocks Master Machine Project

This repository contains solutions to this machine project that has to do with array and string manipulation.

---

## Table of Contents
1. [MP1: First Machine Problem](#-mp1-first-machine-problem)
   - [Makefile Commands](#-makefile-commands)
   - [Challenges in MP1](#-challenges-in-mp1)
2. [MP2: Second Machine Problem](#-mp2-second-machine-problem)
   - [Makefile Commands](#-makefile-commands-1)
   - [Challenges in MP2](#-challenges-in-mp2)
3. [MP3: Third Machine Problem](#-mp3-third-machine-problem)
   - [Makefile Commands](#-makefile-commands-2)
   - [Challenges in MP3](#-challenges-in-mp3)
4. [Conventional Commit Types](#-conventional-commit-types)

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
make run       # Run everything
make test      # Test everything
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

#### **C4 - TL;DR**
Calculates simple moving average of different ranges.

#### **C5 - TL;DR**
Use linear and binary search algorithms to search through stock entries.

---

## 📌 MP3: Third Machine Problem

### 🔧 Makefile Commands
```sh
make compile      # Compile everything
make run          # Run everything
make test         # Test everything
make c7           # Compile, run, and test c7
make c8           # Compile, run, and test c8
make compile_bb   # Compile bbtest
make compile_c7   # Only compile c7
make compile_c8   # Only compile c8
make run_c7       # Only run c7
make run_c8       # Only run c8
make test_c7      # Only test c7
make test_c8      # Only test c8
make clean        # Remove compiled files & outputs
```

### 💺 Challenges in MP3

#### **C6 - TL;DR**
Define struct data types to store stock historical data, including OHLC prices and volume to be used in C7 and C8.

#### **C7 - TL;DR**
Processes stock data to calculate moving averages and identify buy/sell signals.

#### **C8 - TL;DR**
Expands on C7 to generate full trading signals based on moving averages.

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