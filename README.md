# SimpleSearchEngine_CPP

A lightweight, command-line search engine built in C++ using standard libraries. This project scans a folder of plain text files and allows users to perform basic searches using logical operators (`+`, `-`, normal terms) to find documents containing specific keywords.

---

## Features

- **Text Preprocessing**
  - Reads `.txt` files from a folder named `data`.
  - Removes special characters and normalizes all words to lowercase.
  - Builds an inverted index for efficient keyword lookup.

- **Boolean Search Support**
  - `word`: Returns documents that contain the word (default AND behavior).
  - `+word`: Adds documents containing the word to the result set (OR behavior).
  - `-word`: Excludes documents that contain the word (NOT behavior).

- **Case Insensitive**
  - All searches are case-insensitive.

---

## Prerequisites

- C++ compiler (e.g., G++, Clang).
- A folder named `data` in the same directory containing `.txt` files for indexing.

---

## Setup

Clone this repository and compile the code using your preferred C++ compiler.

```bash
git clone https://github.com/maryam-alikhasi/SimpleSearchEngine_CPP.git
cd SimpleSearchEngine_CPP
g++ main.cpp -o search_engine
````

---

## Usage

Place all your text documents in a folder named `data` inside the project directory. Each file should be `.txt`.

Then run the program:

```bash
./search_engine
```

Enter your search query:

```bash
example query:
1
+Leave -me to +dream

```

This means:

* Must contain `to`
* May contain `Leave` , `dream`
* Must not contain `me`

---

## File Structure

* `main.cpp`: The main source file for the search engine.
* `data/`: Folder containing the text files to be indexed and searched.

---

## Language

* C++ 100%

