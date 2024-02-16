![Project Status](https://img.shields.io/badge/Project_Passed-101%-brightgreen)

# Minishell
Welcome to the Minishell project repository! 

This project was an exciting journey into the world of Unix shells, where we had the opportunity to create our very own command-line interpreter, akin to the legendary **bash**. 

Minishell is not just about mimicking the functionality of existing shells; it was a chance for us to delve deep into the inner workings of shells, processes, and file descriptors. 

## Project Objectives:
In this project, our task was to create a fully functional shell that can handle commands, manage processes, and execute various operations commonly found in shells. We learned to parse user input, search for executables, handle environment variables, and implement features like redirections, pipes, and built-in commands.

## Features

### 1. Command Execution
- **Prompt Display**: Minishell displays a customizable prompt to indicate that it's ready to receive commands from the user.
- **Command Execution**: Users can enter commands just like in a regular shell, and Minishell will execute them accordingly.

### 2. Environment Variable Handling
- **Environment Variables**: Minishell supports environment variables, allowing users to set, unset, and expand them within commands.
- **Variable Expansion**: Environment variables prefixed with `$` are expanded to their corresponding values when used in commands.

### 3. Input/Output Redirections
- **Redirections**: Minishell supports input/output redirections (`<`, `>`, `>>`) to manipulate input and output streams of commands.
  - `<`: Redirects input.
  - `>`: Redirects output.
  - `>>`: Redirects output in append mode.
- **Here-Documents**: Minishell supports `<<`, which reads input until a delimiter is encountered. However, it does not update the command history.


### 4. Pipes
Minishell allows users to connect the output of one command to the input of another using pipes (`|`), enabling the creation of pipelines for data processing.

### 5. Built-in Commands
Minishell provides a set of built-in commands that users can execute directly within the shell:
  - `echo`: Display a line of text.
  - `cd`: Change the current working directory.
  - `pwd`: Print the current working directory.
  - `export`: Set an environment variable.
  - `unset`: Unset an environment variable.
  - `env`: Display the current environment variables.
  - `exit`: Exit the shell.

### 6. Signal Handling
Minishell handles signals such as `Ctrl-C` and `Ctrl-D` appropriately in interactive mode, providing a seamless user experience.

### 7. Quote Handling
Minishell handles single and double quotes in command arguments, preventing interpretation of metacharacters within quoted sequences.

### 8. Error Handling
Minishell provides informative error messages and gracefully handles errors such as command not found, permission denied, and more.


## Compile
1. Clone this repository
2. Compile the project:
```make all```
3. Run the program using the below command:
```./minishell```

Now you're ready to explore and interact with our own Minishell!


## Contributors

![Contributors](https://img.shields.io/badge/Contributors-2-blue)

- [Yash Kulkarni](https://github.com/Y2Kgunner)
- [Lara Elkhoury](https://github.com/Larakh88)