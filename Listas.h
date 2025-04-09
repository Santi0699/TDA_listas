#ifndef LISTAS_H_INCLUDED
#define MI_HEADER_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#define t_elem_node int

typedef struct _node node;

node* node_new(t_elem_node data);
t_elem_node node_free(node** a_node);
void list_free(node** head);
void int_print (int e);
void list_print (node* a_node, void pnt(t_elem_node));
node** list_search(node** head, t_elem_node e);
node* node_add_first(node** head, node* new_node);
node* node_add_last(node** head, node* new_node);
node* node_insert_in_order(node** head, node* new_node);
node* delete_node(node** head, t_elem_node v);
void delete_node2(node** head, t_elem_node v);
int list_isorder(node* head);
void list_delete_same_value(node** head);
node* list_min_value(node* head);
void node_add_first2(node** head, node* new_node);
node* list_create_reverse(node* head);
void list_invert(node** head);
#endif