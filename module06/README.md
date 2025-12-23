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
| # | Objective |
|:---:|:---|
| ex00 | Use `static_cast` to implement a converter between scalar types (`char`, `int`, `float`, `double`). |
| ex01 | Use `reinterpret_cast` to serialize a `Data*` to `uintptr_t`, then deserialize it back to a `Data*`. |
| ex02 | Use `dynamic_cast` to identify the actual derived type from a base-class pointer. |
