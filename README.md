# Pipex - 1337 School Project by ![Mouad Kimdil](https://img.shields.io/badge/Mouad-blue)

![School: 1337](https://img.shields.io/badge/School-1337-blue)
## Introduction
Welcome to the "pipex" project, part of the 1337 School curriculum. This project challenges you to create a program that mimics the behavior of shell commands involving pipes. The project is divided into a mandatory part and a bonus part.
## Table of Contents
- [Project Information](#project-information)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Examples](#examples)
- [How to Use](#how-to-use)
- [Contributors](#contributors)

## Project Information

### School
1337

### Project Overview
The Pipex project consists of both mandatory and bonus parts.

## Mandatory Part

The program will be executed as follows:

```bash
./pipex file1 cmd1 cmd2 file2
It must take 4 arguments:
file1 and file2 are file names.
cmd1 and cmd2 are shell commands with their parameters.
The program should behave exactly the same as the shell command below:
```bash
$> < file1 cmd1 | cmd2 > file2

## Bonus Part

- Handle multiple pipes.

```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
Behaves like:
$> ./pipex here_doc LIMITER cmd cmd1 file
Support "<<" and ">>" when the first parameter is "here_doc".
$> ./pipex here_doc LIMITER cmd cmd1 file
Behaves like:
cmd << LIMITER | cmd1 >> file

## Examples

1. Execute the following:

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
The behavior should be like:
$> < infile ls -l | wc -l > outfile
Execute the following:
$> ./pipex infile "grep a1" "wc -w" outfile
The behavior should be like:
$> < infile grep a1 | wc -w > outfile
## How to Use

1. Clone the repository:

```bash
git clone https://github.com/Mouad-kimdil/pipex.git
Compile the program:
make
Execute Pipex:
mandatory part:
./pipex file1 cmd1 cmd2 file2
bonus part:
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
here doc
./pipex here_doc LIMITER cmd cmd1 file

## Contributors

- [Mouad Kimdil](https://github.com/Mouad-kimdil)
