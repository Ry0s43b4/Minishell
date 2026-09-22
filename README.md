# Minishell

A functional UNIX command-line interpreter developed as part of the **Epitech** curriculum, implementing core built-in commands and basic pipeline redirection.

## Project Overview

This project is a recreation of a UNIX shell (like tcsh or bash) aimed at understanding process creation (`fork`), program execution (`execve`), environment variable management, and basic stream manipulation.

The shell executes standard system binaries alongside a selection of custom-built internal commands. It also features an initial implementation of command pipelining, allowing two programs to communicate sequentially.

## Features

### Built-in Commands
The shell natively handles the following built-in commands, developed from scratch:
* `cd` – Change the current working directory.
* `env` – Print the current environment variables.
* `setenv` – Add or modify environment variables.
* `unsetenv` – Remove variables from the environment.

### System Commands
* Executes standard system binaries found in the `PATH` (such as `ls`, `cat`, `echo`, `pwd`, etc.) with correct argument handling.

### Pipeline Support
* Supports single piping via the `|` operator to connect two commands sequentially (e.g., `cmd1 | cmd2`). Multi-stage pipelines (more than two commands in a row) are not currently supported in this version.

## Future Roadmap

This project is subject to future improvements as time permits. Planned enhancements include:
* Full support for standard stream redirections (`>`, `>>`, `<`, `<<`).
* Sequential command execution using the semicolon separator (`;`).
* Multi-stage pipelining to allow an unlimited chain of consecutive commands.

## Getting Started

### Prerequisites

You will need a C compiler (such as `gcc`) and `make` installed on a UNIX-like system (Linux/macOS).

### Installation & Execution

1. Clone the repository:
   ```bash
   git clone https://github.com/Ry0s43b4/Minishell.git
   ```
2. Navigate into the directory:
   ```bash
   cd Minishell
   ```
3. Compile the project using the Makefile:
   ```bash
   make
   ```
4. Launch the shell:
   ```bash
   ./mysh
   ```

## Contributing

Contributions, bug reports, and forks are welcome. Feel free to clone this repository to test the shell, experiment with the code, or help implement the remaining features.

---
Enjoy testing! 🐚
