# TermSnake

A recreation of the classic Snake game for the terminal

## Building

Cmake is required to build the program.

### Windows

For Windows, a C++ compiler such as Visual Studio's MSVC is also required.

To build on Windows, run the following commands:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

The executable will be in the directory "Release"

### Linux
For linux, the ncurses package is required, as well as make. On debian based systems you can run:

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

From there, just run the commands:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

The executable should be in the build directory

## Newest Additions: 1.0

1. The game exists