//
// Created by Alex Brodsky on 2023-09-20.
//

#ifndef LINKED_LIST__H
#define LINKED_LIST__H

typedef void * linked_list_t;
typedef void * ll_iterator_t;
typedef void * ll_node;

typedef struct ll_node {
    struct ll_node *prev;
    struct ll_node *next;
    void *item;
    linked_list_t *connectTo;
} ll_node_t;

typedef struct linked_list {
    ll_node_t *head;
    ll_node_t *tail;
} linked_list;

typedef struct ll_iterator{
    ll_node_t *next;
    linked_list *list;
    ll_node_t *prev;
} ll_iterator;


extern linked_list_t ll_new();
extern void ll_destroy(linked_list_t list);
extern int ll_add_front(linked_list_t list, void *item);
extern int ll_add_back(linked_list_t list, void *item);
extern void * ll_get_front(linked_list_t list);
extern void * ll_get_back(linked_list_t list);

extern void * ll_remove_front(linked_list_t list);
extern void * ll_remove_back(linked_list_t list);

extern int ll_size(linked_list_t list);
extern int ll_is_empty(linked_list_t list);

/* To be added */
extern ll_iterator_t  ll_iterator_new(linked_list_t list);
extern void ll_iterator_destroy(ll_iterator_t iter);
extern void *ll_next(ll_iterator_t iter);
extern int ll_has_next(ll_iterator_t iter);
extern int ll_add(ll_iterator_t iter, void *item);
extern void * ll_set(ll_iterator_t iter, void *item);
extern void * ll_remove(ll_iterator_t iter);



#endif //LINKED_LIST__H
