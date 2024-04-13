<h1 align="center">
	CPP Module 06
</h1>

*<p align="center">C++ casts</p>*

## Set-up/Compilation:
First, enter any exercise directory with `cd ex<..>`.  
Then use any Makefile command.

#### Makefile Commands:
```C
make        //compile executable (./<exercise name>)
make clean  //delete .o
make fclean //delete .o and executable
make re     //delete .o and executable, then recompile
```

## Overview of exercise objectives:
**ex00**: Use `static cast` to create a converter for 4 scalar types (char, int, float, double).  
The program should display the value of a variable converted to each type.  
**ex01**: Use `reinterpret cast` to serialize Data* to uintptr_t, then to deseralize uintptr_t to Data*.  
**ex02**: Use behavior of `dynamic cast` to identify derived class type from a pointer to the base class.
