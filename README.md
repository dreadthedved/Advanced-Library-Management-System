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
## 🚀 Algorithmic Excellence

This project leverages a Binary Search Tree (BST) for efficient management of book records, ensuring scalable operations even as the library grows. Book lookup, insertion, and containment checks operate at **O(log n)** time in average cases, while fallback to **O(n)** in worst-case scenarios is handled gracefully by design. Additionally, the system uses **hash mapping (O(1))** for quick indexing of books and an optimized 2D array to track inventory counts with constant-time access.

Together, these components provide a high-performance foundation for real-time library management, ensuring fast execution, low memory overhead, and reliable scalability—hallmarks of algorithmic precision in systems engineering.

---

## 📌 Final Notes

This system is crafted not just as a demonstration of C++ capabilities, but as a model of what a real-world academic or institutional library engine could achieve with algorithmic rigor and efficient system design. Every decision, from data structures to user flow, is driven by the goal of achieving clarity, scalability, and maintainability in complex environments.

---

## 🧪 How to Build and Run

1. Clone the repository or place `program.cpp` in your working directory.

2. Compile the program:
```bash
   g++ program.cpp -o program
```

3. Run the executable:

```bash
   ./program   (Linux/macOS)  
   .\program.exe (Windows Command Prompt or PowerShell)

