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

## Acknowledgments

- C++ standard I/O and string processing functionalities utilized.

---

**Note:** This project was created focusing on basic file parsing and string manipulation in C++. It may serve as a foundational example for more complex XML parsing applications.
