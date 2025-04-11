#ifndef LISTAS_H_INCLUDED
#define MI_HEADER_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#define t_elem_node int
#define t_elem_node_t node*

typedef struct _node node;
typedef struct _node_t node_t;


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
void node_insert_in_order2(node** head, node* new_node);
node* list_create_fusion_sorted(node** list1, node** list2);
node* node_remove_front(node** head);
node* node_insert_sort(node**h, node* new_node);
node** node_find(node** head, t_elem_node e);
int list_get_major_value(node* head);
t_elem_node list_prom(node* head);
node_t* list_get_major_prom(node_t* head);

#endif