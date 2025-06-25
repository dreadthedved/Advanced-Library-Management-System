# 📚 Advanced Library Management System (C++)

This Library Management System is a robust, high-performance application built in C++ to efficiently manage book circulation within an academic environment. It combines classical data structures with real-time simulations and persistent logging to deliver a scalable and maintainable solution.

---

## 🚀 Key Highlights

- 🔍 **Fast Lookup with Binary Search Tree (BST)**: Book names are indexed in a BST for log-time retrieval and insertion.
- 🔐 **Role-Based Access Control**: Distinct operational flows for students and librarians with credential validation.
- 📊 **Dynamic Inventory Management**: Tracks total and available copies of each book using hash maps and matrices.
- ⏱️ **Simulated Clock + Fine System**: Accurate time tracking for issue/return operations and automated fine computation.
- 📝 **Persistent Logging**: All transactions are stored in an append-only log file (`library_log.txt`) for audit and recovery.
- ⚙️ **Modular Design**: Separation of concerns via class-based abstractions for `Student`, `BookTree`, and utility functions.

---

## 🛠️ Tech Stack

- **Language**: C++ (OOP + STL)
- **Data Structures**:
  - Binary Search Tree (BST)
  - Unordered Hash Map
  - Fixed-Size Matrix for Book Inventory
- **File Handling**: Standard File I/O for persistent logging
- **Design Paradigm**: Object-Oriented Programming (OOP)

---

## 📂 Project Structure

- `tp2.cpp` - Main application logic
- `library_log.txt` - Auto-generated log of all transactions
- `Student`, `BookTree` - Core classes modeling system behavior

---

## 🧪 How to Build and Run

1. **Clone the Repository** or place `tp2.cpp` in your working directory.

2. **Compile the Program**:

   ```bash
   g++ -std=c++17 -o tp2.exe tp2.cpp
