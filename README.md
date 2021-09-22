# Boilerplate Setup for OpenMP parallel programming with WSL/WSL2 Ubuntu and Visual Studio Code
This boilerplate code provides the installation instructions and tasks.json configuration in VSC for OpenMP programming.

## Install on Ubuntu / Windows 10 + WSL/WSL2
```
$ sudo apt install -y g++
$ sudo apt install -y build-essential
$ sudo apt install libomp-dev
$ sudo apt install libboost-all-dev
```

## C/C++ support for Visual Studio Code is provided by a Microsoft C/C++ extension to enable cross-platform C and C++ development on Windows, Linux, and macOS.
## Install the extension
1. Open VS Code.
2. Select the Extensions view icon on the Activity bar or use the keyboard shortcut (Ctrl+Shift+X).
3. Search for 'C++'.
4. Select Install.

## Build the program
1. Select the Terminal > Run Task... command from the main menu.
2. Choose "Builder for OpenMP programs" (label in tasks.json)