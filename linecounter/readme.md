```markdown
# File Line Counter and Converter (C)

A practical C-based utility designed to process text files by counting lines and generating a structured output. The program reads a source file, displays its content with line numbers in the terminal, and simultaneously saves the formatted version to a new file.

## 🛠️ Features

* **Line-by-Line Numbering:** Automatically prefixes each line of text with its corresponding line number.
* **Output Generation:** Saves the processed and numbered content directly to `output.txt`.
* **Robust Error Handling:** Comprehensive checks for:
    - Missing or invalid command-line arguments.
    - File access issues (opening/reading).
    - Disk I/O errors (writing/closing).
* **Format Integrity:** Preserves all original line breaks during the conversion process.
* **Stream Monitoring:** Displays a summary of the total line count upon completion.



## 🚀 Usage

### Syntax
```bash
./program --file <filename>

```

### Example

```bash
./linecounter --file example.txt

```

### Sample Output

```text
Line 1: This is the first line
Line 2: This is the second line
...
Total number of lines: 42

Converted content saved to 'output.txt'

```

## 💻 Requirements

* **OS:** POSIX-compatible system (Linux, macOS, WSL).
* **Compiler:** GCC or Clang (C99 or later).
* **Standard Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `fcntl.h`, `string.h`.

## 🧠 Technical Specifications & Limitations

* **Buffer Management:** Uses a 1024-byte buffer (1023 + null terminator) for efficient read operations.
* **Line Capacity:** Designed to handle files up to **256 lines**.
* **File I/O:**
* Input file remains strictly unchanged.
* Output is hardcoded to `output.txt` and will overwrite existing files of the same name.


* **Exit Codes:** Returns `0` for successful execution and `1` for any fatal errors (detailed in `stderr`).

## 📄 License

Distributed under the **MIT License**. Free for use and modification.

---

**Author:** Duarte Lacerda

**Version:** 1.0
