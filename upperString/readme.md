```markdown
# Text Case Converter (C)

A versatile C-based CLI tool designed to read text files and perform case transformations. It allows users to toggle between uppercase and lowercase output or simply stream the file content to the console, featuring robust argument parsing and error handling.

## 🛠️ Features

* **Flexible Conversion:** Supports converting text to full uppercase or lowercase via command-line flags.
* **Stream Mode:** Can be used as a simple file reader (displaying content without changes) if no conversion option is selected.
* **Advanced Argument Parsing:** Validates both filenames and conversion flags (`L/l` for lower, `U/u` for upper).
* **Comprehensive Error Handling:**
    - Detects missing or invalid arguments.
    - Manages file access errors (not found, permission denied).
    - Identifies empty files and invalid conversion options.
* **POSIX Compliant:** Built to run efficiently on Unix-like systems.



## 🚀 Usage

### Basic Syntax
```bash
./program --filename <filename> [--option L/l | U/u]

```

### Options

* `--filename` : Specify the input file (required).
* `--option`   : Conversion type (optional):
* `L` or `l` : Convert to **lowercase**.
* `U` or `u` : Convert to **UPPERCASE**.



### Examples

1. **Display content as is:**
```bash
./converter --filename example.txt

```


2. **Convert to UPPERCASE:**
```bash
./converter --filename example.txt --option U

```


3. **Convert to lowercase:**
```bash
./converter --filename example.txt --option l

```



## 💻 Requirements

* **OS:** POSIX-compatible system (Linux, macOS, WSL).
* **Compiler:** GCC or Clang (C99 or higher).
* **Standard Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `fcntl.h`, `string.h`, `ctype.h`.

## 🧠 Technical Specifications & Limitations

* **Memory Management:** Uses a 1024-byte buffer (1023 + null terminator) for efficient stream processing.
* **Character Set:** Optimized for **ASCII** characters.
* **Non-Destructive:** The program only outputs to the console (`stdout`); it does **not** modify the original source file.
* **Exit Codes:** Returns `0` on success and `1` for execution errors (with details sent to `stderr`).

## 📄 License

Distributed under the **MIT License**. Free for use and modification.

---

**Author:** Duarte Lacerda

**Version:** 1.0
