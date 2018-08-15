#include <stdlib.h>

#include "Stack_point.h"

void create_stack (stack *ps)
{
	*ps = NULL;
}

int push (stack_type x, stack *ps)
{
	stack_element *temp;

    temp = malloc(sizeof(stack_element));
    if (!temp)
		return 0;
    temp->data = x;
    temp->link = *ps;
    *ps = temp;
    return 1;
}

int pop(stack *ps, stack_type *px)
{
	stack_element *temp;

    if (*ps)
	{
		temp = *ps;
        *ps = temp->link;
		*px = temp->data;
        free (temp);
		return 1;
	}
	return 0;
}

int stack_top (stack *ps, stack_type *px)
{
    if (*ps)
	{
		*px = (*ps)->data;
		return 1;
	}
	return 0;
}

int stack_is_empty (stack *ps)
{
	return *ps == NULL;
}

int stack_is_full (stack *ps)
{
	return 0;
}









