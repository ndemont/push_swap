# push_swap

## subject

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

## binary

- `push_swap [-cvs] [--dst] [file ...] [arguments ...]`

Receives a list of integer arguments as a pile and generates the instructions used to sort that pile.


- `checker [-cvs] [--src] [file ...] [arguments ...]`

Checks if the list of instructions you’ll generate with the program push_swap is actually sorting the stack properly.

## instructions

**sa**: swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

**sb**: swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

**ss**: sa and sb at the same time.

**pa**: push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

**pb**: push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

**ra**: rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

**rb**: rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

**rs**: ra and rb at the same time.

**rra**: reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.

**rrb**: reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

**rrs**: rra and rrb at the same time.

## bonus

**command**
- `ruby -e "puts (a..b).to_a.shuffle.join(' ')"` - generates a set of integers between a and b in a random order.

**flags**
- `-v` visual - displays the piles at each state. (can only be used with --dst for push_swap)
- `-c` color - displays in colors.
- `-s` sticks - displays the piles with sticks. (can only be used with `-v`)
- `--dst file` destination - saves the instructions in the precised file. (option for push_swap)
- `--src file` source - reads the instructions from the precised file. (option for checker) 

**tester**
- `tester.sh` - tests the number of operations and displays an error according to the limits of your choice.

## allowed functions

- `write`
- `read`
- `malloc`
- `free`
- `exit`
