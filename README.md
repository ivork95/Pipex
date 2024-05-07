# Pipex

## Overview

Pipex is a program implemented in C that mimics the behavior of the shell command `|` (pipe).

## Usage

Clone repository.

Compile with make in root folder.

Run program with four arguments:


- `file1` and `file2`: File names.
- `cmd1` and `cmd2`: Shell commands with their parameters.



### Example

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
should behave like:
```
< infile ls -l | wc -l > outfile
```
