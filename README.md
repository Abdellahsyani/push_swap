# push_swap project

> the project is about creating or implementing an algorithm that can sort a stack in a fewer steps
by using two stacks and a specific operations like:

* allowed operations:
- * sa `(swap a)`: Swap the first 2 elements at the top of stack a.
    - Do nothing if there is only one or no elements.
- * sb `(swap b)`: Swap the first 2 elements at the top of stack b.
    - Do nothing if there is only one or no elements.
- * ss : sa and sb at the same time.
- * pa `(push a)`: Take the first element at the top of b and put it at the top of a.
    - Do nothing if b is empty.
- * pb `(push b)`: Take the first element at the top of a and put it at the top of b.
    - Do nothing if a is empty.
- * ra `(rotate a)`: Shift up all elements of stack a by 1.
    - The first element becomes the last one.
- * rb `(rotate b)`: Shift up all elements of stack b by 1.
    - The first element becomes the last one.
- * rr : ra and rb at the same time.
- * rra `(reverse rotate a)`: Shift down all elements of stack a by 1.
    - The last element becomes the first one.
- * rrb `(reverse rotate b)`: Shift down all elements of stack b by 1.
    - The last element becomes the first one.
- * rrr : rra and rrb at the same time

* V.2 Example
> To illustrate the effect of some of these instructions, let’s sort a random list of integers.
In this example, we’ll consider that both stacks grow from the right.
----------------------------------------------------------------------------------------------------------
- Init a and b:
- 2
- 1
- 3
- 6
- 5
- 8
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec sa:
- 1
- 2
- 3
- 6
- 5
- 8
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec pb pb pb:
- 6 3
- 5 2
- 8 1
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec ra rb (equiv. to rr):
- 5 2
- 8 1
- 6 3
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec rra rrb (equiv. to rrr):
- 6 3
- 5 2
- 8 1
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec sa:
- 5 3
- 6 2
- 8 1
- _ _
- a b
----------------------------------------------------------------------------------------------------------
- Exec pa pa pa:
- 1
- 2
- 3
- 5
- 6
- 8
- _ _
- a b
----------------------------------------------------------------------------------------------------------
