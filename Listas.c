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
        *head=(*head)->next;
    }
    
    return head;
}

node** node_find(node** head, t_elem_node e)
{
    while((*head)!=NULL && (*head)->data<e)
    {
        head=&(*head)->next;
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

void node_add_first2(node** head, node* new_node)
{
    if(new_node!=NULL)
    {
        new_node->next= *head;
        *head=new_node;
    }
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

void node_insert_in_order2(node** head, node* new_node)
{

    if (*head == NULL || new_node->data < (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    while((*head)!=NULL && (*head)->data < new_node->data)
    {
        head=&(*head)->next;
    }


        new_node->next=(*head)->next;
        (*head)->next=new_node;

}

node* node_insert_sort(node**h, node* new_node)
{
    if(new_node!=NULL)
    {
    node** aux = node_find(h, new_node->data);
    new_node->next = *aux;
    *aux = new_node;
    }
    
    return new_node;
}

node* node_remove_front(node** head)
{
    if(*head==NULL)return NULL;

    node* aux= (*head)->next;
    (*head)->next=NULL;
    node* remove= (*head);
    (*head)=aux;

    return remove;
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
//1.
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
//2
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
//3.
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
//4.
node* list_create_reverse(node* head)// Si quiero agregar nodos de una lista para crear otra no debo hacerlo directamente con la funcion de add_first o add_last ya que modifico la original
{
    node* reverse_list=NULL; //No hace falta inicilizarlo ya que despues se pisa la informacion con la funcion de add_first
    while(head!=NULL)
    {
        node* new_node=node_new(head->data);//Para evitar lo de arriba genero un nodo nuevo con el valor actual del nodo head y lo agrego a la lista nueva revertida
        node_add_first2(&reverse_list,new_node);
        head=head->next;
    }

    return reverse_list;
    
}

//5

void list_invert(node** head)
{
    node* prev = NULL;
    node* current = *head;

    while (current != NULL)
    {
        node* next = current->next; 
        current->next = prev;       
        prev = current;             
        current = next;             
    }
    head=&prev; 
}

//6.

int is_pair(t_elem_node value)
{
    if(value%2 == 0)
    {
        return 1;
    }

    return 0;
}
//7.
void list_create_pair_impair(node** head, node** pair, node** impair)
{
    while((*head)!=NULL)
    {
        if(is_pair((*head)->data))
        {
            node* new_pair=node_new((*head)->data);
            node_add_first2(pair,new_pair);
        }else{
            node* new_impair=node_new((*head)->data);
            node_add_first2(impair,new_impair);
        }
        (*head)=(*head)->next;
    }
}

//8.

node* list_create_fusion_sorted(node** list1, node** list2)
{
    if(*list1 == NULL && *list2==NULL) return NULL;

    node* result=NULL;
    while((*list1)!=NULL)
    {
        //node* temp=node_new(list1->data);
        node_insert_in_order2(&result,node_remove_front(list1));
        //(*list1)=(*list1)->next;
    }

    while ((*list2)!=NULL)
    {
        //node* temp=node_new(list2->data);
        node_insert_in_order2(&result, node_remove_front(list2));
        //(*list2)=(*list2)->next;
    }

    return result;
}

//9.
