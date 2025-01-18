#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    int data;
    int index;
    struct s_list *next;
    struct s_list *prev;
} t_list;

// Function to count the number of elements in a stack
int count_elements(t_list *stack) {
    int count = 0;
    while (stack) {
        count++;
        stack = stack->next;
    }
    return count;
}

// Function to find the smallest node in the stack
t_list *find_min(t_list **stack_a) {
    t_list *temp = *stack_a;
    t_list *min_node = NULL;

    while (temp) {
        if (temp->index == -1 && (min_node == NULL || temp->data < min_node->data)) {
            min_node = temp;
        }
        temp = temp->next;
    }
    return min_node;
}

// Function to index the stack
void index_stack(t_list **stack_a) {
    int index = 0;
    t_list *node;

    while ((node = find_min(stack_a)) != NULL) {
        node->index = index;
        index++;
    }
}

// Function to add an element to the stack (end of stack)
void add_to_stack(t_list **stack, int data) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return;
    new_node->data = data;
    new_node->index = -1;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (!*stack) {
        *stack = new_node;
    } else {
        t_list *temp = *stack;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to push an element to the back of stack_b
void pb(t_list **stack_a, t_list **stack_b) {
    if (*stack_a == NULL)
        return;
    t_list *temp = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a)
        (*stack_a)->prev = NULL;

    temp->next = *stack_b;
    if (*stack_b)
        (*stack_b)->prev = temp;
    *stack_b = temp;
}

// Function to rotate stack_a
void ra(t_list **stack_a) {
    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    t_list *temp = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_a)->prev = NULL;
    temp->next = NULL;

    t_list *last = *stack_a;
    while (last->next)
        last = last->next;

    last->next = temp;
    temp->prev = last;
}

// Function to rotate stack_b
void rb(t_list **stack_b) {
    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    t_list *temp = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_b)->prev = NULL;
    temp->next = NULL;

    t_list *last = *stack_b;
    while (last->next)
        last = last->next;

    last->next = temp;
    temp->prev = last;
}

// Function to push elements back to stack_a from stack_b in the correct order
void push_back_to_stack_a(t_list **stack_a, t_list **stack_b) {
    t_list *temp;
    
    while (*stack_b) {
        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        if (*stack_b)
            (*stack_b)->prev = NULL;

        temp->next = *stack_a;
        if (*stack_a)
            (*stack_a)->prev = temp;
        *stack_a = temp;
    }
}

// Function to sort the stack
void sort_stack(t_list **stack_a, t_list **stack_b) {
    t_list *current;
    int size = count_elements(*stack_a);
    int range_size = size / 3;  // Dividing the elements into 3 ranges (or adjust as needed)
    int lower_range = 0;
    int upper_range = range_size;

    while (*stack_a) {
        current = *stack_a;
        if (current->index >= lower_range && current->index < upper_range) {
            pb(stack_a, stack_b);  // Push the current element to stack_b
            lower_range = upper_range;
            upper_range += range_size;
        } else if (current->index < lower_range) {
            pb(stack_a, stack_b);
            rb(stack_b);  // Rotate stack_b to maintain order
            lower_range = upper_range;
            upper_range += range_size;
        } else {
            ra(stack_a);  // Rotate stack_a to find the next element
        }

        // Ensure we're correctly moving to the next element in stack_a
        if (*stack_a)
            *stack_a = (*stack_a)->next;
    }

    // After sorting, push all elements back to stack_a
    push_back_to_stack_a(stack_a, stack_b);
}

// Function to free the stack
void free_stack(t_list **stack) {
    t_list *temp;
    while (*stack) {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

// Main function
int main(int ac, char **av) {
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int i;

    if (ac < 2) {
        printf("Error\n");
        return 1;
    }

    for (i = 1; i < ac; i++) {
        int num = atoi(av[i]);
        add_to_stack(&stack_a, num);
    }

    index_stack(&stack_a);  // Index the stack to prepare for sorting
    sort_stack(&stack_a, &stack_b);  // Sort the stack

    // Print the final stack_a (sorted)
    t_list *temp = stack_a;
    while (temp) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("\n");

    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}

