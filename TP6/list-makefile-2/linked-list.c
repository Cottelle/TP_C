#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node {
    int value;
    struct ll_node *next;
} ll_node;

struct ll_list {
    struct ll_node *first;
};


ll_list * ll_create(void) {
    ll_list * list = malloc(sizeof(ll_list));
    if (list == NULL){
        return NULL;
    }
    list->first = NULL;
    return list;
}

void ll_append(ll_list *list, int value) {
    ll_node * new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = NULL;
    new_element->value = value;

    if(list->first == NULL) {
        list->first = new_element;
        return;
    }

    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
    }
    it->next = new_element;
}

int ll_get(const ll_list *list, unsigned int value_idx) {

    ll_node *it = list->first;

    for(unsigned int i = 0; i < value_idx; i++) {
        it = it->next;
    }
    return it->value;
}

void ll_free(ll_list *list) {
    return;
}

size_t ll_size(ll_list *list){
        size_t count=1;
        if (list==NULL){
            return 0;
        }
        else{
        ll_node *node = list->first;
        while(node->next !=NULL){
            node=node->next;
            count=count+1;
        }
        return count;
        }
 }

 void ll_prepend(ll_list *list, int value){

     ll_node *new = malloc(sizeof(ll_node));
     if (new==NULL){
         free(new);
         exit(1);
     }
     new->value=value;
     new->next= list->first;
     list->first = new; 
          
 }

 int ll_first(ll_list *list){
     if (list==NULL){
         exit(1);
     }
     return list->first->value;

 }


 int ll_last(ll_list *list){
     if (list==NULL){
         exit(1);
     }
     ll_node *acc= list->first;
     while(acc->next !=NULL){
         acc=acc->next;
     }
     return acc->value;


 }
 void ll_pop_last(ll_list*list){
     if (list==NULL){
         exit(1);
     }
     ll_node *acc= list->first;
     if (acc->next==NULL){
         list=NULL;
     }
     while(acc->next->next !=NULL){
         acc=acc->next;
     }
     acc->next=NULL;

 }
 void ll_pop_first(ll_list*list){
    if (list==NULL){
            exit(1);
        }
        if (list->first->next==NULL){
            list==NULL;
        }  
        list->first=list->first->next; 

 }

 /*void ll_free(ll_list *list){           // a revoir
    if(list!=NULL){
        list->first=(list->first)->next;
        ll_free(list);
        free(list);
    }

 }*/

 void ll_insert(ll_list*list, int value, int idx){
     if(ll_size(list)  < idx){
         exit(1);
     }
     ll_node *acc = list->first;
     ll_node * new= malloc(sizeof(ll_node));
     if (new==NULL){
         free(new);
         exit(1);
     }
     new->value=value;
     for(int i=0;i<idx-1;i++){
         acc=acc->next;
     }
     ll_node *apres = acc->next;
     acc->next= new;
    new->next=apres;
 }
 void ll_remove(ll_list*list, int idx){
     if(ll_size(list)  < idx){
         exit(1);
     }
     ll_node *acc = list->first;
     for(int i=0;i<idx-1;i++){
         acc=acc->next;
     }
     acc->next=acc->next->next;


 }
