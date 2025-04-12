#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"
#include "stack_dynamic.h"
#include "queue_dynamic.h"
#include "time.h"


int main()
{
    node* head=NULL;
    node*n1=node_new(1);
    node*n2=node_new(3);
    node*n3=node_new(2);
    node*n4=node_new(6);
    node*n5=node_new(4);


    node_add_first2(&head,n1);
    node_add_first2(&head,n2);
    node_add_first2(&head,n3);
    node_add_first2(&head,n4);
    node_add_first2(&head,n5);

    //list_print(head,int_print);

    node* head1=NULL;
    node*n6=node_new(8);
    node*n7=node_new(4);
    node*n8=node_new(7);
    node*n9=node_new(12);
    node*n10=node_new(3);    

    node_add_first2(&head1,n6);
    node_add_first2(&head1,n7);
    node_add_first2(&head1,n8);
    node_add_first2(&head1,n9);
    node_add_first2(&head1,n10);

    //list_print(head1,int_print);

    node* fusion=list_create_fusion_sorted(&head,&head1);

    list_print(fusion,int_print);

//    srand(time(NULL));

//    stack* pilita=stack_new(5);
/*  
    push(pilita,5);
    push(pilita,4);
    push(pilita,3);
    push(pilita,2);
    push(pilita,1);
*/
/*
    stack_add_random(pilita,5);
    stack_print(pilita);
    int sum_elements=stack_sum_elements(pilita);
    printf("La suma de los elementos de pilita es: %d",sum_elements);
    stack* pilita_copy=stack_copy(pilita);
    puts("La copia de pilita quedo asi");
    stack_print(pilita_copy);
*/


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