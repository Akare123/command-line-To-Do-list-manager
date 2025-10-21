# Simple C To-Do List Manager

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A lightweight and fast command-line to-do list manager written entirely in C. This project demonstrates basic file I/O, command-line argument parsing, and standard C library usage.

## Features

- **Add:** Add new tasks to your list.
- **List:** View all your current tasks.
- **Remove:** Delete tasks by their number.
- **Persistent Storage:** Tasks are saved to a local `tasks.txt` file.

## Prerequisites

To compile and run this project, you will need:
- A C compiler (like `gcc`)
- `make` build automation tool

These are standard on most Linux and macOS systems. For Windows, you can use WSL (Windows Subsystem for Linux) or MinGW.

## How to Get Started

Follow these steps to get the project up and running on your local machine.

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git
cd YOUR_REPOSITORY_NAME
```

### 2. Compile the Program

Use the included `Makefile` to compile the source code.

```bash
make
```
This will create an executable file named `todo` in the project directory.

### 3. How to Use

The program is controlled via command-line arguments.

**To list all tasks:**
```bash
./todo list
```

**To add a new task:**
(Use quotes if your task contains spaces)
```bash
./todo add "Buy milk and bread"
```

**To add another task:**
```bash
./todo add "Finish the C project"
```

**To remove a task by its number:**
(This will remove the second task from the list)
```bash
./todo remove 2
```

## File Structure

- `main.c`: The main C source code file containing all the logic.
- `Makefile`: The build script to compile the program.
- `tasks.txt`: A plain text file where your tasks are stored. This file is created automatically when you add your first task.

## Contributing

Contributions are welcome! If you have ideas for new features or improvements, feel free to open an issue or submit a pull request.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
