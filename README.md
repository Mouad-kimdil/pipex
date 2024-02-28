Pipex is a project designed as part of the 1337 School cursus, aiming to develop a program that simulates the behavior of shell commands involving pipes. The project is divided into two main parts: a mandatory section and a bonus section, challenging students to implement fundamental Unix functionalities.

## Table of Contents

- [Project Information](#project-Overview)
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)
- [Examples](#examples)
- [How to Use](#how-to-use)
- [Contributors](#contributors)

## Project Overview

The primary objective of Pipex is to create a program that mimics the behavior of the following shell command:
@@ -13,6 +22,8 @@ $> < file1 cmd1 | cmd2 > file2

This command takes four arguments: **file1** and **file2** as file names, and **cmd1** and **cmd2** as shell commands along with their parameters. The program is expected to replicate the functionality of the provided shell command.

## examples

### Mandatory Part

In the mandatory part, the focus is on understanding and implementing the basic structure of the pipeline. The program must handle the execution of two commands (cmd1 and cmd2) with input from file1 and redirect the output to file2. This core functionality lays the foundation for more advanced features in the bonus section.
@@ -34,3 +45,70 @@ The program is expected to handle multiple commands connected by pipes, providin
```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```

The program should support "<<" and ">>" when the first parameter is "here_doc," simulating the behavior of a shell command with a here document.

### Examples

Here are a couple of examples illustrating the usage and expected behavior of Pipex:

#### mandatory part

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```

The behavior should be equivalent to:

```bash
$> < infile ls -l | wc -l > outfile
```

#### bonus part

##### multipple pipes
```bash
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Should behave like:

```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```

##### here doc

```bash
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Should behave like:

```bash
cmd << LIMITER | cmd1 >> file
```
## how to use
### Clone the repository:
```bash
git clone https://github.com/Mouad-kimdil/pipex.git
```
```bash
cd pipex
```
***Mandatory part***
```bash
make
```
***bonus part***
```bash
make bonus
```
