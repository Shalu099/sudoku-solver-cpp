# sudoku-solver-cpp
# Sudoku Solver using Recursion and Backtracking 🧠🧩

This is a simple C++ mini-project that solves a 9x9 Sudoku puzzle using recursion and backtracking. The project demonstrates a classic algorithmic approach to constraint satisfaction problems.

## 🔧 Technologies Used
- Language: C++
- Concepts: Recursion, Backtracking
- Compiler: Any standard C++ compiler (e.g., g++, Visual Studio, Code::Blocks)

## 📌 How It Works
1. The algorithm finds an empty cell.
2. It attempts to fill it with a number from 1 to 9.
3. It checks if the number is safe to place:
   - Not in the same row
   - Not in the same column
   - Not in the same 3x3 box
4. If safe, it places the number and recursively solves the next empty cell.
5. If it hits a dead end, it backtracks and tries another number.

## 💻 Output Example

