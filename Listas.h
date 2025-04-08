#ifndef LISTAS_H_INCLUDED
#define MI_HEADER_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#define t_elem_node int

typedef struct _node
{
    t_elem_node data;
    struct _node* next;    
    
}node;

node* node_new(t_elem_node data)
{
    node* r=(node*)malloc(sizeof(node));
    if(r!=NULL)
    {
        r->data=data;
        r->next=NULL;
    }

    return r;
}

t_elem_node node_free(node** a_node)
{
    node* aux= *a_node;
    t_elem_node data= 0;
    if(a_node!=NULL)
    {
        data= aux->data;
        *a_node = aux->next;
        free(aux);
    }
    return data;
}

void list_free(node** head)
{
    while(*head!=NULL)
    {
        t_elem_node e = node_free(head);
        // Aca deberia de ir una funcion que elimine el lo que contiene e si es que es otro tipo de dato distinto de int. Ej: fraccion o que contenga la direccion de memoria de un vector
    }
}

// imprimir un elemento entero
void int_print (int e){
    printf("%d ", e);
}

void list_print (node* a_node, void pnt(t_elem_node)){
    while (a_node != NULL){
        pnt(a_node->data);
        a_node = a_node->next;
    }
}


node** list_search(node** head, t_elem_node e)
{
    while((*head)!=NULL && (*head)->data==e)
    {
        *head=(*head)->next;
    }
    
    return head;
}

node* node_add_first(node** head, node* new_node)
{
    if(new_node!=NULL)
    {
        new_node->next= *head;
        *head=new_node;
    }

    return new_node;
}

node* node_add_last(node** head, node* new_node)
{
    if(node_new!=NULL)
    {
        while((*head)!=NULL)
        {
            *head= (*head)->next;
        }

        (*head)->next=new_node;
    }
    return new_node;
}



#endif