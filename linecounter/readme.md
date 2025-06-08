File Line Counter and Converter
==============================

Description:
------------
This program reads a text file specified by the user, counts the number of lines, displays each line with its line number, and saves the numbered content to an output file named 'output.txt'. The program includes robust error handling for file operations.

Features:
---------
- Reads input file specified via command line argument
- Counts and displays total number of lines
- Prints each line prefixed with its line number
- Saves numbered content to output.txt
- Comprehensive error handling for:
  - Missing or invalid arguments
  - File opening/reading errors
  - File writing/closing errors
- Preserves original line breaks in output
- Limits maximum line count (256 lines)

Usage:
------
Command syntax:
  ./program --file <filename>

Example:
  ./linecounter --file example.txt

Sample output:
Line 1: This is the first line
Line 2: This is the second line
...
Total number of lines: 42

Converted content saved to 'output.txt'

Requirements:
-------------
- POSIX-compatible operating system
- C compiler (C99 or later)
- Standard libraries: stdio.h, stdlib.h, unistd.h, fcntl.h, string.h

Limitations:
------------
- Maximum buffer size: 1023 bytes per read operation
- Maximum line count: 256 lines
- Output filename is fixed as 'output.txt'
- Input file must be text format

Author:
-------
Duarte Lacerda

Version:
--------
1.0

License:
--------
MIT License - free for use and modification

---

Notes:
1. The program preserves original line endings in the output
2. Error messages are displayed on stderr
3. Return codes:
   - 0: Success
   - 1: Error occurred
4. The input file remains unchanged
5. Existing output.txt will be overwritten