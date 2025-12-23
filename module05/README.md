<h1 align="center">
	CPP Module 05
</h1>

*<p align="center">Repetition and Exceptions</p>*

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
The 4 exercises focus on the use of `custom exceptions`.  
The implemented classes such as `Bureaucrat`, `Form`, and `Intern` interact with one another.  
The main functions test these interactions across different scenarios.  
For example, a bureaucrat signs/executes a form only if it has the required authorizations.
