#include "stack_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

void stack_add_random(stack* s, int cant_elem)
{
    
    for(int i=0; i<cant_elem;i++)
    {
        t_elem_stack value= rand() %10;
        push(s,value);
    }
}
//10.a
void stack_print(stack* s)
{
    if(stack_isempty(s)) return;

    stack* aux=stack_new(stack_getsize(s));

    while(!stack_isempty(s))
    {
        push(aux,pop(s));
        printf("|%d|\n",top(aux));
    }

    while(!stack_isempty(aux))
    {   
        push(s,pop(aux));
    }

    stack_free(aux);

}
//b.

void stack_print_recursive(stack* s)
{
    //completar
}

//12.a
int stack_sum_elements(stack* s)
{
    if(stack_isempty(s)) return 0;

    stack* aux=stack_new(stack_getsize(s));
    int sum=0;

    while(!stack_isempty(s))
    {
        push(aux,pop(s));
        sum=sum+top(aux);
    }

    while(!stack_isempty(aux))
    {   
        push(s,pop(aux));
    }

    stack_free(aux);

    return sum;
}
//14.
stack* stack_copy(stack*s)
{
    stack* aux= stack_new(stack_getsize(s));
    stack* result=stack_new(stack_getsize(s));
    while(!stack_isempty(s))
    {
        push(aux,pop(s));
    }

    while(!stack_isempty(aux))
    {
        t_elem_stack value=top(aux);
        push(result,value);
        push(s,pop(aux));
    }

    stack_free(aux);

    return result;
}
