<div align="center">

# 🌲 Binary Search Tree (BST) in C

**A complete implementation of a Binary Search Tree with level-order display**

![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)
![Module](https://img.shields.io/badge/Module-Algorithmique%20%26%20Complexité-6366f1?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-22c55e?style=for-the-badge)

> 🎓 **Final Project** — Algorithmique et Complexité | Abdelli Abdelmoumen | Group 03

</div>

---

## 📌 Overview

This project is a full implementation of a **Binary Search Tree (BST)** in the C programming language, built as the final project for the *Algorithmique et Complexité* module.

It supports all core BST operations through an interactive menu, including insertion, search, deletion, and level-by-level display using a **circular queue**.

---

## ✨ Features

| Feature | Description |
|--------|-------------|
| ➕ **Insert** | Add a new value while maintaining BST properties |
| 🔍 **Search** | Recursively find a value in the tree |
| ❌ **Delete** | Remove a node handling all 3 cases (leaf, one child, two children) |
| 📊 **Level Display** | Print the tree level by level using a queue (BFS) |
| 🔺 **Maximum** | Find the largest value in the tree |
| 🔻 **Minimum** | Find the smallest value in the tree |

---

## 🧠 Data Structures

### 🌿 Tree Node
```c
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;
```

### 📦 Circular Queue (for level-order traversal)
```c
typedef struct Queue {
    node* data;
    struct Queue* next;
} Queue;
```
> The queue is used to perform a **Breadth-First Search (BFS)** to display the tree level by level.

---

## ⚙️ Core Functions

| Function | Description |
|----------|-------------|
| `createnode(int v)` | Allocates and initializes a new tree node |
| `insertnode(node** root, int val)` | Inserts a value iteratively |
| `searchnode(node* root, int v)` | Searches for a value recursively |
| `deleteNode(node* racine, int v)` | Deletes a node (handles 3 cases) |
| `printByLevel(node* racine)` | Displays tree level by level (BFS) |
| `minimum(node* racine)` | Returns the node with the smallest value |
| `maximum(node* racine)` | Returns the node with the largest value |
| `enfiler(Queue** file, node* v)` | Enqueues a node into the circular queue |
| `defiler(Queue** file)` | Dequeues a node from the circular queue |

---

## 🗑️ Deletion Cases

The `deleteNode` function handles all three standard BST deletion cases:

```
Case 1 — Leaf node (no children):
  → Simply free the node and set it to NULL

Case 2 — One child (left or right):
  → Link the parent directly to the existing child, then free the node

Case 3 — Two children:
  → Replace the node's value with the in-order successor (minimum of right subtree)
  → Recursively delete the in-order successor
```

---

## 🖥️ Interactive Menu

When you run the program, you get a simple CLI menu:

```
--- Menu Principal ---
1. Inserer une valeur
2. Afficher l'arbre par niveau
3. Rechercher une valeur
4. Supprimer une valeur
5. Quitter
```

---

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Any Linux/Windows/macOS terminal

### Compile & Run

```bash
# Compile
gcc -o bst main.c

# Run
./bst
```

### Example Session

```
--- Menu Principal ---
Entrez votre choix: 1
Entrez la valeur a inserer: 50
Valeur 50 inseree.

Entrez votre choix: 1
Entrez la valeur a inserer: 30
Valeur 30 inseree.

Entrez votre choix: 2
L'arbre par niveau:
50
30
```

---

## 🗂️ Project Structure

```
bst-project/
│
├── 📄 main.c        # Full source code
└── 📄 README.md
```

---

## 📚 Concepts Covered

- ✅ Dynamic memory allocation (`malloc`, `free`)
- ✅ Recursive algorithms (search, delete)
- ✅ Iterative insertion
- ✅ Pointer manipulation and linked structures
- ✅ Breadth-First Search (BFS) using a circular queue
- ✅ Binary Search Tree properties and invariants

---

## 👨‍💻 Author

**Abdelli Abdelmoumen** — Group 03
🎓 Final Project for *Algorithmique et Complexité*

---

<div align="center">

⭐ **Leave a star if this helped you!** ⭐

</div>
