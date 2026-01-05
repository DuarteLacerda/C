```markdown
# Special Character Counter & Converter (C)

A specialized C utility designed to parse text files, quantify whitespace structures, and perform character-to-character conversions. This tool is ideal for sanitizing filenames or flattening text structures by replacing spaces, tabs, and newlines with specific delimiters.

## 🛠️ Features

* **Precise Analytics:** Counts spaces, horizontal tabs, and line breaks independently.
* **Content Transformation:** Automates character substitution:
    - Spaces (` `) → Underscores (`_`)
    - Tabs (`\t`) → Hyphens (`-`)
    - Newlines (`\n`) → Spaces (` `)
* **File Generation:** Outputs the converted content to a dedicated `output.txt` file.
* **Size Validation:** Specifically handles files up to 256 lines of 1024 characters each.
* **Safety & Security:** Robust error handling for file access and resource management (open/close operations).



## 🚀 Usage

### Syntax
```bash
./program --file <filename>

```

### Example

```bash
./converter --file document.txt

```

### Typical Output

```text
Total spaces: 120
Total tabs: 15
Total line breaks: 30

Converted content saved to 'output.txt'.

```

## 💻 Requirements

* **OS:** POSIX-compatible (Linux, macOS, WSL).
* **Compiler:** GCC or Clang (C99 or higher).
* **Standard Libraries:** `stdio.h`, `stdlib.h`, `unistd.h`, `fcntl.h`, `string.h`, `ctype.h`.

## 🧠 Implementation Details

* **Non-Destructive:** The original input file remains completely unchanged.
* **Memory Management:** Uses a 1024-byte fixed buffer for read operations to ensure a low memory footprint.
* **Overwrite Logic:** The `output.txt` file is automatically overwritten if it already exists.
* **Exit Codes:** - `0`: Success.
* `1`: Execution error (details sent to `stderr`).



## 📄 License

Distributed under the **MIT License**. Free for use and distribution.

---

**Author:** Duarte Lacerda

**Version:** 1.0
