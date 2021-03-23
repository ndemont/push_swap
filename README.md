# push_swap

## subject

This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

## actions

**sa**: swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
**sb**: swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
**ss**: sa and sb at the same time.
**pa**: push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty
**pb**: push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
**ra**: rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
**rb**: rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
**rs**: ra and rb at the same time.
**rra**: reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one
**rrb**: reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
**rrs**: rra and rrb at the same time.

## How-To save our datas

- [ ] struct global avec tout 
- [ ] liste chainees de commandes (termcap)
- [ ] struct par commande 
- [ ] arbre binaire: 1.operation 2.command 3.command arg 4.command return 5.leftchild 6.rightchild
- [ ] le current path (cd)
- [ ] le retour de la derniere commande ($?)

## allowed functions:

- printf
- malloc
- free
- write
- open
- read
- close
- fork 

## Commands builtins:

1) **export** (sans arg) -> "declre -x var" affichage var alpha



## Small MAN for minishell functions 📚
