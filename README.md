# PUSH_SWAP

This project has been created as part of the 42 curriculum by fbenini-.

Push_swap is a project about sorting algorithms and data structures. The goal is to create a program that will sort a list of integers with limited movements and two stacks.

You will have two stacks (data structure) at your disposal, and the following movements to help you sort the numbers:

- sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
- rrr : rra and rrb at the same time

This project was made using the turk sort algorithm, made exclusively to be the most performant and achieve the least number of movements on the push swap problem.

## Installation and Running

- First, clone the repository and cd into it.
- After that run the following commands:

```bash
make all
./push_swap 3 1 2 # Test the program
```

```
▄▄▄▄  █  ▐▌ ▄▄▄ ▐▌    ▄▄▄ ▄   ▄ ▗▞▀▜▌▄▄▄▄  
█   █ ▀▄▄▞▘▀▄▄  ▐▌   ▀▄▄  █ ▄ █ ▝▚▄▟▌█   █ 
█▄▄▄▀      ▄▄▄▀ ▐▛▀▚▖▄▄▄▀ █▄█▄█      █▄▄▄▀ 
█               ▐▌ ▐▌                █     
▀                                    ▀     
                                           
```

## References

[Article by Yutong Deng on Turk Algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

[Algorithms Design in C by IME USP](https://www.ime.usp.br/~pf/algorithms/)
