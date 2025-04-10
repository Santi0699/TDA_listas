#include "queue_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

void queue_add_random(queue* q, int cant_elem)
{
    for(int i=0; i<cant_elem;i++)
    {
        t_queue_elem value= rand() %10;
        enqueue(q,value);
    }
}

//11.
void queue_print(queue* q)
{
    queue* aux=queue_new(queue_getsize(q));

    while (!queue_isempty(q))
    {
        printf("|%d|",peek(q));
        enqueue(aux,dequeue(q));
    }

    while (!queue_isempty(aux))
    {
        enqueue(q,dequeue(aux));
    }
    
    queue_free(aux);

}

//12.b
int queue_sum_elements(queue* q)
{
    if(queue_isempty(q))return 0;
    queue* aux=queue_new(queue_getsize(q));
    int sum=0;

    while (!queue_isempty(q))
    {
        sum=sum+peek(q);
        enqueue(aux,dequeue(q));
    }

    while (!queue_isempty(aux))
    {
        enqueue(q,dequeue(aux));
    }
    
    queue_free(aux);

    return sum;

}