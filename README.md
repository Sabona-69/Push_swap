# Push Swap - 42 Project

## Table of Contents
- [Introduction](#introduction)
- [Mandatory Part](#mandatory-part)
  - [Overview](#overview)
  - [Algorithm](#algorithm)
  - [Compilation and Execution](#compilation-and-execution)
- [Bonus Part](#bonus-part)
  - [Overview](#bonus-overview)
  - [Algorithm](#bonus-algorithm)
- [Resources](#resources)
- [Author](#author)

## Introduction
The **Push Swap** project involves sorting a stack of integers using a limited set of operations and a second stack. The goal is to create a sorting algorithm with the least number of operations. This project tests your understanding of algorithms, data structures, and the ability to manage complexity in a constrained environment.

## Mandatory Part

### Overview
In the mandatory part of the project, you need to implement a sorting algorithm that sorts a stack of integers with a minimal number of operations. The operations you can use are:
- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: Swap the first two elements of both stack A and stack B.
- `pa`: Push the top element from stack B to stack A.
- `pb`: Push the top element from stack A to stack B.
- `ra`: Rotate stack A up by one position.
- `rb`: Rotate stack B up by one position.
- `rr`: Rotate both stack A and stack B up by one position.
- `rra`: Reverse rotate stack A down by one position.
- `rrb`: Reverse rotate stack B down by one position.
- `rrr`: Reverse rotate both stack A and stack B down by one position.

### Algorithm
The main goal is to sort the numbers in stack A with the fewest operations possible. You will need to implement an efficient algorithm such as quicksort, mergesort, or a custom sorting algorithm suitable for this task.

### Compilation and Execution
To compile the project, use the following command:

```bash
make
```

To run the program, execute:

```bash
./push_swap [list_of_numbers]
```

Example:

```bash
./push_swap 3 1 2 4
```

This command will output the sequence of operations needed to sort the stack.

## Bonus Part

### Bonus Overview
The bonus part of the project requires you to implement a checker program that verifies if the output of your sorting algorithm correctly sorts the stack. The checker program should read a sequence of operations and verify if the final state of stack A is sorted.

### Algorithm
You need to create a checker program that:
- Reads the sequence of operations from the standard input.
- Executes these operations on a copy of the initial stack.
- Verifies if stack A is sorted in ascending order and stack B is empty at the end.

## Resources
- [Push Swap - 42 Project Subject](https://projects.intra.42.fr/projects/push_swap)
- [Stack Data Structure - Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Push Swap Checker - GitHub Repository](https://github.com/42Paris/push_swap_checker)

## Author
**hel-omra**  
[42 Intra Profile](https://profile.intra.42.fr/users/hel-omra)
