```markdown
# File Processor with Space Substitution (C)

A C-based file utility designed to automate text sanitization. The program identifies lines containing spaces, replaces them with underscores (`_`), and filters these modified lines into a new output file. It is a practical example of stream processing and file descriptor management in a POSIX environment.

## 🛠️ Features

* **Smart Filtering:** Only lines that actually undergo modification are saved to the output file.
* **Dynamic Naming:** Automatically generates the output filename by appending `.out` to the original name.
* **Content Transformation:** Replaces all standard spaces (` `) with underscores (`_`) while maintaining the rest of the text structure.
* **Live Monitoring:** Displays modified content in the terminal and provides a summary report of changed lines.
* **Robust I/O Management:** Secure handling of file descriptors and detailed error messaging for input/output issues.



## 🚀 Usage

### Execution
Run the program using the following command:
```bash
./processor --file filename.txt

```

### Result

The program will create a new file named `filename.txt.out` containing only the modified lines.

### Terminal Output Example

```text
Modified content:
Text_with_substituted_spaces
Another_modified_line

Total lines modified: 2

```

## 💻 Requirements

* **OS:** POSIX-compatible system (Linux, macOS, WSL).
* **Compiler:** GCC or Clang (C99 compatible).
* **Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `fcntl.h`, `string.h`.

## 🧠 Implementation Details & Constraints

* **Non-Destructive:** The original source file is never altered.
* **Buffer Limit:** Utilizes a 1024-byte buffer (1023 + null terminator). It is not designed for lines exceeding this length.
* **Path Handling:** The generated output filename has a maximum limit of 1023 characters.
* **Substitution Logic:** Currently targets standard spaces; tabs or multiple whitespace types are not treated as substitutes in the current version.
* **Exit Codes:** Returns `0` on success and `1` for fatal I/O errors (details sent to `stderr`).

## 📄 License

Distributed under the **MIT License**. Free for use and modification.

---

**Author:** Duarte Lacerda

**Version:** 1.0
