# Binary Tree Range Filter

## 📌 Overview

This C++ program demonstrates:

1. **Breadth-First Search (BFS)** traversal to display a binary tree level-by-level.
2. **Range-based pruning** — removing all nodes in the tree whose values fall outside a user-specified range.

It constructs a sample binary tree, displays it, prompts the user for a valid `[minVal, maxVal]` range, prunes nodes outside the range, and displays the updated tree.

---

## 🖥 Features

- **BFS Traversal**: Prints tree nodes level-by-level.
- **Range Filtering**: Removes nodes with values `< minVal` or `> maxVal`.
- **Input Validation**: Ensures numeric input and valid range (`minVal < maxVal`).
- **Dynamic Memory Management**: Frees memory for removed nodes.

---

## 📋 Example Run

**Input:**
Original Tree:
8
5 11
2 7 9 12
6 10 13

Enter the minimum value of the range: 6
Enter the maximum value of the range: 11

**Output:**
Tree after removing nodes outside the range [6, 11]:
8
7 11
6 9 10

---

## ⚙ How It Works

1. **Tree Construction**
   - A sample binary tree is manually created in `main()`.
2. **Display Original Tree**
   - `BFS(root)` prints all nodes level-by-level.
3. **Read User Input**
   - `readValidRange(minVal, maxVal)` ensures a valid range is entered.
4. **Prune Tree**
   - `removeOutsideRange(root, minVal, maxVal)` recursively removes out-of-range nodes.
5. **Display Updated Tree**
   - The pruned tree is printed again using BFS.

---

## 🛠 How to Run

### You can run this code in two ways:
