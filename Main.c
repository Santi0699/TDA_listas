#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"
#include "stack_dynamic.h"
#include "queue_dynamic.h"
#include "time.h"


int main()
{
    //list_print (head, int_print);
    srand(time(NULL));

    stack* pilita=stack_new(5);
/*  
    push(pilita,5);
    push(pilita,4);
    push(pilita,3);
    push(pilita,2);
    push(pilita,1);
*/

    stack_add_random(pilita,5);
    stack_print(pilita);
    int sum_elements=stack_sum_elements(pilita);
    printf("La suma de los elementos de pilita es: %d",sum_elements);
    stack* pilita_copy=stack_copy(pilita);
    puts("La copia de pilita quedo asi");
    stack_print(pilita_copy);



/*
    queue* filita=queue_new(5);
    queue_add_random(filita,5);
    queue_print(filita);
    int sum_elem=queue_sum_elements(filita);
    puts(" ");
    printf("La suma de los elementos de pilita es: %d",sum_elem);
    puts(" ");
    queue_invert(filita);
    queue_print(filita);
*/
    return 0;
}