Pipex
Project Information
School 1337
Project Overview
The Pipex project consists of both mandatory and bonus parts.
Mandatory Part
The program will be executed as follows:
./pipex file1 cmd1 cmd2 file2
It must take 4 arguments:
file1 and file2 are file names.
cmd1 and cmd2 are shell commands with their parameters.
The program should behave exactly the same as the shell command below:
$> < file1 cmd1 | cmd2 > file2
Examples
Execute the following:
$> ./pipex infile "ls -l" "wc -l" outfile
The behavior should be like:
$> < infile ls -l | wc -l > outfile
Execute the following:
$> ./pipex infile "grep a1" "wc -w" outfile
The behavior should be like:
$> < infile grep a1 | wc -w > outfile
Bonus Part
Handle multiple pipes.
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
Behaves like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
Support "<<" and ">>" when the first parameter is "here_doc".
$> ./pipex here_doc LIMITER cmd cmd1 file
Behaves like:
cmd << LIMITER | cmd1 >> file
How to Use
Clone the repository:
git clone https://github.com/your-username/pipex.git
Compile the program:
make
Execute Pipex:
./pipex file1 cmd1 cmd2 file2
Contributors
Mouad Kimdil
