# Simple Tag Enumeration Program

## Project Overview

This project involves creating a C++ program that parses a text file containing XML-like tags, extracts tag types, and stores the associated text elements. The main requirements include identifying each element tag, counting tag occurrences, and storing the enclosed text for each tag type.

## Core Requirements

### TagStruct - Named Struct Type

```cpp
struct TagStruct {
    std::string tagName;
    int tagCount;
    std::string concatenatedText;
};
```

For each tag encountered during parsing, the program stores:
- `tagName`: Tag name
- `tagCount`: Number of matching open/close tag pairs in the file
- `concatenatedText`: Concatenated text found between all tags of this type, separated by ":"

### Terminal Input Command Loop

The program provides a terminal input command loop with the following options:

1. ‘r’: Read and parse a specified input file.
2. ‘p’: Print all tags - list all tags in arbitrary order to `cout`.
3. ‘d’: Dump/write tags and data to a file called `tag.txt`.
4. ‘l’: List/print tag data for a given tag to `cout`.
5. ‘q’: Quit - terminate the input loop and exit the program.

### Assumptions

1. All tags match (open/close).
2. No nesting of tags (simple input).
3. Tags are case-sensitive.

### Example Output

For the given input file:

```xml
<TXT>text</TXT>
<TAG1>hello there old tag</TAG1>
<TXT>and more text</TXT>
```

The stored data (in each `TagStruct`) would be:

```cpp
"TXT", 2, "text:and more text"
"TAG1", 1, "hello there old tag"
```

Note: Spaces within the enclosed text are preserved, and leading/trailing spaces can be trimmed if desired.

### Code Snippet

```cpp
#include <iostream>
#include <string>

std::string s1 = "hello", s2 = "world";
if (s1 != s2) std::cout << "These don’t match!\n";
```

## How to Use

1. Clone the repository.
2. Compile the C++ program.
3. Run the executable.
4. Follow the terminal prompts to read, parse, and manipulate tag data.

## About the Program

The tag extraction program utilizes three files: `TagExtraction.h` (header file with function declarations and struct), `TagExtraction.cpp` (source file with function definitions), and `TagExtractionDriver.cpp` (driver source file displaying the menu, obtaining user input, and calling relevant functions from `TagExtraction.cpp`).

## Functions

### 1. `read`

This function takes a vector storing the list of structs (tags and their data) and a filename. It populates the vector list of type `TagStruct` with tags and their data from the file, and then returns the vector to the calling driver file.

### 2. `print`

This function takes a vector storing the list of structs (tags and their data) and iterates through the elements, displaying extracted tag names. It is a void method.

### 3. `dump`

The `dump` function, with parameters similar to `print`, is also a void function. It utilizes an `ofstream` to write/dump all tags in the vector to a file named `tag.txt` as instructed in the assignment.

### 4. `listData`

The `listData` function takes a vector storing the list of structs (tags and their data) and a tag name. It explicitly prints out that specific tag's name and data.

## How to Run the Program

To run the program, type the following command in the terminal:

```bash
make run
```

The makefile should execute the `./TagExtraction.exe` command to run the executable file. After execution, a menu from the program should appear with various options.

---

**Note:** The provided overview serves as a quick reference for the program structure and functionality. For detailed code and implementation, refer to the specific files in the project directory.

## Acknowledgments

- C++ standard I/O and string processing functionalities utilized.

---

**Note:** This project was created focusing on basic file parsing and string manipulation in C++. It may serve as a foundational example for more complex XML parsing applications.
