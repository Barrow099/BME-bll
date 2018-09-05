//
// Created by barrow099 on 2018.09.05..
//
#include <stdlib.h>
#include <stdio.h>
#include "bll.h"

bll_item* create_item(void* item) {
    bll_item* i = malloc(sizeof(bll_item));
    i->value = item;
    return i;
}

void delete_items(bll_list *list) {
    bll_item *next = list->first_item;
    while(next) {
        bll_item *tn = next->next_item;
        free(next);
        next = tn;
    }
}

bll_list* bll_create() {
    bll_list* ls = (bll_list*) malloc(sizeof(bll_list));
    return ls;
}

void bll_delete(bll_list* list) {
    delete_items(list);
    free(list);

}

void bll_add(bll_list *list, void * item) {
    bll_item *i = create_item(item);
    if(!list->first_item) {
        list->first_item = i;
        list->last_item = i;
        list->count++;
    }else {
        bll_item *lasti = list->last_item;
        lasti->next_item = i;
        list->last_item = i;
        list->count++;
    }
}

void * bll_get(bll_list *list, int index) {
    if(list->count <= index) {
        printf("DEBUG Index Out Of Range: length is %d but index is %d\n",list->count, index);
        return 0;
    }
    bll_item *item = list->first_item;
    for(int i = 0;i < index;i++) {
        item = item->next_item;
    }
    return item->value;

}

void bll_remove(bll_list * list, int index) {
    if(list->count <= index) {
        printf("DEBUG Index Out Of Range: length is %d but index is %d\n",list->count, index);
        return;
    }
    bll_item *prev = 0;
    bll_item *item = list->first_item;
    for(int i = 0;i < index;i++) {
        prev = item;
        item = item->next_item;
    }
    bll_item * next = item->next_item;

    if(prev) {
        prev->next_item = next;
    }else {
        list->first_item = next;
    }
    if(!next)
        list->last_item = prev;

    list->count--;
    free(item);

}

