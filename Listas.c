#include "Listas.h"

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

void list_print (node* a_node, void pnt(t_elem_node))
{
    while (a_node != NULL){
        pnt(a_node->data);
        a_node = a_node->next;
    }
}


node** list_search(node** head, t_elem_node e)
{
    while((*head)!=NULL && (*head)->data==e)
    {
        *head=&(*head)->next;
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

node* node_insert_in_order(node** head, node* new_node)
{
    if (new_node!=NULL)
    {
        while((*head)!= NULL && (*head)->next->data < new_node->data)
        {
            head= &(*head)->next;
        }

        if((*head)->next->data < new_node->data)
        {
            node* aux = (*head)->next;
            (*head)->next=new_node;
            new_node->next=aux;
            node_free(&aux);
        }
    }

    return new_node;
}

node* delete_node(node** head, t_elem_node v)
{
    node** n = list_search(head,v);
    node* aux= *n;
    *n = aux->next;
    aux->next=NULL;

    return aux;

}

void delete_node2(node** head, t_elem_node v)
{
    node** n = list_search(head,v);
    node* aux= *n;
    *n = aux->next;
    aux->next=NULL;
    
    node_free(&aux);
}

int list_isorder(node* head)
{

    while(head->next!=NULL && head->data < head->next->data)
    {
        head=head->next;
    }
    
    if(head->next==NULL)
    {
        return 1;
    }
    return 0;
}

void list_delete_same_value(node** head)
{
    if((*head)==NULL)return;
    node* aux = *head;
    while (aux!=NULL && aux->next!=NULL)
    {
        if((*head)->data==aux->next->data)
        {
            delete_node2(&aux->next,aux->next->data);
        }else{
            aux=aux->next;
        }
        
    }

    list_delete_same_value(&(*head)->next);
}

node* list_min_value(node* head)
{
    node* min=head;

    while(head!=NULL)
    {
        if(min->data < head->data)
        {
            min= head;
        }
        head=head->next;
    }

    return min;

}

node* list_min_value(node* head)
{
    if (head == NULL) return NULL;

    node* min = head->next;
    

    while (head != NULL)
    {
        if (head->data < min->data)
        {
            min = head;
        }
        head = head->next;
    }

    return min;
}

//pepe