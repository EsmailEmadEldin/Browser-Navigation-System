# 🌐 Browser Navigation System

A **stack-based browser navigation simulator** implemented in C++ using a custom linked-list stack. Simulates real browser back/forward navigation logic by reading URLs and commands from text files.

---

## 📌 About

This project was built as a data structures assignment to demonstrate the practical use of **stacks** and **linked lists** in simulating browser navigation. It reads a list of URLs and a sequence of navigation commands, then processes each command — showing the current page, next page, and previous page at every step.

---

## 🛠️ How It Works

The program uses **three stacks**:

| Stack | Role |
|-------|------|
| `Backward` | Stores previously visited pages (back history) |
| `Forward` | Stores pages to revisit (forward history) |
| `Temp` | Used to reverse URL order during initialization |

### Navigation Logic
- **Backward command** → pushes current page to `Forward`, pops from `Backward`
- **Forward command** → pushes current page to `Backward`, pops from `Forward`
- **Invalid command** → skipped with an error message

---

## 📁 Project Structure

```
Browser-Navigation-System/
│
├── main.cpp        # Main source file with Stack and Node classes
├── URLs.txt        # Input file: 9 URLs + 1 line of space-separated commands
└── README.md       # Project documentation
```

---

## 📄 Input File Format (`URLs.txt`)

The program reads from a file named `URLs.txt` structured as follows:

```
https://www.google.com
https://www.github.com
https://www.stackoverflow.com
https://www.youtube.com
https://www.wikipedia.org
https://www.reddit.com
https://www.medium.com
https://www.linkedin.com
https://www.twitter.com
Backward Forward Backward Backward Forward Forward Backward Forward Forward Backward
```

- **Lines 1–9**: URLs to load into the browser history
- **Line 10**: Space-separated navigation commands (`Backward` / `Forward`)

---

## ▶️ How to Run

### Prerequisites
- A C++ compiler (g++, clang++, MSVC, etc.)
- A `URLs.txt` file in the same directory as the executable

### Compile & Run (Linux / macOS)
```bash
g++ -o browser main.cpp
./browser
```

### Compile & Run (Windows)
```bash
g++ -o browser.exe main.cpp
browser.exe
```

---

## 🖥️ Sample Output

```
Choice:1 [Backward]
 === The current page is : ===
 https://www.github.com
=== The next one is : ===
https://www.google.com
=== The previous one is : ===
https://www.stackoverflow.com
-----------------------------------------------------------------------------------------------
```

---

## 🧠 Concepts Demonstrated

- **Linked List** — custom `Node` class used as the underlying structure for the stack
- **Stack (LIFO)** — implemented from scratch with `push`, `pop`, `isEmpty`, and `Clear`
- **File I/O** — reading URLs and commands from an external `.txt` file
- **String Tokenization** — using `strtok` to parse space-separated commands
- **Browser Navigation Logic** — mirroring real back/forward history behavior

---

## 👤 Author

- [Esmail Emad El-Din](https://github.com/EsmailEmadEldin)
- [Yousef Tarek](https://github.com/yousseftarekk265)
